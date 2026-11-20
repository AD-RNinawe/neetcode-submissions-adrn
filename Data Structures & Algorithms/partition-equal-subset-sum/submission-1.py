class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        tot=sum(nums)
        if tot%2!=0:
            return False
        tgt=tot//2
        n=len(nums)
        memo=[[-1]*(tgt+1) for _ in range(n+1)]
        def dfs(i,tgt):
            if tgt==0:
                return True
            if i>=n or tgt<0:
                return False
            if memo[i][tgt]!=-1:
                return memo[i][tgt]
            memo[i][tgt]=dfs(i+1,tgt) or dfs(i+1,tgt-nums[i])
            return memo[i][tgt]
        return dfs(0,tgt)