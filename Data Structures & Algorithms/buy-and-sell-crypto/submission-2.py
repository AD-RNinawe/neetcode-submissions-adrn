class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lt=prices[-1]
        ans=0
        for i in range(len(prices)-2,-1,-1):
            if prices[i]>=lt:
                lt=prices[i]
            else:
                ans=max(ans,lt-prices[i])
        return ans
