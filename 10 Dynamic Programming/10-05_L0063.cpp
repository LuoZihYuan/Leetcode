#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
          for(int j = 0; j < n; j++)
            if (obstacleGrid[i][j] == 1) grid[i][j] = 0;
            else if (i == 0 && j == 0) grid[i][j] = 1;
            else if (i == 0) grid[i][j] = grid[i][j-1];
            else if (j == 0) grid[i][j] = grid[i-1][j];
            else grid[i][j] = grid[i-1][j] + grid[i][j-1];
        return grid[m-1][n-1];
    }
};

int main() {
  vector<vector<int>> case_1 = {{0,0,0},
                                {0,1,0},
                                {0,0,0}};
  cout << Solution().uniquePathsWithObstacles(case_1) << endl;
  vector<vector<int>> case_2 = {{0,1},
                                {1,0}};
  cout << Solution().uniquePathsWithObstacles(case_2) << endl;
  return 0;
}