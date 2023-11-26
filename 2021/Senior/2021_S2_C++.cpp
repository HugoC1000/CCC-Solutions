#include <iostream>
#include <vector>
int main(){
  int M,N,K;
  std::cin>> M;
  std::cin >>N;
  std::cin >>K;
  std::vector<int> row(M+1,0);
  std::vector<int> col(N+1,0);

  int goldCount = 0;
  //input operation
  for (int i =0; i< K;i++){
    char firstHalf;
    std::cin >> firstHalf;
    int secondHalf;
    std::cin >> secondHalf;

    if (firstHalf == 'R'){
        row[secondHalf] +=1;
    }else{
        col[secondHalf]+= 1;
    }
  }

  for (int i =1; i<= M;i++){
    for (int j = 1;j<=N;j++){
      if((row[i] + col[j])%2!= 0){
        goldCount++;
    }
  }

  }
  std::cout << goldCount;
}
