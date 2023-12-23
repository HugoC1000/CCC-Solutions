#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> measurements;
    for (int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        measurements.push_back(temp);
    }

    sort(measurements.begin(), measurements.end());


    // for (int i = 0;i < measurements.size();i++){
    //     cout << measurements[i] << " ";
    // }

    cout << endl;
    int median = floor((N+1)/2)-1;

    cout << measurements[median] <<" ";
    for (int i = 1; i < measurements.size()/2+1; i++){
        if ( median+i <= N){
        cout << measurements[median+i] << " ";
        }
        if (median - i >= 0){
        cout << measurements[median-i]<< " ";
        }
    }

}
