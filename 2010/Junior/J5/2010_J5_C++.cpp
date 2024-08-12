#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::find
#include <utility>   // for std::pair

using namespace std;

int main() {
    int startX, startY;
    int targetX, targetY;

    cin >> startX >> startY >> targetX >> targetY;

    queue<pair<int, pair<int, int> > > q;
    int minMove = -1;  

    q.push(make_pair(0, make_pair(startX, startY)));

    vector<pair<int, int> > visited;

    while (!q.empty()) {
        int currX = q.front().second.first;
        int currY = q.front().second.second;
        int minSoFar = q.front().first;

        // Check if the current node is visited
        if (std::find(visited.begin(), visited.end(), make_pair(currX, currY)) != visited.end()) {
            q.pop();
            continue;
        }

        // Mark the current node as visited
        visited.push_back(make_pair(currX, currY));

        // Check if the target is reached
        if (currX == targetX && currY == targetY) {
            minMove = minSoFar;
            break;  //First match found in BFS is the shortest path. 
        }

        q.pop();

        // Possible positions the knight can go to. Check if in perimeter. 
        if (currX + 1 <= 8 && currY + 2 <= 8) {
            q.push(make_pair(minSoFar + 1, make_pair(currX + 1, currY + 2)));
        }
        if (currX + 2 <= 8 && currY + 1 <= 8) {
            q.push(make_pair(minSoFar + 1, make_pair(currX + 2, currY + 1)));
        }
        if (currX + 2 <= 8 && currY - 1 >= 1) {
            q.push(make_pair(minSoFar + 1, make_pair(currX + 2, currY - 1)));
        }
        if (currX + 1 <= 8 && currY - 2 >= 1) {
            q.push(make_pair(minSoFar + 1, make_pair(currX + 1, currY - 2)));
        }
        if (currX - 1 >= 1 && currY - 2 >= 1) {
            q.push(make_pair(minSoFar + 1, make_pair(currX - 1, currY - 2)));
        }
        if (currX - 2 >= 1 && currY - 1 >= 1) {
            q.push(make_pair(minSoFar + 1, make_pair(currX - 2, currY - 1)));
        }
        if (currX - 2 >= 1 && currY + 1 <= 8) {
            q.push(make_pair(minSoFar + 1, make_pair(currX - 2, currY + 1)));
        }
        if (currX - 1 >= 1 && currY + 2 <= 8) {
            q.push(make_pair(minSoFar + 1, make_pair(currX - 1, currY + 2)));
        }
    }

    cout << minMove << endl;
    return 0;
}
