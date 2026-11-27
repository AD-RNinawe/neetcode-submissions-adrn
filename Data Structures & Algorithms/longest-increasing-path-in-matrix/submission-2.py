class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows,cols=len(matrix),len(matrix[0])
        dirs=[[-1,0],[1,0],[0,1],[0,-1]]
        indeg=[[0]*cols for _ in range(rows)]
        for r in range(rows):
            for c in range(cols):
                for d in dirs:
                    nr,nc=d[0]+r,d[1]+c
                    if (0<=nr<rows and 0<=nc<cols and matrix[nr][nc]<matrix[r][c]):
                        indeg[r][c]+=1
        q=deque()
        for r in range(rows):
            for c in range(cols):
                if indeg[r][c]==0:
                    q.append([r,c])
        LIS=0
        while q:
            for _ in range(len(q)):
                r,c=q.popleft()
                for d in dirs:
                    nr,nc=r+d[0],c+d[1]
                    if (0<=nr<rows and 0<=nc<cols and matrix[nr][nc]>matrix[r][c]):
                        indeg[nr][nc]-=1
                        if indeg[nr][nc]==0:
                            q.append([nr,nc])
            LIS+=1
        return LIS