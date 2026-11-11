class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        n2,n1=nums[0],max(nums[0],nums[1])
        for i in range(2,len(nums)):
            roll=max(n1,n2+nums[i])
            n2,n1=n1,roll
        return n1