class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows,cols=len(grid),len(grid[0])
        vis=set()
        q=deque()
        
        def addcell(r,c):
            if min(r,c)<0 or r==rows or c==cols or (r,c) in vis or grid[r][c]==-1:
                return
            vis.add((r,c))
            q.append([r,c])
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==0:
                    q.append([r,c])
                    vis.add((r,c))
        dist=0
        while q:
            for i in range(len(q)):
                r,c=q.popleft()
                grid[r][c]=dist
                addcell(r+1,c)
                addcell(r-1,c)
                addcell(r,c+1)
                addcell(r,c-1)
            dist+=1