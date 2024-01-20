//When an airplane wants to land on gates before or equal to 4, we give them to furtherest away from gate 1, so we give that airplane 4. 
//Maximies amount of airplanes able to land. 
//CCC original test data was weak, though to get the intended solutions, storing the avalible gates inside a set and using lower_bound() is needed. 
//This reduces the time complexity of the solution. 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    long long numOfGates,numOfPlanes;
    long long count = 0;
    cin >> numOfGates >> numOfPlanes;

    set<long long> available_gates;
    for (long long i = 1; i <= numOfGates; ++i) {
        available_gates.insert(i);
    }

    for (long long i = 0; i < numOfPlanes; i++){
        long long idealGate;
        cin >> idealGate;
        //cout << "I: " << i << "IdealGate: " << idealGate << endl;

        auto it_lower = available_gates.lower_bound(idealGate); // Find the first element not less than N
        //cout << "LowerBound: " << *it_lower << endl;
        
        if(it_lower== available_gates.begin()&&*it_lower <= idealGate){
            available_gates.erase(*it_lower);
            count++;
        } else if( *it_lower == idealGate){
            available_gates.erase(*it_lower);
            count++;
        }else if(it_lower != available_gates.begin()) {
            --it_lower;
            available_gates.erase(*it_lower);
            count++;
            //std::cout << "Count" << count << endl;{
        }else{
            break;
        }

    }
    cout << count <<endl;
}
