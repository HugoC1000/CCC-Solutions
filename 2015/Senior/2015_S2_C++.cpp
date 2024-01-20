//Simple greedy algorithm. The moment an athelete requests a jersey and its avalible, just give it to them. 
//If A and B both want jersey 1 it doesn't matter which one we give it to, since we are only recording the number of people that were able to get a jeresy. 
//So either way, whether we give it to A or B, the count is only going to increase by 1.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int numOfJersey, numOfAtheletes;
    cin >> numOfJersey >> numOfAtheletes;
    int count = 0;

    vector<int> jerseySizes;
    for(int i = 0;i<numOfJersey;i++){
        char temp;
        cin>>temp;

        if (temp =='L'){
            jerseySizes.push_back(3);
        }else if(temp =='M'){
            jerseySizes.push_back(2);
        }else{
            jerseySizes.push_back(1);
        }
    }
    for (int j = 0;j<jerseySizes.size();j++){
            // cout << jerseySizes[j] << " ";
    }


    for(int i = 0;i<numOfAtheletes;i++){
        char temp;
        int jerseyNumber;
        cin>>temp >> jerseyNumber;

        // cout << "Temp: " << temp << endl;
        // cout << "Jersey number: " << jerseyNumber << endl;

        int perferredSize;
        if (temp =='L'){
             perferredSize = 3;
        }else if(temp =='M'){
             perferredSize = 2;
        }else{
             perferredSize = 1;
        }

        // cout << "Perferred Size: " << perferredSize << endl;

        if (jerseySizes[jerseyNumber-1] >= perferredSize && jerseySizes[jerseyNumber-1] != -1){ //If the jersey sizes is bigger than or equal to the athelete's perferred size and the jersey is not already taken(Marked by the -1)
            count += 1;
            jerseySizes[jerseyNumber-1] = -1;
            // cout << "count: " << count << endl;
        } 
        // cout << endl;
        // for (int j = 0;j<jerseySizes.size();j++){
        //     cout << jerseySizes[j] << " ";
        // }

    }

    cout << count;
}
