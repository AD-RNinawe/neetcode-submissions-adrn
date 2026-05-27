class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1){return false;}
        vector<vector<int>> adj(n);
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> vis;
        if(!dfs(0,-1,vis,adj)){
            return false;
        }
        return vis.size()==n;
    }
private:
    bool dfs(int node, int parent, unordered_set<int>& vis, vector<vector<int>>& adj){
        if(vis.count(node)){return false;}
        vis.insert(node);
        for(int nei: adj[node]){
            if(nei==parent){
                continue;
            }
            if(!dfs(nei,node,vis,adj)){
                return false;
            }
        }
        return true;
    }
};
