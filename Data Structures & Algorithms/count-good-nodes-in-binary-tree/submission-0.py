# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        count = 0

        def dfs(root: TreeNode, biggest):
            nonlocal count 

            if not root:
                return 
            
            if root.val >= biggest:
                biggest = root.val 
                count += 1
            
            dfs(root.left, biggest)
            dfs(root.right, biggest)

        dfs(root, root.val)
        return count


        