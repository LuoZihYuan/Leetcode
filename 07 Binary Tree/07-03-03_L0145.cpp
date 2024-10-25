#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Your implementation of `Solution` goes here. */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> buffer;
        vector<TreeNode*> postorder;
        if (root == nullptr)
            return vector<int>{};
        TreeNode* current;
        buffer.push_back(root);
        postorder.push_back(root);
        while(buffer.size() > 0) {
            current = buffer.back();
            buffer.pop_back();
            auto it = find(postorder.begin(), postorder.end(), current);
            if(current->left != nullptr)
                postorder.insert(it, current->left);
            it = find(postorder.begin(), postorder.end(), current);
            if(current->right != nullptr) {
                buffer.push_back(current->right);
                postorder.insert(it, current->right);
            }
            if(current->left != nullptr) {
                buffer.push_back(current->left);
            }
        }
        vector<int> result;
        for(auto node: postorder) {
            result.push_back(node->val);
        }
        return result;
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
    
    return 0;
}