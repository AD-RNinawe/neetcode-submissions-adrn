class Solution:
    def dailyTemperatures(self, temps: List[int]) -> List[int]:
        res=[0]*len(temps)
        st=[]
        for i,t in enumerate(temps):
            while st and t>st[-1][0]:
                tmp,idx=st.pop()
                res[idx]=i-idx
            st.append((t,i))
        return res