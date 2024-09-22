#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> circleOrder;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        circleOrder.push_back(temp);
    }
    int diameterCircle = N/2;
    int count = 0;

    // cout << "diameterCircle:  " << diameterCircle << endl;

    for(int i = 0;i<N;i++){
        // cout << "I: " << i<< endl;
        if(circleOrder[(diameterCircle+i)%N] == circleOrder[i]){
            // cout << "Opposing Side " << circleOrder[diameterCircle+i] << endl;
            count++;
        }
    }

    cout << count;
}
