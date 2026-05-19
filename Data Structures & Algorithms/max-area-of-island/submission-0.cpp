class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        int ans=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1){
                    int ar=0;
                    dfs(grid,r,c,ar);
                    ans=max(ans,ar);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int r, int c, int& ar){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0){
            return;
        }
        ar++;
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            dfs(grid,r+directions[i][0],c+directions[i][1],ar);
        }
    }
};
