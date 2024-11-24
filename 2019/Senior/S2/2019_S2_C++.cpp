#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int x){
  if(x <= 1){
    return false;
  }
  for(int a = 2;a <= sqrt(x);a++){
    if(x%a == 0){
      return false;
    }
  }
  return true;
}


int main() {
  int numofinp;
  cin >> numofinp;
  for(int b = 0;b < numofinp;b++ ){
    int n;
    cin >> n;
    for(int c = 2;c<n;c++){
      if (is_prime(c)){
        if (is_prime((2*n)-c)){
           cout << c << " "<< (2*n)-c << endl;
          break;
        }
      }
    }
  }
}
