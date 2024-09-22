#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <cstring>

using namespace std;
#define ll long long

ll N,M;

const int MAX = 108;

ll dist[MAX][MAX];
// vector<vector<bool> > visited(MAX, vector<bool>(MAX, false));
bool visited[MAX][MAX];
string grid[MAX][MAX];

pair<int,int> start;
vector<pair<int,int> > cameras;
vector<pair<int,int> > empty_cells; //Stores ycord, xcord of empty cells. 

void handleCameras(){
    for (pair<int,int> camera : cameras){
         //Up
        for (int i = camera.first; i >= 1; i--){
            if (grid[i][camera.second] == "Wall")
                break;
            if (grid[i][camera.second] == "Empty"|| grid[i][camera.second] == "Start"){
                dist[i][camera.second] = -10;
                visited[i][camera.second] = true;
            }
        }

        //Down
        for (int i = camera.first; i <= N; i++){
            if (grid[i][camera.second] == "Wall")
                break;
            if (grid[i][camera.second] == "Empty" || grid[i][camera.second] == "Start"){
                dist[i][camera.second] = -10;
                visited[i][camera.second] = true;
            }
        }

        //Left
        for (int i = camera.second; i >= 1; i--){
            if (grid[camera.first][i] == "Wall")
                break;
            if (grid[camera.first][i] == "Empty"|| grid[camera.first][i] ==  "Start"){
                dist[camera.first][i] = -10;
                visited[camera.first][i] = true;
            }
        }

        //Right
        for (int i = camera.second; i <= M; i++){
            if (grid[camera.first][i] == "Wall")
                break;
            if (grid[camera.first][i] == "Empty" || grid[camera.first][i] == "Start"){
                dist[camera.first][i] = -10;
                visited[camera.first][i] = true;
            }
        }
    }   
}

void bfs(pair<int,int> startCellCords){
    queue<pair<int,int> > q;
    q.push(startCellCords);

    while (!q.empty()){
        pair<int,int> currentCell;
        currentCell = q.front();
        q.pop();

        int currCellY = currentCell.first;
        int currCellX = currentCell.second;

        if(visited[currCellY][currCellX]){
            continue;
        }

        if(grid[currCellY][currCellX] == "Wall" || grid[currCellY][currCellX] == "Camera"){
            continue;
        }

        if(grid[currCellY][currCellX] == "Start" || grid[currCellY][currCellX] == "Empty"){
            //Right
            if(currCellX < M && dist[currCellY][currCellX+1] > dist[currCellY][currCellX]+1){
                dist[currCellY][currCellX+1] = dist[currCellY][currCellX] + 1;
                q.push(make_pair(currCellY, currCellX + 1));
            }
            //Left
            if(currCellX > 1  && dist[currCellY][currCellX-1] > dist[currCellY][currCellX]+1){
                dist[currCellY][currCellX-1] = dist[currCellY][currCellX] + 1;
                q.push(make_pair(currCellY, currCellX - 1));
            }
            //Up
            if(currCellY > 1 && dist[currCellY-1][currCellX] > dist[currCellY][currCellX]+1){
                dist[currCellY-1][currCellX] = dist[currCellY][currCellX] + 1;
                q.push(make_pair(currCellY-1, currCellX));
            }
            //Down
            if(currCellY < N && dist[currCellY + 1][currCellX] > dist[currCellY][currCellX]+1){
                dist[currCellY + 1][currCellX] = dist[currCellY][currCellX] + 1;
                q.push(make_pair(currCellY + 1, currCellX));
            }
        //Left conveyor
        }else if (grid[currCellY][currCellX] == "Conveyor L"){
            if (dist[currCellY][currCellX - 1] > dist[currCellY][currCellX] && currCellX > 1 && grid[currCellY][currCellX - 1] != "Wall"){
                dist[currCellY][currCellX - 1] = dist[currCellY][currCellX];
                q.push(make_pair(currCellY, currCellX - 1));
            }
        }
        //Right conveyor
        else if (grid[currCellY][currCellX] == "Conveyor R"){
            if (dist[currCellY][currCellX + 1] > dist[currCellY][currCellX] && currCellX < M && grid[currCellY][currCellX + 1] != "Wall"){
                dist[currCellY][currCellX + 1] = dist[currCellY][currCellX];
                q.push(make_pair(currCellY, currCellX + 1));
            }
        }
        //Up conveyor
        else if (grid[currCellY][currCellX] == "Conveyor U"){
            if (dist[currCellY - 1][currCellX] > dist[currCellY][currCellX] && currCellY > 1 && grid[currCellY - 1][currCellX] != "Wall"){
                dist[currCellY - 1][currCellX] = dist[currCellY][currCellX];
                q.push(make_pair(currCellY -1, currCellX ));
            }
        }
        //Down conveyor
        else if (grid[currCellY][currCellX] == "Conveyor D"){
            if (dist[currCellY + 1][currCellX] > dist[currCellY][currCellX] && currCellY < N && grid[currCellY + 1][currCellX] != "Wall"){
                dist[currCellY + 1][currCellX] = dist[currCellY][currCellX];
                q.push(make_pair(currCellY + 1, currCellX ));
            }
        }

    }


}


int main(){
    cin >> N >> M;


    pair<int, int> startCell; //xCord,yCord

    vector<int> stepsToReachEachEmptyCell;

    map <pair<int, int>,int > indexToEmptyCell; //xCord, yCord : index

    vector<pair<int, int> > cameraCells;

    //cout << "Take in input" << endl;

    //Take in input
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            char temp;
            cin >> temp;
            if (temp == 'S'){
                start = make_pair(i,j);
                grid[i][j] = "Start";
            }else if (temp == '.'){
                empty_cells.push_back(make_pair(i,j));
                grid[i][j] = "Empty";
            }else if (temp  == 'C'){
                cameras.push_back(make_pair(i, j));
                grid[i][j] = "Camera";
            }else if(temp == 'L'){
                grid[i][j] = "Conveyor L";
            }else if(temp == 'R'){
                grid[i][j] = "Conveyor R";
            }else if(temp == 'U'){
                grid[i][j] = "Conveyor U";
            }else if (temp == 'D'){
                grid[i][j] = "Conveyor D";
            }else if(temp == 'W'){
                grid[i][j] = "Wall";
            }
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            dist[i][j] = 1e18;
        }
    }
    memset(visited, false, sizeof visited);


    handleCameras();

    dist[start.first][start.second] = 0;

    bfs(start);

    for (auto x : empty_cells)
    {
        if (visited[x.first][x.second] || dist[x.first][x.second] >= 1e18)
            cout << -1 << endl;
        else
            cout << dist[x.first][x.second] << endl;
    }


    //The following code writes the output to a text file. This helps when comparing differences with the expected output
    // std::string filename = "output.txt";

    // // Open a file in write mode
    // std::ofstream outfile(filename);

    // if (outfile.is_open()) {
    //     std::cout << "File opened successfully!" << std::endl;

    //     // Write each number to a new line in the file

    //     for (auto x : empty_cells){
    //         if (visited[x.first][x.second] || dist[x.first][x.second] >= 1e18)
    //             outfile << -1 << std::endl;
    //         else
    //             outfile << dist[x.first][x.second] << endl;
    //     }
  
    //     outfile.close(); // Close the file
    //     std::cout << "File closed successfully!" << std::endl;
    // } else {
    //     std::cerr << "Unable to open file: " << filename << std::endl;
    // }





}
