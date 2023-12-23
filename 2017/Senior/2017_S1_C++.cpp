#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> swiftArr;
    vector<int> semaArr;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        swiftArr.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        semaArr.push_back(temp);
    }
    int swiftSum = 0;
    int semaSum = 0;
    int maxK = 0;
    for (int i = 0; i < N; i++) {
        swiftSum += swiftArr[i];
        semaSum += semaArr[i];

        if (swiftSum == semaSum) {
            maxK = i+1;
        }
    }

    cout << maxK;
}   
