class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>&a, const vector<int>&b){
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(comp)> mh;
        for (const auto& point: points){
            mh.push({point[0],point[1]});
            if (mh.size()>k){
                while(mh.size()>k){
                    mh.pop();
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(mh.top());
            mh.pop();
        }
        return res;
    }
};
