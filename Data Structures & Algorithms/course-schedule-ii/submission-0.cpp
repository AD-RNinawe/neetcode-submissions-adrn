class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto& pre: prerequisites){
            indeg[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int fin=0;
        vector<int> output(numCourses);
        while(!q.empty()){
            int node=q.front();q.pop();
            output[numCourses-fin-1]=node;
            fin++;
            for(int nei:adj[node]){
                indeg[nei]--;
                if(indeg[nei]==0){q.push(nei);}
            }
        }
        if (fin!=numCourses){return {};}
        return output;
    }
};
