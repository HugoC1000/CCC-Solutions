#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long

struct Student{
    LL initialPosition;
    LL speed; // one meter per second
    LL hearingRange;
};

LL findSumOfTime(LL concertLocation, vector<Student> Students){
    LL totalWalkingTime = 0;
    for(Student student : Students){
        long long walkingTime = abs(concertLocation - student.initialPosition) - student.hearingRange;
        if (walkingTime > 0) {
            totalWalkingTime += walkingTime * student.speed;
        }
    }
    return totalWalkingTime;
}

int main(){
    LL N;
    cin >> N;

    vector<Student> students;


    for(int i = 0; i < N; i++){
        LL temp1;
        LL temp2;
        LL temp3;
        cin >> temp1 >> temp2 >> temp3;
        Student temp = {temp1, temp2, temp3};
        students.push_back(temp);
    }

    LL low = 0;
    LL high = 1e9;

    LL result = (long long)1e9;

    while (low <= high) {
        int mid = (low+high)/2;
        LL sumOfTimeForMid = findSumOfTime(mid, students);
        LL sumOfTimeForLeftOfMid = findSumOfTime(mid-1, students);
        LL sumOfTimeForRightOfMid = findSumOfTime(mid+1,students);
        
        result = sumOfTimeForMid;

        if (sumOfTimeForMid < sumOfTimeForRightOfMid && sumOfTimeForMid < sumOfTimeForLeftOfMid) {
            break;
        }

        if (sumOfTimeForMid == sumOfTimeForRightOfMid || sumOfTimeForMid == sumOfTimeForLeftOfMid) {
            break;
        }


        if (sumOfTimeForMid < sumOfTimeForRightOfMid) {
            high = mid - 1;
        } else if (sumOfTimeForMid < sumOfTimeForLeftOfMid) {
            low = mid + 1;
        }
    }

    cout << result << endl;

}
