#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    //Save stuff to distances
    vector<int> distances(4);
    for (int i = 0; i < 4; i++) {
        cin >> distances[i];
    }

    vector<vector<int> > distanceTable(5, vector<int>(5));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                distanceTable[i][j] = 0;
            } else if (i < j) { //Sum right side of the thing
                int sum = 0;
                for (int k = i; k < j; k++) {
                    sum += distances[k];
                }
                distanceTable[i][j] = sum;
            } else { //To sum the left side of the vector, you can just flip i and j
                distanceTable[i][j] = distanceTable[j][i];
            }
        }
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j!= 4){
            cout << distanceTable[i][j] << " ";
            }else{
                cout << distanceTable[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
