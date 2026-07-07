class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=0;
        int prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int st=intervals[i][0];
            int ed=intervals[i][1];
            if(st>=prev){
                prev=ed;
            } else {
                res++;
                prev=min(prev,ed);
            }
        }
        return res;
    }
};
