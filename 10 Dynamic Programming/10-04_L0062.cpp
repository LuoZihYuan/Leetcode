#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> grid(m, vector<int>(n, 0));
    //     for(int i = 0; i < m; i++)
    //       for(int j = 0; j < n; j++)
    //         if (i == 0 || j == 0) grid[i][j] = 1;
    //         else grid[i][j] = grid[i-1][j] + grid[i][j-1];
    //     return grid[m-1][n-1];
    // }
    int uniquePaths(int m, int n) {
        double ret = 1.0;
        int count = min(m-1, n-1);
        int combinations = m + n - 2;
        for (int i = 0; i < count; i++, combinations--){
          ret *= combinations;
          ret /= i+1;
        }
        return int(ret);
    }
};

int main() {
  cout << Solution().uniquePaths(3, 7) << endl;
  cout << Solution().uniquePaths(3, 2) << endl;
  return 0;
}