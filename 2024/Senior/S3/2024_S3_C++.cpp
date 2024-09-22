#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Swipe {
    char c;
    int num1;
    int num2;
};

struct sect {
    int value;
    int num1;
    int num2;
};


int main(){

    int n;
    cin >> n;
    vector<int> startStr(n);
    vector<int> targetStr(n);

    for(int k =0;k<n;k++){
        int temp;
        cin >> temp;
        startStr[k] = temp;
    }

     
    for(int k =0;k<n;k++){
        int temp;
        cin >> temp;
        // cout << "Temp: " << temp;
        targetStr[k] = temp;
    }

    if(n == 1&& targetStr[0] != startStr[0]){
        cout << "NO" << endl;
    }else{
    //Generates sections

    vector<sect > sections;
    int sectionStart = 0;
    for(int i = 1 ; i < n ; i++){
        if(targetStr[i] != targetStr[i-1]){
            sect temp = {targetStr[i-1], sectionStart,i-1};
            sections.push_back(temp);
            sectionStart = i;
        }
        if(i == n-1){
            sect temp = {targetStr[i], sectionStart,n-1};
            sections.push_back(temp);
        }

    }


    bool condition = true;
    vector<Swipe> rightSwipes;
    vector<Swipe> leftSwipes;
    int sectionIndex = 0; 
    if(!sections.empty()){
        for(int i = 0;i<startStr.size();i++){
            if(startStr[i] == sections[sectionIndex].value){
                int startIndex = sections[sectionIndex].num1;
                int endIndex = sections[sectionIndex].num2;
                //Case 1 i < start
                
                if(i< startIndex){
                    Swipe temp = {'R', i, endIndex};
                    rightSwipes.push_back(temp);
                }else if( i == startIndex){ //Case 2 i = start
                    Swipe temp = {'R' , startIndex, endIndex};
                    rightSwipes.push_back(temp);
                }else if(startIndex < i && i < endIndex){  //Case 3 start < i < end

                    Swipe temp1 = {'L', startIndex, i};
                    Swipe temp2 = {'R', i, endIndex};
                    leftSwipes.push_back(temp1);
                    rightSwipes.push_back(temp2);
                }else if(i == endIndex){ //Case 4 i = end
                    Swipe temp = {'L' , startIndex, endIndex};
                    leftSwipes.push_back(temp);
                }else if(i > endIndex){ //Case 5 i > end
                    Swipe temp = {'L', startIndex, i};
                    leftSwipes.push_back(temp);
                }
                
                sectionIndex += 1;
            }
        }
    }

    //  cout << sectionIndex << endl;
    // cout << sections.size() << endl;

    if(sectionIndex != sections.size()){
        condition = false; 
    }


    // cout << "Starting swipes output: " << endl;
    // for(int i = 0;i<swipes.size();i++){
    //     cout << swipes[i].c << " " << swipes[i].num1 << " " << swipes[i].num2 << endl;
    // }

    // cout << endl;

    if(condition == true){
        cout << "YES" << endl;
        cout << rightSwipes.size() + leftSwipes.size() << endl;
        for(int i = 0; i < leftSwipes.size();i++){
            cout << leftSwipes[i].c << " " << leftSwipes[i].num1 << " " << leftSwipes[i].num2 << endl;
        }

        for(int i = rightSwipes.size()-1;i >= 0;i--){
            cout << rightSwipes[i].c << " " << rightSwipes[i].num1 << " " << rightSwipes[i].num2 << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    }
}
