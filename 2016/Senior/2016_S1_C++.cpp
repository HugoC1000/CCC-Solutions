//The idea of this quesiton is that as long as the number of occurences of letters of the second string are less than or equal to the occurence of letters of the first string, it is a correct solution. 
//The length of the two strings are the same, and if the number of occurencees of letters is less, then the asteriks could take care of it.
//For example: ABCD and AB**. The occurences in the first string are A:1 B:1 C:1 D:1. The second has A:1 B:1 C:0 D:0. The two remaining missing letters could fill it in. 
//If we had ABCD and AA**, this instantly is invalidated as we have 2 As in the second and theres no way for us to subtract an A. 

#include <iostream>
#include <string>
#include <map>

int main() {
    std::string stringA, stringB;
    std::cin >> stringA >> stringB;

    std::map<char, int> countOfLetterA;
    std::map<char, int> countOfLetterB;

    // Count occurrences of letters in stringA
    for (char letter : stringA) {
        if (std::isalpha(letter)) { //If the character is in the alphabet, we add one to the number of occurences of that letter. 
            countOfLetterA[letter]++;
        }
    }

    for (char letter : stringB) {
        if (std::isalpha(letter)) { //If the character is in the alphabet, we add one to the number of occurences of that letter. 
            countOfLetterB[letter]++;
        }
    }

    bool allCountsLessEqual = true;
  
    for (const auto& pair : countOfLetterB) {
        char letter = pair.first;
        int countInB = pair.second;
        int countInA = countOfLetterA[letter];

        if (countInB > countInA) {
            allCountsLessEqual = false;
            break;
        }
    }
    if (allCountsLessEqual) {
        std::cout << "A" << std::endl;
    } else  {
        std::cout << "N" << std::endl;
    }

    return 0;
}
