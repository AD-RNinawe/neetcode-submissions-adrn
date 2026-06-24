class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tgt=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i]>=tgt){
                tgt=i;
            }
        }
        return tgt==0;
    }
};
