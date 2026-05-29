class Solution {
    vector<bool> vis;
    vector<vector<int>> adj;
    unordered_set<int> cycle;
    int st;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        adj.resize(n+1);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n+1,false);
        st=-1;
        dfs(1,-1);
        for(int i=edges.size()-1;i>=0;i--){
            int u = edges[i][0], v=edges[i][1];
            if(cycle.count(u) && cycle.count(v)){
                return {u,v};
            }
        }
        return {};
    }
private:
    bool dfs(int node, int par){
        if(vis[node]){
            st=node;
            return true;
        }
        vis[node]=true;
        for(int nei:adj[node]){
            if(nei==par){continue;}
            if(dfs(nei,node)){
                if(st!=-1){cycle.insert(node);}
                if(node==st){st=-1;}
                return true;
            }
        }
        return false;
    }
};
