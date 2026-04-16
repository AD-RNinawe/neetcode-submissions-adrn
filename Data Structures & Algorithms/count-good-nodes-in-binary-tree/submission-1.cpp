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
              int goodNodes(TreeNode* root) {
                return dfs(root,root->val);
              }
              int dfs(TreeNode* root, int currmx){
                if (!root) return 0;
                int cnt=0;
                if (root->val>=currmx){
                    cnt=1;
                    currmx=root->val;
                }
                cnt+=dfs(root->left,currmx);
                cnt+=dfs(root->right,currmx);
                return cnt;
              }
          };
