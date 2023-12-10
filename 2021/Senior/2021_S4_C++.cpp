#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>

int main(){
  int N,W,D;
  std::cin >> N >>W>>D;
  std::vector<int> walkways[N+1];//a vector to hold walkways
  for (int i = 0;i<W;i++){
    int a,b;
    std::cin >>a >>b;
    walkways[b].push_back(a);
  }

  std::queue<int> list;
  std::vector<bool> visitedList(N+1, false);
  std::vector<int> walkingTimes(N+1, 100000000);
  walkingTimes[N] = 0;
  visitedList[N] = 1;
  list.push(N);
  
  while(!list.empty()){
    int current = list.front();
    list.pop();
    for(const int connecting : walkways[current]){
      if(!visitedList[connecting]){
        walkingTimes[connecting] = walkingTimes[current]+1;
        list.push(connecting);
      }
      visitedList[connecting]=true;
    }
  }

 //a vector for subway path, size N+1
  std::vector<int> subwayPath(N+1);
  std::multiset<int> cumulativeTime;
  //todo: subway path 0 = 0
  subwayPath[0]=0;

  //int firstStop;
  //int nextStop;
 // std::cin >> firstStop;
  for(int i = 1;i < N+1;i++){
    std::cin >> subwayPath[i];
    cumulativeTime.insert(i-1+walkingTimes[subwayPath[i]]);
  }
 

  int temp, value;
  for(int day = 0; day<D; day++){
    int change1, change2;
    std::cin>>change1>>change2;

    value = change1-1+walkingTimes[subwayPath[change1]];
    cumulativeTime.erase(cumulativeTime.find(value));

    value = change2-1+walkingTimes[subwayPath[change2]];
    cumulativeTime.erase(cumulativeTime.find(value));

    //swap the stattions on subwaypath, i.e. change1 <> change2
    //temp = path [1]
    temp = subwayPath[change1];
    subwayPath[change1] = subwayPath[change2];
    subwayPath[change2] = temp;
    

    //add new times in cumulative time, refer to line 48, add change 1 correspondingly, and add for change 2

    cumulativeTime.insert(change1-1+walkingTimes[subwayPath[change1]]);
    cumulativeTime.insert(change2-1+walkingTimes[subwayPath[change2]]);

    //print the head of the cumulative time
    std::cout << *cumulativeTime.begin() << std::endl;

    // for (std::multiset<int>::iterator it=cumulativeTime.begin();it!=cumulativeTime.end(); ++it){
    // std::cout << ' ' << *it;
    // }
  }
  

  return 0;
}
