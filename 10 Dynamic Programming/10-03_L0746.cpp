#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> ret(len+1, 0);
        for (int i = 2; i <= len; i++) {
          ret[i] = min(ret[i-2] + cost[i-2], ret[i-1] + cost[i-1]);
        }
        return ret[len];
    }
};

int main() {
    vector<int> case_1 = {10,15,20};
    cout << Solution().minCostClimbingStairs(case_1) << endl;
    vector<int> case_2 = {1,100,1,1,1,100,1,1,100,1};
    cout << Solution().minCostClimbingStairs(case_2) << endl;
    return 0;
}
