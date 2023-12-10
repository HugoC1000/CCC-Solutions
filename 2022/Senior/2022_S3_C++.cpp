#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  //what is the mini amount of good samples we are guaranteed to have?
  //1,2 {1}{2} two
  //1,2,3 {1}{2}{3}


  //adding a distinct note to the piece will generate index-1 extra good samples

  //adding a repetitive note will generate curIndex-firstIndex-1 amount of good samples
  double N,M,K;
  std::cin >> N >> M>> K;

  std::vector<int> seq(N,0);

  seq[0]=1;

  //use a for loop for M-1 iterations 
  //if k-i>=0 and i<N
    //add i+1 to sequence on this i position
    //decrement i from k
  //otherwise
    //break the loop (we exaust k or i goes over N)
  K -= N;
  for (int i = 1;i<M;i++){
    if (K-i>=0 && i<N){
      seq[i]= i+1;
      K-=i;
    }else{
      break;
    }
  }

  
  //use a int checkpoint
  //get a iterator to find the start of sequence and end of sequence where start from 0
  //auto it = std::find(seq.begin(), seq.end(), 0)
   //if the iterator not equals to sequence end
    //checkpoint starts from it-seqence begin
  //otherwise  checkpoint be N
  int checkpoint;
  auto it = std::find(seq.begin(), seq.end(), 0);
  if (it != seq.end()){
    checkpoint = it - seq.begin();
  }else{
    checkpoint = N;
  }

  //if we still have K left
    //for j start M goes to 0, backwards
      //if condition, refer to "K-1>=0", but with j,
        //sequence i be sequence i-j
        //K-=j-1;
        //break
  //otherwise, sequence i be sequencei-1
  //for i start from checkpint , up to N, 
  for (int i = checkpoint;i<N;i++){
    if (K > 0){
      for (int j = M; j>0;j--){
        if (K-j+1>=0){
          seq[i] = seq[i-j];
          K-= j-1;
          break;
        }
      }
    }else{
       seq[i] = seq[i-1];
    }
  }

  //std::cout<<K<<std::endl;
  if( K == 0){
    for (int i = 0; i< N;i++){
      std::cout << seq[i] << " ";
    }
  }else{
    std::cout << -1;
  }

  //if k become 0, print all notes in the sequence
  //otherwise print -1

  
  return 0;
}
