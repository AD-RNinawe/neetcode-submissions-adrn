class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        int ans=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]=='1'){
                    dfs(grid,r,c);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int r, int c){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            dfs(grid,r+directions[i][0],c+directions[i][1]);
        }
    }
};
