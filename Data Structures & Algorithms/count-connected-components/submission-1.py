class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj=[[] for _ in range(n)]
        vis=[False]*n
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        def dfs(node):
            for nbr in adj[node]:
                if not vis[nbr]:
                    vis[nbr]=True
                    dfs(nbr)
        res=0
        for i in range(n):
            if not vis[i]:
                vis[i]=True
                dfs(i)
                res+=1
        return res