#include <iostream>
#include <vector>

using namespace std;

int main(){
    int nRows,mColumns, nPalindromeRows, mPalindromeColumns;

    cin >> nRows >> mColumns >> nPalindromeRows >> mPalindromeColumns;

    vector<vector<char> > grid(nRows,vector<char>(mColumns));

    if(nPalindromeRows ==0){

        //fill mPalindromeColumns with a

            //a a a a b
            //a a a a b
            //a a a b c

            for(int i = 0;i<mPalindromeColumns;++i){
                for(int j = 0;j<nRows;j++){
                    grid[j][i] = 'a' + i %22;
                }
            }

            //Fill columns that are not palindromes

            //increment starting from mColumns - mPalindromeColumns 

            for(int i = 0;i<(mColumns - mPalindromeColumns);i++){

                for(int j = 0;j<nRows-1;j++){
                    grid[j][i + mPalindromeColumns] = 'b'+i % 22;
                }
                grid[nRows-1][mPalindromeColumns + i] = 'c' + i%22;
            }



    }else if(mPalindromeColumns ==0){

        for(int i = 0;i<nPalindromeRows;++i){
            for(int j = 0;j<mColumns;j++){
                grid[i][j] = 'a'+i %22;
            }

        }

        //Fill columns that are not palindromes

        //increment starting from mColumns - mPalindromeColumns 

        for(int i = 0;i<(nRows - nPalindromeRows);i++){

            for(int j = 0;j<mColumns-1;j++){
                grid[i+nPalindromeRows][j] = 'b'+i % 22;
            }
            grid[i+nPalindromeRows][mColumns-1] = 'c' + i%22;
        }

    }else if(nPalindromeRows == nRows){
        
       if(mColumns % 2 == 0){
            if(mPalindromeColumns % 2 == 1){
                grid[0][0]  ='$';
            }else{
                
                int notPalindromeColumns = mColumns - mPalindromeColumns;
                for(int i = 0;i<notPalindromeColumns/2;i++){
                    grid[0][i] = 'b';
                }

                for(int i = notPalindromeColumns/2;i<(notPalindromeColumns/2+mPalindromeColumns);i++){
                    grid[0][i] = 'a';
                }

                for(int i = (notPalindromeColumns/2+mPalindromeColumns) ;i<mColumns;i++){
                    grid[0][i] = 'b';
                }

            }
        }else{
            if(mPalindromeColumns % 2 == 0){

                int middleLength = mPalindromeColumns + 1; //+1 to accoutn for middle a
                int notMiddle = mColumns-middleLength;
                int middleLengthStart = notMiddle/2;
                int middleLengthEnd = middleLength+middleLengthStart;



                for(int i = 0;i<mColumns;i++){
                    if(i < middleLengthStart){
                        grid[0][i] = 'b';
                    }else if(i >= middleLengthEnd){
                        grid[0][i] = 'b';
                    }else{
                        if((i-middleLengthStart)+1 == (middleLength+1)/2){
                            grid[0][i] = 'b';
                        }else{
                            grid[0][i] = 'a';
                        }
                    }
                }
            }else{

                int middleLength = mPalindromeColumns;
                int notMiddle = mColumns-middleLength;
                int middleLengthStart = notMiddle/2;
                int middleLengthEnd = middleLength+middleLengthStart;
                // cout << "Middle Length: " << middleLength << endl;
                // cout << "Not middle: " << notMiddle << endl;
                for(int i = 0;i<mColumns;i++){
                    if(i < middleLengthStart){
                        grid[0][i] = 'b';
                    }else if(i >= middleLengthEnd){
                        grid[0][i] = 'b';
                    }else{
                        grid[0][i] = 'a';
                    }
                }
            }
        }

        if(grid[0][0] != '$'){ 
            for(int i = 1;i<nRows;i++){
                for(int j = 0;j<mColumns;j++){
                    grid[i][j] = 'a';
                }
            }
        }
        

    }else if(mPalindromeColumns == mColumns){

        if(nRows %2 == 0){
            //cout << "Entered 1"  << endl;
            if(nPalindromeRows % 2 == 1){
                //cout << "Entered 2 " << endl;
                grid[0][0] = '$';
            }else{
                int notPalindromeRows = nRows - nPalindromeRows;
                for(int i = 0;i<notPalindromeRows/2;i++){
                    grid[i][mColumns-1] = 'b';
                }

                for(int i = notPalindromeRows/2;i<(nPalindromeRows+notPalindromeRows/2);i++){
                    grid[i][mColumns-1] = 'a';
                }

                for(int i = (nPalindromeRows+notPalindromeRows/2);i<nRows;i++){
                    grid[i][mColumns-1] = 'b';
                }

            }
        }else{
            if(nPalindromeRows % 2 == 1){

                int middleLength = nPalindromeRows;
                int notMiddle = nRows-middleLength;
                int middleLengthStart = notMiddle/2;
                int middleLengthEnd = middleLength+middleLengthStart;
                
                // cout << "Middle Length: " << middleLength << endl;
                // cout << "Not middle: " << notMiddle << endl;

                for(int i = 0;i<nRows;i++){
                    if(i < middleLengthStart){
                        grid[i][mColumns-1] = 'b';
                    }else if(i >= middleLengthEnd){
                        grid[i][mColumns-1] = 'b';
                    }else{
                        grid[i][mColumns-1] = 'a';
                    }
                }
            }else{

                int middleLength = nPalindromeRows+1;
                int notMiddle = nRows-middleLength;
                //cout << "Not middle: " << notMiddle << endl;
                int middleLengthStart = notMiddle/2;
                int middleLengthEnd = middleLength+middleLengthStart;

                for(int i = 0;i<mColumns;i++){
                    if(i < middleLengthStart){
                        grid[i][mColumns-1] = 'b';
                    }else if(i >= middleLengthEnd){
                        grid[i][mColumns-1] = 'b';
                    }else{
                        if((i-middleLengthStart)+1 == (middleLength+1)/2){
                            grid[i][mColumns-1] = 'b';
                        }else{
                            grid[i][mColumns-1] = 'a';
                        }
                    }
                } 
            }
        }
        if(grid[0][0] != '$'){
            for(int i = 0;i<nRows;i++){
                for(int j = 0;j<mColumns-1;j++){
                    grid[i][j] = 'a';
                }
            }
        }

    }else{

        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < mColumns; j++){
                if(i < nPalindromeRows || j < mPalindromeColumns){
                    grid[i][j] = 'a';
                }else{
                    grid[i][j] = 'b';
                }
            }
        }

    }

    if(grid[0][0] == '$' ){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i = 0;i< nRows;i++){
            for(int j = 0;j<mColumns;j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

}
