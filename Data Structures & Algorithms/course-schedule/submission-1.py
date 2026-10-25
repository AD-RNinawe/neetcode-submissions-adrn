class Solution:
    def canFinish(self, n: int, prereqs: List[List[int]]) -> bool:
        indeg=[0]*n
        adj=[[] for i in range(n)]
        for src,dst in prereqs:
            indeg[dst]+=1
            adj[src].append(dst)
        q=deque()
        for i in range(n):
            if indeg[i]==0:
                q.append(i)
        fin=0
        while q:
            node=q.popleft()
            fin+=1
            for nei in adj[node]:
                indeg[nei]-=1
                if indeg[nei]==0:
                    q.append(nei)
        return fin==n