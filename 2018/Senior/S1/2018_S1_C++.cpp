#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;

int main() {
  //Takes in input and initilizes array. 
  int numofinp = 0;
  cin >> numofinp;
  vector <int> arr = {};
  vector <double> arrofdist = {};
  //Puts values in the array. 
  for (int a = 0;a<numofinp; a++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
    arrofdist.push_back(0.0);
  }
  //Sorts the array
  sort(arr.begin(),arr.end());
  //Calculates the difference between two towns and divides it by 2 to find the maximum length for the towns. It then stores it in arrofdist. 
  for (int b = 1;b<numofinp;b++){
    double diff = arr[b]-arr[b-1];
    arrofdist[b-1] += diff/2;
    arrofdist[b] += diff/2;
  }
  //The next two lines gets rid of the first and last elements as they will be infinite and definitely not be the solution. 
  arrofdist.erase(arrofdist.begin()+numofinp-1);
  arrofdist.erase(arrofdist.begin());
  //The next two line sorts the array, and takes the first element to get the smallest value. It then outputs it with the decimal place. 
  sort(arrofdist.begin(),arrofdist.end());
  cout << fixed << setprecision(1) << arrofdist[0];
}
