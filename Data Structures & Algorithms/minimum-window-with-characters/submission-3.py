class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t:
            return ""
        tcnt={}
        for i in range(len(t)):
            if t[i] in tcnt:
                tcnt[t[i]]+=1
            else:
                tcnt[t[i]]=1
        win={}
        have,need=0,len(tcnt)
        res,resl=[-1,-1],float("infinity")
        l=0
        for r in range(len(s)):
            c=s[r]
            win[c]=1+win.get(c,0)
            if c in tcnt and win[c]==tcnt[c]:
                have+=1
            while have==need:
                if (r-l+1)<resl:
                    res=[l,r]
                    resl=r-l+1
                win[s[l]]-=1
                if s[l] in tcnt and win[s[l]]<tcnt[s[l]]:
                    have-=1
                l+=1
        l,r=res
        return s[l:r+1] if resl!=float("infinity") else ""