#include <vector>
#include <iostream>
using namespace std;

/* Your implementation of `Solution` goes here. */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
/* Uncomment the following code snippet for Leetcode performance optimization. */
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
    vector<int> case_1 = {-1,0,3,5,9,12};
    int ret = Solution().search(case_1, 9);
    cout << ret << endl;
    vector<int> case_2 = {-1,0,3,5,9,12};
    ret = Solution().search(case_2, 3);
    cout << ret << endl;
    vector<int> case_3 = {5};
    ret = Solution().search(case_3, 5);
    cout << ret << endl;
    return 0;
}