class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        st=[]
        res=[]
        def bt(op,cl):
            if op==cl==n:
                res.append("".join(st))
                return
            if op<n:
                st.append("(")
                bt(op+1,cl)
                st.pop()
            if cl<op:
                st.append(")")
                bt(op,cl+1)
                st.pop()
        bt(0,0)
        return res