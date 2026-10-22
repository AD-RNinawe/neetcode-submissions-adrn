class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows,cols=len(grid),len(grid[0])
        fresh=0
        time=0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==1:
                    fresh+=1
        directions=[[1,0],[-1,0],[0,1],[0,-1]]
        while fresh>0:
            flag=False
            for r in range(rows):
                for c in range(cols):
                    if grid[r][c]==2:
                        for dr,dc in directions:
                            row,col=r+dr,c+dc
                            if row in range(rows) and col in range(cols) and grid[row][col]==1:
                                grid[row][col]=3
                                fresh-=1
                                flag=True
            if not flag:
                return -1
            for r in range(rows):
                for c in range(cols):
                    if grid[r][c]==3:
                        grid[r][c]=2
            time+=1
        return time