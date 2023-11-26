#include <iostream>
#include <vector>
#include <algorithm>



int main(){
  double N,M,K;
  std::cin >> N >> M >> K;

  std::vector<int> vec (N, 0);

  vec[0] = 1;
  K-=N;
  //subtask 1 generate exactly N good samples

  //the minimum good sample of a piece N is N, each single note is a good sample
  //we want K-N good samples to make it K
  //every time we add a new distinct number for the first time, it creates the index-1 good samples
  //everytime we add an already exist number,  it creates index1-index2-1 good samples

    //collect the input

    //create a vector with N size, all initialized as 0

    //set the first element as 1

    //let k = k-n, we just neet to make k-n good samples to make it K

    //use a for loop bounded by M

    //in the for loop, only add new distinct number to the piece, i.e vec[i]=i+1 when K-i>=0 and i<N, also update K as -i
    //if we run out of distinct notes, terminate the loop
  
  for(int i =1;i<M;i++){
    if(K-i>=0 && i<N){
      vec[i]=i+1;
        K-=i;
    }else{
      break;
    }
  }

  


  //subtask 2: create K-N samples
  //use find() to find the position that has 0
  int checkposition;
  auto it = std::find(vec.begin(), vec.end(), 0);
  if(it != vec.end()){
    checkposition = it-vec.begin();
  }else{
    checkposition = N;
  }
  
  //for loop i starts from checkposition, i bounded by N
    //if K is greater than 0 (fill in new number with j notes back)
      //for j starts at M, greater than 0, j--
        //if K-j+1 greater than 0
          //vector i = vector i - j
          //k -= j-1
          //break
    //else (when k <= 0) copy previous value to the current position
      //vector i = vector i-1
  for (int i = checkposition;i<N;i++){
    if (K > 0){
      for (int j= M;j>0;j--){
        if (K-j+1 >=0){
          vec[i]=vec[i-j];
          K -= j-1;
          break;
        }
      }
      
    }else{
      vec[i]=vec[i-1];
    }
  }
  //if k becomes 0, meaning we successfully get K good samples. so we use a for loop to printout vector i, i start from N
  //else, print -1
 // std::cout<<'K'<<K<<std::endl;
  if (K == 0){
    for (int i =0;i<N;i++){
      std::cout << vec[i]<<' ';
    }
  }else{
    std::cout << -1;
  }

  
  return 0;
}
