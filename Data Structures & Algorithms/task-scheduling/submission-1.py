class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt=[0]*26
        for t in tasks:
            cnt[ord(t)-ord('A')]+=1
        maxf=max(cnt)
        maxc=0
        for i in cnt:
            if i==maxf:
                maxc+=1
        time=(maxf-1)*(n+1)+maxc
        return max(len(tasks),time)