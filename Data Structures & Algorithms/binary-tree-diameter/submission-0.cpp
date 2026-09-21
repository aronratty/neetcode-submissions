class Solution {
private:
    int dfs(TreeNode* curr, int& result) {
        if (curr == nullptr) {
            return 0;
        }

        int leftTree = dfs(curr->left, result);
        int rightTree = dfs(curr->right, result);

        result = std::max(result, leftTree + rightTree);

        return 1 + std::max(leftTree, rightTree);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};