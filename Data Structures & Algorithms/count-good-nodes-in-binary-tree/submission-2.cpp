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
    void solve(TreeNode* root, int maxSoFar, int& cnt){
        if(root == NULL) return;

        if(root->val >= maxSoFar){
            cnt++;
        }

        maxSoFar = max(maxSoFar, root->val);

        solve(root->left, maxSoFar, cnt);
        solve(root->right, maxSoFar, cnt);
    }
    int goodNodes(TreeNode* root) {
        int maxSoFar = root->val;
        int cnt = 0;
        solve(root, maxSoFar, cnt);
        return cnt;
    }
};
