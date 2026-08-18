class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l=0
        ans=0
        seen=set()
        for i in range(len(s)):
            if s[i] in seen:
                ans=max(ans,i-l)
                while s[i] in seen:
                    seen.discard(s[l])
                    l+=1
            seen.add(s[i])
        ans=max(ans,len(s)-l)
        return ans
