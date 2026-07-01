class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupsize) {
        if(hand.size()%groupsize!=0) return false;
        unordered_map<int,int>cnt;
        for(int num:hand) cnt[num]++;
        sort(hand.begin(),hand.end());
        for(int num:hand){
            if(cnt[num]>0){
                for(int i=num;i<num+groupsize;i++){
                    if(cnt[i]==0) return false;
                    cnt[i]--;
                }
            }
        }
        return true;
    }
};
