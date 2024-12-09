/*
Idea is to use a 2D DP table, with dp[i][j], where i is the starting index of a subarray, and j is the ending index. 
the DP will store the max riceball size within that subarray. From index i to index j. 
To set this, up first dp[i][i] is going to be riceBalls[i], because the max riceball from index i to index i... is going to be itself. 
Then we will iterate diagonally. To do this, we iterate through different lengths of the subarray. 
We will also iterate through different start indexes.
We can combine both cases (merging 2 riceballs and merging 3) into one case. 
Within each subarray, we will split it into 3 parts. In practice this would look like riceballs: [3,9,3]
9 will be where we split the subarray. We will iterate through possible left indexes of the subarrays. 
Our goal is to get the riceballs from the start to the left index, and the riceballs from the right index to the end, the same. 
This will allow us to merge the riceballs. 
If  the start to left index is greater than the right index to the end, that means we can give some riceballs to the right index in an attempt to balance things out. 
Vice versa for the other side. 
Once they are equal, they will enter the last else if statement in the code below. 
There, we make sure that the left part(start index to middleSegmentLeft) is not 0. 
Then we add up the max riceball size from the left side, middle segment, and the right side. 
Note: If we are summing up adjacent riceballs(only two riceballs), the middle segment will = 0, to explain this: 
  If the middle segment's left and right were dp[i][j], we make them effectively dp[j][i]. This will always = 0, as we are only filling the upper part of the diagonal, 
  in the dp array. 
Because we do not add every possible combination to the DP(we only add combinations that can be merged), if you print the DP array, you will find most cells are 0. 
It is also because we don't fill all cells in, that dp[0][N] meaning maxriceBallSize from index 0 to index N won't give us the answer(it will prob be 0). 
Thus we have to loop over the entire dp array, and get the max value. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> riceBalls(N);
    for (int i = 0; i < N; i++) {
        cin >> riceBalls[i];
    }

    // dp[i][j] will store the maximum size of a rice ball we can form from subarray [i, j]
    vector<vector<int> > dp(N, vector<int>(N, 0));

    // Base case: a single rice ball can only be formed from itself
    for (int i = 0; i < N; i++) {
        dp[i][i] = riceBalls[i];
    }
    
    for(int lengthOfSubaray = 2; lengthOfSubaray <= N; lengthOfSubaray++){
        // cout << "Len: " << lengthOfSubaray << endl;
        for(int startIndex = 0; startIndex <= N - lengthOfSubaray; startIndex++){ //start index of the subarray
            int endIndex = startIndex + lengthOfSubaray -1;  //end index of the subarray
            // cout << "startIndex: " << startIndex << " endIndex: " << endIndex << endl;


            int middleSegmentLeft = startIndex; 
            int middleSegmentRight = endIndex;

            while (middleSegmentRight > middleSegmentLeft){
                // cout << "middleSegmentLeft: " << middleSegmentLeft << endl;
                // cout << "middleSegmentRight: " << middleSegmentRight << endl;
                
                if (dp[startIndex][middleSegmentLeft] < dp[middleSegmentRight][endIndex]) {
                    middleSegmentLeft++;
                }else if (dp[startIndex][middleSegmentLeft] > dp[middleSegmentRight][endIndex]) {
                    middleSegmentRight--;
                }else if (dp[startIndex][middleSegmentLeft] != 0) {
                    // Check if the middle segment can be merged or is empty
                    if (dp[middleSegmentLeft + 1][middleSegmentRight - 1] > 0 || middleSegmentLeft + 1 > middleSegmentRight - 1) { //First case considers merging 3 riceballs. Second case considers adjacent ones. 
                        int newRiceBallSize = dp[startIndex][middleSegmentLeft] + dp[middleSegmentLeft + 1][middleSegmentRight - 1] + dp[middleSegmentRight][endIndex]; 
                        //If adjacent, dp[middleSegmentLeft + 1][middleSegmentRight - 1] will = 0. in dp[i][j], and j > i, the cell will = 0. 
                        dp[startIndex][endIndex] = max(dp[startIndex][endIndex], newRiceBallSize);
                        break;
                    }
                    middleSegmentLeft++;
                }
            }
        }

    }
    int maxSize = 1; 

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {  // Only print values where i <= j
    //         // Printing each element with a width of 3 for alignment (2 digits plus space)
    //         cout << setw(3) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxSize = max(maxSize, dp[i][j]);
        }
    }
    cout <<  maxSize << endl;
}
