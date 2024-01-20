#include <iostream>
#include <string>
#include <vector>

int main(){
    int K;
    std::vector<int> currentNumbers; //currentNumbers records the numbers remainig after each operation. 

    std::cin >> K;
    for (int i = 0;i < K;i++){
        int temp;
        std::cin >> temp;
        if (temp == 0){ // If 0, remove last element of the list. 
            currentNumbers.pop_back();
        }else{ //If normal number, then add that number to the back of the list
            currentNumbers.push_back(temp);
        }
        // std::cout << std::endl;
        // for(int i = 0;i<currentNumbers.size();i++){
        //     std::cout << currentNumbers[i] << " ";
        // }

    }

    int sum = 0;
    for(int i = 0;i<currentNumbers.size();i++){
        sum += currentNumbers[i];
    }
    
    std::cout << sum << std::endl;


}
