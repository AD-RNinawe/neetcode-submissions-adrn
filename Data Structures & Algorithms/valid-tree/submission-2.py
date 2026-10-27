class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)!=(n-1):
            return False
        adj=[[] for _ in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        vis=set()
        def dfs(node,par):
            if node in vis:
                return False
            vis.add(node)
            for nbr in adj[node]:
                if nbr==par:
                    continue
                if not dfs(nbr,node):
                    return False
            return True
        return dfs(0,-1) and len(vis)==n