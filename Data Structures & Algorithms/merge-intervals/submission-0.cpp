class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(auto& interval:intervals){
            int st=interval[0];
            int end=interval[1];
            int lastend=output.back()[1];
            if(st<=lastend){
                output.back()[1]=max(lastend,end);
            } else {
                output.push_back({st,end});
            }
        }
        return output;
    }
};
