class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(nums,0,subset);
        return res;
    }
private:
    void dfs(const vector<int>& nums, int i, vector<int>& subset){
        if( i== nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset);
        subset.pop_back();  
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }  
        dfs(nums,i+1,subset);
    }
};
