class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n=len(heights)
        st=[]
        lm=[-1]*n
        for i in range(n):
            while st and heights[st[-1]]>=heights[i]:
                st.pop()
            if st:
                lm[i]=st[-1]
            st.append(i)
        st=[]
        rm=[n]*n
        for i in range(n-1,-1,-1):
            while st and heights[st[-1]]>=heights[i]:
                st.pop()
            if st:
                rm[i]=st[-1]
            st.append(i)
        ans=0
        for i in range(n):
            lm[i]+=1
            rm[i]-=1
            ans=max(ans,heights[i]*(rm[i]-lm[i]+1))
        return ans