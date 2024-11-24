#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 3000

int triangle[MAX_SIZE][MAX_SIZE];
using namespace std;

void Solution()
{
    int numRows, targetSize;
    cin >> numRows >> targetSize;

    // // Input the values into the triangle
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            cin >> triangle[row][col];
        }
    }

    // Generate sizes of smaller triangles
    vector<int> triangleSizes;
    triangleSizes.push_back(targetSize); //[6, 4, 3, 2, 1]
    int currentSize = targetSize;
    while (currentSize > 2)
    {
        currentSize = (2 * currentSize + 2) / 3;
        if (currentSize == 2){
            break;
        }
        triangleSizes.push_back(currentSize);
        // cout << currentSize << " ";
    }



    // cout << endl;
    triangleSizes.push_back(2);
    triangleSizes.push_back(1);
    reverse(triangleSizes.begin(), triangleSizes.end());

    // for(int i = 0; i < triangleSizes.size();i++){
    //     cout << triangleSizes[i] << " ";
    // }

    // cout << endl;
    // cout << triangleSizes.size() << endl;

    // Update DP table for each triangle siz
    for (int idx = 1; idx < (int)triangleSizes.size() && triangleSizes[idx] <= targetSize; idx++)
    {
        int sizeDifference = triangleSizes[idx] - triangleSizes[idx - 1];
        for (int row = 0; row + triangleSizes[idx] <= numRows; row++)
        {
            for (int col = 0; col <= row; col++)
            {
                triangle[row][col] = max(triangle[row][col], max(
                                                                 triangle[row + sizeDifference][col],
                                                                 triangle[row + sizeDifference][col + sizeDifference]));
            }
        }
        
    }

    // Calculate the sum of maximum values
    long long totalMaxSum = 0;
    for (int row = 0; row + targetSize <= numRows; row++)
    {
        for (int col = 0; col <= row; col++)
            totalMaxSum += triangle[row][col];
    }
    cout << totalMaxSum << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solution();
    return 0;
}
