import bisect

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails=[]
        tails.append(nums[0])
        for i in range(1,len(nums)):
            if tails[-1]<nums[i]:
                tails.append(nums[i])
                continue
            idx=bisect.bisect_left(tails,nums[i])
            tails[idx]=nums[i]
        return len(tails)

        