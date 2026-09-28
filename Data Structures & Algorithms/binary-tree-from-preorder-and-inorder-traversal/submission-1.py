# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        mp={}
        for i in range(len(inorder)):
            mp[inorder[i]]=i
        q=collections.deque(preorder)
        def build(st,ed):
            if st>ed:
                return None
            root=TreeNode(q.popleft())
            mid=mp[root.val]
            root.left=build(st,mid-1)
            root.right=build(mid+1,ed)
            return root
        return build(0,len(q)-1)

        