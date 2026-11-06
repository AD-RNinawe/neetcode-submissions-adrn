class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n=len(grid)
        vis=set()
        minh=[[grid[0][0],0,0]]
        dirs=[[0,1],[0,-1],[1,0],[-1,0]]
        vis.add((0,0))
        while minh:
            t,r,c=heapq.heappop(minh)
            if r==n-1 and c==n-1:
                return t
            for dr,dc in dirs:
                nbrr,nbrc=r+dr,c+dc
                if nbrr<0 or nbrc<0 or nbrr==n or nbrc==n or (nbrr,nbrc) in vis:
                    continue
                vis.add((nbrr,nbrc))
                heapq.heappush(minh,[max(t,grid[nbrr][nbrc]),nbrr,nbrc])
                