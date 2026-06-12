class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int currmn=1,currmx=1;
        for(int num:nums){
            int tmp=currmx*num;
            currmx=max(max(num*currmx,num*currmn),num);
            currmn=min(min(tmp,num*currmn),num);
            res=max(res,currmx);
        }
        return res;
    }
};
