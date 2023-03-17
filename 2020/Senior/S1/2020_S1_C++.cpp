#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<iomanip>
using std::cin;
using std::cout;
using namespace std;
int main() {
  
  int numofinp;
  cin >> numofinp;
    vector<pair<int,int>>arr(numofinp);
    for(int i = 0;i <numofinp;i++){
      cin >> arr[i].first >> arr[i].second;
    }

  sort(arr.begin(),arr.end());
  float max = 0;
  for(int b = numofinp - 1; b >= 0;b--){
    if(std::fabs(arr[b].second-arr[b-1].second)/(arr[b].first-arr[b-1].first) > max){
      max = std::fabs((arr[b].second-arr[b-1].second))/(arr[b].first-arr[b-1].first);
      
    }
  }
  
  cout << fixed << setprecision(1.0) <<max;
}
