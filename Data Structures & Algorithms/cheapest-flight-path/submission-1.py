class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        inf=float("inf")
        adj=[[] for _ in range(n)]
        dist=[[inf]*(k+5) for _ in range(n)]
        for u,v,cst in flights:
            adj[u].append([v,cst])
        dist[src][0]=0
        minh=[(0,src,-1)]
        while len(minh):
            cst,node,stops=heapq.heappop(minh)
            if dst==node:
                return cst
            if stops==k or dist[node][stops+1]<cst:
                continue
            for nbr,w in adj[node]:
                nextcst=cst+w
                nextstops=stops+1
                if dist[nbr][nextstops+1]>nextcst:
                    dist[nbr][nextstops+1]=nextcst
                    heapq.heappush(minh,(nextcst,nbr,nextstops))
        return -1