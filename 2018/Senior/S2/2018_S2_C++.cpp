#include <iostream>
#include <vector>

using namespace std;

//The following function rotates the square/grid 90 degrees. 

vector <vector<int> > rotate(vector <vector<int> > grid,int sizeofSqr){
  vector <vector<int> > newGrid;
  for(int a = 0;a<sizeofSqr;a++){
    vector < int > tempvec;
    for(int b = 0;b<sizeofSqr;b++){
      tempvec.push_back(0);
    }
    newGrid.push_back(tempvec);
  }
  for(int a = 0;a<sizeofSqr;a++){
    for(int b = 0;b<sizeofSqr;b++){
      newGrid[a][b] = grid[sizeofSqr-b-1][a];
}
  }
  
  return newGrid;
}


/* The following function checks if the grid inputted is correct. For it to be correct, it needs to satisfy 2 conditions:
1. All numbers in a row must be ascending from left to right.
2. All numbers in a column must be increasing from up to down. */

int check(vector <vector<int> > grid,int sizeofSqr){
  int conditionsMet = 1;
  //test if numbers are ascending in a row
  for(int a = 0;a<sizeofSqr;a++){
    int previous = -1;
    for(int b = 0;b < sizeofSqr;b++){
      if (grid[a][b] <= previous){
        conditionsMet = 0;
        break;
      }
      previous = grid[a][b];
    }
  }
  //test if numbers are ascending down a column.  
  if (conditionsMet == 1){
    for(int a = 0;a<sizeofSqr;a++){
      int previous = -1;
      for(int b = 0;b < sizeofSqr;b++){
        if (grid[b][a] <= previous){
          conditionsMet = 0;
          break;
        }
        previous = grid[b][a];
      }
    }
  }
  return conditionsMet;
}
    

int main() {
//Takes in input and stores it in a 2d vector. 
  int sizeofSqr;
  cin >> sizeofSqr;
  vector <vector<int> > grid;
  for(int a = 0;a<sizeofSqr;a++){
    vector < int > tempvec;
    for (int b = 0;b < sizeofSqr;b++){
      int temp;
      cin>> temp;
      tempvec.push_back(temp);
    }
    grid.push_back(tempvec);
  }


/*The following code does the following. 
It checks if the grid is correct by calling the check() function. If it is, then it outputs it. If it dosen't, it rotates it and
checks again. it does this 4 times, as the maximum number of rotations needed is 4 and there is always a solution. */

  for(int t = 0;t<4;t++){
    if(check(grid,sizeofSqr) == 0){
      grid = rotate(grid,sizeofSqr);
    }else{
      for(int a = 0;a<sizeofSqr;a++){
        for(int b = 0;b < sizeofSqr;b++){
          if (b == sizeofSqr-1){
            cout<< grid[a][b];
          }else{
            cout << grid[a][b] << " ";
          } 
        }
        cout << "\n";
      }
      break;
    }
}
}
