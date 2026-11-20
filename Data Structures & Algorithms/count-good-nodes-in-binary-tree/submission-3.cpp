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
private:
    void dfs(TreeNode* root, int& count, int max) {
        if(root == NULL) {
            return; 
        }

        if(root->val >= max) {
            count++; 
            max = std::max(root->val, max); 
        }; 

        dfs(root->right, count, max); 
        dfs(root->left, count, max); 
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0; 
        int max = INT_MIN; 
        dfs(root, count, max); 
        return count; 
    }
};
