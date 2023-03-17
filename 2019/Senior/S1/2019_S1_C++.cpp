#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
  int arr[4] = {1,2,3,4};
  string seq ;
  cin >> seq;
  for(char c:seq){
    if(c == 'H'){
      swap(arr[0],arr[2]);
      swap(arr[1],arr[3]);
    }else{
      swap(arr[1],arr[0]);
      swap(arr[3],arr[2]);
    }
  }
  cout << arr[0] << " " << arr[1] << "\n";
  cout << arr[2] << " " << arr[3];
}
