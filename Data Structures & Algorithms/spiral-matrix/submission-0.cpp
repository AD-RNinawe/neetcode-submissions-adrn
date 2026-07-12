class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> steps={m,n-1};
        int r=0,c=-1,d=0;
        while (steps[d%2]){
            for(int i=0;i<steps[d%2];i++){
                r+=dirs[d].first;
                c+=dirs[d].second;
                res.push_back(matrix[r][c]);
            }
            steps[d%2]--;
            d=(d+1)%4;
        }
        return res;
    }
};
