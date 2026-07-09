/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st,ed;
        for(const auto& i:intervals){
            st.push_back(i.start);
            ed.push_back(i.end);
        }
        sort(st.begin(),st.end());
        sort(ed.begin(),ed.end());
        int res=0,cnt=0,s=0,e=0;
        while(s<intervals.size()){
            if(st[s]<ed[e]){
                s++;
                cnt++;
            } else {
                e++;
                cnt--;
        }
            res=max(res,cnt);
        }
        return res;
    }
};
