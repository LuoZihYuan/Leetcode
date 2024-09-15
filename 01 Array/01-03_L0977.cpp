#include <vector>
#include <iostream>
using namespace std;

/* Your implementation of `Solution` goes here. */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len, 0);
        int j = 0, k = len-1;
        for(int i = len-1; i >= 0; i--) {
            if (nums[j] * nums[j] > nums[k] * nums[k]) {
                ret[i] = nums[j] * nums[j];
                j++;
            } else {
                ret[i] = nums[k] * nums[k];
                k--;
            }
        }
        return ret;
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
    
    vector<int> ret;
    vector<int> case_1 = {-4,-1,0,3,10};
    ret = Solution().sortedSquares(case_1);
    for(auto i: ret)
        cout << i << ", ";
    cout << endl;
    vector<int> case_2 = {-7,-3,2,3,11};
    ret = Solution().sortedSquares(case_2);
    for(auto i: ret)
        cout << i << ", ";
    cout << endl;
    return 0;
}