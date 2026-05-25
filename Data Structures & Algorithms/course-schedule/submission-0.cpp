class Solution {
    unordered_map<int,vector<int>> prereqs;
    unordered_set<int> vis;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            prereqs[i]={};
        }
        for(const auto& prereq:prerequisites){
            prereqs[prereq[0]].push_back(prereq[1]);
        }
        for(int c=0;c<numCourses;c++){
            if(!dfs(c)){return false;}
        }
        return true;
    }
    bool dfs(int curr){
        if(vis.count(curr)){return false;}
        if(prereqs[curr].empty()){return true;}
        vis.insert(curr);
        for(int pre:prereqs[curr]){
            if(!dfs(pre)){return false;}
        }
        vis.erase(curr);
        prereqs[curr].clear();
        return true;
    }
};
