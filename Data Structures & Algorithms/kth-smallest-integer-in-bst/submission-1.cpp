/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root, int& cnt, int& ans, int k){
        if(root == NULL) return;

        solve(root->left, cnt, ans, k);
        if(cnt >= k){
            return;
        }
        cnt++;
        if(cnt == k) ans = root->val;
        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int cnt = 0;
        solve(root, cnt, ans, k);
        return ans;
    }
};
