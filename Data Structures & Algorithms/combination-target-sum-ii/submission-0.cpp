class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, curr, 0);
        return res;
    }
private:
    void dfs(vector<int>& nums, int target, int i, vector<int>& curr, int total){
        if(total==target){
            res.push_back(curr);
            return;
        }
        if(total>target || i==nums.size()){
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums,target,i+1,curr,total+nums[i]);
        curr.pop_back();
        while (i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        dfs(nums,target,i+1,curr,total);
    }
};
