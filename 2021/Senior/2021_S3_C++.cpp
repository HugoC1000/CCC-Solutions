  //there is a U shaped feature

  //we might can perform some kind search to find the lowest point on this U shape

  //what should we search in, and what are we looking for?

  //how do we know that we are at the bottom?
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <cmath>
  using namespace std;



  long long getWalkingTime(int p, vector<vector<int>> f) {
      long long out = 0;
      for (const vector<int>& i : f) {
          long long walk = abs(p - i[0]) - i[2];
          if (walk > 0) {
              out += walk * i[1];
          }
      }
      return out;
  }

  int main() {
      int n;
      std::cin >> n;
      vector<vector<int>> f;
      f.resize(n, vector<int>(3));
//min starts from 1billion, max start from 0, as from the question input range
      long long low = 1000000000;
      long long high = 0;
      for (long long i = 0; i < n; i++) {
          cin >> f[i][0] >> f[i][1] >> f[i][2];
          if (f[i][0] > high) {
              high = f[i][0];
          }
          if (f[i][0] < low) {
              low = f[i][0];
          }
      }

      int mid = 0;
      long long s = 0;
      while (low <= high) {
          mid = (low + high) / 2;
          s = getWalkingTime(mid,f);
          long long sLeft = getWalkingTime(mid - 1,f);
          long long sRight = getWalkingTime(mid + 1,f);
          if (s < sRight && s < sLeft) {
              break;
          }
          if (s == sRight || s == sLeft) {
              break;
          }
          if (s < sRight) {
              high = mid - 1;
          } else if (s < sLeft) {
              low = mid + 1;
          }
      }

      cout << s << endl;
      return 0;
  }
