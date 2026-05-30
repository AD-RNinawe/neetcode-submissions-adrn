class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;
        for(const auto& time:times){
            edges[time[0]].emplace_back(time[1],time[2]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> mheap;
        mheap.push({0,k});
        set<int> vis;
        int t=0;
        while(!mheap.empty()){
            auto curr=mheap.top();
            mheap.pop();
            int w1=curr.first,n1=curr.second;
            if(vis.count(n1)){
                continue;
            }
            vis.insert(n1);
            t=w1;
            if(edges.count(n1)){
                for(const auto& next:edges[n1]){
                    int n2=next.first,w2=next.second;
                    if(!vis.count(n2)){
                        mheap.push({w1+w2,n2});
                    }
                }
            }
        }
        return vis.size()==n ? t : -1;
    }
};
