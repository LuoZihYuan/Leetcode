#include <vector>
#include <iostream>
using namespace std;

/* Your implementation of `Solution` goes here. */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int i = 0, i_step = 0, i_ahead = 0, j = 0, j_step = 1, j_ahead = 0, total = n * n;
        for(int count = 1; count <= total; count++) {
            ret[i][j] = count;
            i_ahead = i + i_step;
            j_ahead = j + j_step;
            if(i_ahead < 0 || i_ahead == n || j_ahead < 0 || j_ahead == n || ret[i_ahead][j_ahead]) {
                swap(i_step, j_step);
                j_step = -j_step;
                i_ahead = i + i_step;
                j_ahead = j + j_step;
            }
            i = i_ahead;
            j = j_ahead;
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
    
    vector<vector<int>> ret;
    ret = Solution().generateMatrix(3);
    for(auto row: ret) {
        for(auto column: row) cout << column << ", ";
        cout << endl;
    }
    ret = Solution().generateMatrix(1);
    for(auto row: ret) {
        for(auto column: row) cout << column << ", ";
        cout << endl;
    }
    
    return 0;
}