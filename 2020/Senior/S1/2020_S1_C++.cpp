#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
int main(){
  int N;
  std::cin >> N;
  std::map<double,double> map; //Create a map to create key value pairs of time to distance. 
  std::set<double> seta; //Create a set to store and auto sort the keys.
  for (int i = 0;i<N;i++){ //Input values into map and set
    double temp1,temp2;
    std::cin >> temp1 >>temp2;
    map[temp1] = temp2;
    seta.insert(temp1);
  }
  double speed = 0;

  std::vector<double> setVector(seta.begin(), seta.end());  //Convert set into a vector
  
  for(int i =0;i<N-1;i++){ //Calculate the difference in time and position between each consecutive time stamps
    double diffInTime  = setVector[i+1]-setVector[i];
    double diffInPos = std::abs(map[setVector[i+1]]-map[setVector[i]]);
    double newSpeed = diffInPos/diffInTime;
    if (newSpeed > speed){ //Store the highest speed recorded so far. 
      speed = newSpeed;
    }
  }
  std::cout << speed; //Output
}
