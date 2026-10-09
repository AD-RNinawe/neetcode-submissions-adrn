class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res=[]
        nums.sort()
        def dfs(i,cur,tot):
            if tot==target:
                res.append(cur.copy())
                return
            for j in range(i,len(nums)):
                if tot+nums[j]>target:
                    return
                cur.append(nums[j])
                dfs(j,cur,tot+nums[j])
                cur.pop()
        dfs(0,[],0)
        return res
        