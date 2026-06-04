class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> vis;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> mh;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        mh.push({grid[0][0],0,0});
        vis.insert({0,0});
        while(!mh.empty()){
            auto curr=mh.top();mh.pop();
            int t=curr[0],r=curr[1],c=curr[2];
            if(r==n-1 && c==n-1){return t;}
            for(const auto& dir:dirs){
                int nr=r+dir[0],nc=c+dir[1];
                if(nr<0 || nc<0 || nr==n || nc==n || vis.count({nr,nc})){continue;}
                vis.insert({nr,nc});
                mh.push({max(t,grid[nr][nc]),nr,nc});
            }
        }
        return n*n;
    }
};
