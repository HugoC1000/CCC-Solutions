#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int questionType,N;
    int totalCount = 0;
    vector<int> dmojistanBikers,peglandBikers;
    //Take in Inputs
    cin >> questionType >> N;
  
    for (int i = 0; i < N; i++){
        int temp;
        cin>> temp;
        dmojistanBikers.push_back(temp);
    }
    for (int i = 0; i < N; i++){
        int temp;
        cin>> temp;
        peglandBikers.push_back(temp);
    }

    //Sort arrays to arrange from slowest biker to fastest
    sort(dmojistanBikers.begin(),dmojistanBikers.end());
    sort(peglandBikers.begin(),peglandBikers.end());

    if(questionType == 1){  
        //We are trying to find the minimum total speed. 
        //To do this, we pair the biggest numbers together. 
        //Since we are extracting the maximum, this means that more value is lost(As the second bigger number is lost) 
        //For example, if the bikers are [1,2,3] and [2,4,6]. We compute max(6,3)+max(4,2)+(2,1) = 12, instead of max(6,1)+max(4,2)+max(3,2) which is less. 
        for(int i = 0; i <N;i++){
            int bikerSpeed = max(dmojistanBikers[i],peglandBikers[i]);
            totalCount += bikerSpeed;
        }
        cout << totalCount << endl;
    }else{
        for(int i = 0; i <N;i++){
            //We are trying to find the maximum total speed. 
            //To do this, we pair the biggest and smalelst numbers together. 
            //Since we are extracting the maximum, this means we add bigger numbers more often
            //For example, if the bikers are [1,2,3] and [2,4,6]. We compute max(6,1)+max(4,2)+max(3,2) rather than max(6,3)+max(4,2)+(2,1) = 12, instead of which is more. 
            int bikerSpeed = max(dmojistanBikers[i],peglandBikers[N-i-1]);
            totalCount += bikerSpeed;
        }
        cout << totalCount << endl;
    }


}
