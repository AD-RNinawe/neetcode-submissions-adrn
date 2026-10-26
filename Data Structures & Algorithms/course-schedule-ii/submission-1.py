class Solution:
    def findOrder(self, n: int, prereqs: List[List[int]]) -> List[int]:
        indeg=[0]*n
        adj=[[] for i in range(n)]
        for src,dst in prereqs:
            indeg[dst]+=1
            adj[src].append(dst)
        q=deque()
        for i in range(n):
            if indeg[i]==0:
                q.append(i)
        fin,out=0,[]
        while q:
            node=q.popleft()
            out.append(node)
            fin+=1
            for nbr in adj[node]:
                indeg[nbr]-=1
                if indeg[nbr]==0:
                    q.append(nbr)
        if fin!=n:
            return []
        return out[::-1]
        