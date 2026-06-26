class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c, int prev){
        int rows=matrix.size(),cols=matrix[0].size();
        if(r<0||r>=rows||c<0||c>=cols||matrix[r][c]<=prev){return 0;}
        if(dp[r][c]!=-1) return dp[r][c];
        int res=1;
        for(vector<int> d: dirs){
            res=max(res,1+dfs(matrix,r+d[0],c+d[1],matrix[r][c]));
        }
        dp[r][c]=res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        dp=vector<vector<int>>(rows,vector<int>(cols,-1));
        int ans=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                ans=max(ans,dfs(matrix,r,c,INT_MIN));
            }
        }
        return ans;
    }
};
