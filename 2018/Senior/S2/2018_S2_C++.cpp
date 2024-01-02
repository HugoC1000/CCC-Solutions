#include <algorithm>
#include <iostream>
#include <vector>

int N;

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> grid) {
  std::vector<std::vector<int>> newGrid(N, std::vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      newGrid[i][j] = grid[N - j - 1][i];
    }
  }
  return newGrid;
}

bool check(std::vector<std::vector<int>> grid) {
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (grid[i][j] < grid[i][j - 1]) {
        return false;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (grid[j][i] < grid[j - 1][i]) {
        return false;
      }
    }
  }

  return true;
}

int main() {

  std::cin >> N;

  std::vector<std::vector<int>> grid(N, std::vector<int>(N));
//Take in input
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> grid[i][j];
    }
  }
  //If the grid is not correct, rotate it. 
  for (int i = 0; i < 8; i++) {
    if (check(grid)) {
      break;
    }
    grid = rotate(grid);
  }
  // print the answer
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << grid[i][j];
      if (j < N - 1)  std::cout << " ";
    }
    std::cout << std::endl;
  
}
  return 0;
}
