# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res=root.val
        def dfs(root):
            nonlocal res
            if not root:
                return 0
            lm=dfs(root.left)
            lm=max(lm,0)
            rm=dfs(root.right)
            rm=max(rm,0)
            res=max(res,root.val+lm+rm)
            return root.val+max(lm,rm)
        dfs(root)
        return res