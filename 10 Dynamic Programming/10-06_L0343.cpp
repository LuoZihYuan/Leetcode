#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 2; i <= n; i++) {
          for(int j = 1; j <= (i / 2); j++) {
            dp[i] = max(dp[i], max((i-j)*j, dp[i-j] * j));
          }
        }
        return dp[n];
    }
};

int main() {
  cout << Solution().integerBreak(2) << endl;
  cout << Solution().integerBreak(10) << endl;
  return 0;
}