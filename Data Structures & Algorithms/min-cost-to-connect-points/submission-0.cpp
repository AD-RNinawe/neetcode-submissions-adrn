class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),node=0;
        vector<int> dist(n,100000000);
        vector<bool> vis(n,false);
        int edges=0,res=0;
        while(edges<n-1){
            vis[node]=true;
            int nxt=-1;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                int curr=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
                dist[i]=min(dist[i],curr);
                if(nxt==-1||dist[i]<dist[nxt]){
                    nxt=i;
                }
            }
            res+=dist[nxt];
            node=nxt;
            edges++;
        }
        return res;
    }
};
