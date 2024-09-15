#include <vector>
#include <iostream>
using namespace std;

/* Your implementation of `Solution` goes here. */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        int sum = 0, min = len + 1;
        for(int i = 0; i < len; i++) {
            sum += nums[i];
            if(sum < target) continue;
            while(sum >= target && j <= i) {
                min = (i-j+1 < min) ? i-j+1 : min;
                sum -= nums[j];
                j++;
            }
        }
        if(min > len) return 0;
        return min;
    }
};
/* Uncomment the following code snippet on Leetcode for performance optimization. */
// int init = [] {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     ofstream out("user.out");
//     cout.rdbuf(out.rdbuf());
// 
//     for (string s; getline(cin, s); cout << '\n') {
//         string t;
//         getline(cin, t);
//         int tar = stoi(t);
// 
//         for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i) {
//             bool _neg = 0;
//             if (s[_i] == '-')
//                 ++_i, _neg = 1;
//             int v = s[_i++] & 15;
//             while ((s[_i] & 15) < 10)
//                 v = v * 10 + (s[_i++] & 15);
//             if (_neg)
//                 v = -v;
//             if (v == tar) {
//                 cout << i;
//                 goto next;
//             }
//             if (v > tar)
//                 break;
//         }
//         cout << -1;
//     next:;
//     }
//     exit(0);
//     return 0;
// }();

int main() {
    
    int ret;
    vector<int> case_1 = {2,3,1,2,4,3};
    ret = Solution().minSubArrayLen(7, case_1);
    cout << ret << endl;
    vector<int> case_2 = {1,4,4};
    ret = Solution().minSubArrayLen(4, case_2);
    cout << ret << endl;
    vector<int> case_3 = {1,1,1,1,1,1,1,1};
    ret = Solution().minSubArrayLen(11, case_3);
    cout << ret << endl;
    
    return 0;
}