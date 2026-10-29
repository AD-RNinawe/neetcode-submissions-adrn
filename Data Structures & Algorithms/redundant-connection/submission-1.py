class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n=len(edges)
        adj=[[] for _ in range(n+1)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        vis=[False]*(n+1)
        cycle=set()
        cyclest=-1
        def dfs(node,par):
            nonlocal cyclest
            if vis[node]:
                cyclest=node
                return True
            vis[node]=True
            for nbr in adj[node]:
                if nbr==par:
                    continue
                if dfs(nbr,node):
                    if cyclest!=-1:
                        cycle.add(node)
                    if node==cyclest:
                        cyclest=-1
                    return True
            return False
        dfs(1,-1)
        for u,v in reversed(edges):
            if u in cycle and v in cycle:
                return [u,v]
        return []   
        