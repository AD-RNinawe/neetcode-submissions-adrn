class Solution:
    def maxArea(self, heights: List[int]) -> int:
       l,r=0,len(heights)-1
       ans=0
       while l<r:
            ar=min(heights[l],heights[r])*(r-l)
            ans=max(ans,ar)
            if heights[l]<=heights[r]:
                l+=1
            else:
                r-=1
       return ans

        