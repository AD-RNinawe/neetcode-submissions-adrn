class Solution:
    def ladderLength(self, beginword: str, endword: str, wordlist: List[str]) -> int:
        if endword not in wordlist or beginword==endword:
            return 0
        n,m=len(wordlist),len(wordlist[0])
        adj=[[] for _ in range(n)]
        mp={}
        for i in range(n):
            mp[wordlist[i]]=i
        for i in range(n):
            for j in range(i+1,n):
                cnt=0
                for k in range(m):
                    if wordlist[i][k]!=wordlist[j][k]:
                        cnt+=1
                if cnt==1:
                    adj[i].append(j)
                    adj[j].append(i)
        q,res=deque(),1
        vis=set()
        for i in range(m):
            for c in range(97,123):
                if chr(c)==beginword[i]:
                    continue
                word=beginword[:i]+chr(c)+beginword[i+1:]
                if word in mp and mp[word] not in vis:
                    q.append(mp[word])
                    vis.add(mp[word])
        while q:
            res+=1
            for i in range(len(q)):
                node=q.popleft()
                if wordlist[node]==endword:
                    return res
                for nbr in adj[node]:
                    if nbr not in vis:
                        vis.add(nbr)
                        q.append(nbr)
        return 0