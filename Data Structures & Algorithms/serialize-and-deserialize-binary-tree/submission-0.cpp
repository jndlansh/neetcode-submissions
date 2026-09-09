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

class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root, string& s){
        if(root == NULL){
            s += "N,";
            return;
        }
        s += to_string(root->val) + ',';
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s; //"1,2,N,N,3,4,N,N,5,N,N"
    }

    // Decodes your encoded data to tree.
    TreeNode* buildTree(vector<string>&nodes, int& index){
        if(nodes[index] == "N"){
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = buildTree(nodes, index);
        root->right = buildTree(nodes, index);

        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp = "";

        for(char c : data){
            if(c ==','){
                nodes.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }
        int index = 0;
        return buildTree(nodes, index);
    }
};
