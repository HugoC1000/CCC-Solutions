2021S1
#include <iostream>


int main(){
  int N;
  std::cin>>N;
  int heights[N+1];
  for (int i = 0;i<N+1;i++){
    std::cin>> heights[i];
  }
  int width[N];
  for (int i = 0; i< N;i++){
    std::cin>> width[i];
  }

  double area = 0;//what data type is proper?

  for (int i = 1; i< N+1;i++){
  //  std::cout << i;
    int leftHeight = heights[i-1];
 //   std::cout << "Left Height: " << leftHeight << std::endl;
    int rightHeight = heights[i];
  //  std::cout << "Right Height: " << rightHeight << std::endl;
    int widthOfBoard = width[i-1];
 //   std::cout << "Width: " << widthOfBoard << std::endl;
    double tempArea = widthOfBoard*(leftHeight+rightHeight)/2.0;
    area += tempArea;
  }
  std::cout <<std::fixed<< area;


}
