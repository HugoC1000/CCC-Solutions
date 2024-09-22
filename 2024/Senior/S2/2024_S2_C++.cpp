#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main(){
    int T,N;
    cin >> T >> N;

    for(int i = 0; i< T;i++){

        bool result = true;

        string str;
        cin >> str;
        unordered_map<char,int> dict;
        for(int j = 0; j< N; j++){
            dict[str[j]]++; 
        }


        if(dict[str[0]] > 1 ){ //First element is heav


            for(int j = 0;j< N;j++){
                if (j % 2 == 0){
                    if(dict[str[j]] <=  1){
                        result = false;
                        break;
                    }
                }else{
                    if(dict[str[j]]  > 1){
                        result = false;
                        break; 
                    }
                }
            }
            
        }else{  //First elemet is light
            for(int j = 0; j< N; j++){ 
                if(j%2 == 0){
                    if(dict[str[j]] > 1){
                        result = false;
                        break;
                    }
                }else{
                    if(dict[str[j]] <= 1){
                        result = false;
                        break;
                    }
                }

            }
        }


        if(result == true){
            cout << "T" <<endl;
        }else{
            cout << "F" << endl;
        }
    }
}
