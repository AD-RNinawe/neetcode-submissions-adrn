class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res=nums[0]
        mn,mx=1,1
        for num in nums:
            tmp=mx*num
            mx=max(num*mx,num*mn,num)
            mn=min(tmp,num*mn,num)
            res=max(res,mx)
        return res
