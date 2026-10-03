class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        hp=[]
        for x,y in points:
            dist=-(x**2+y**2)
            heapq.heappush(hp,[dist,x,y])
            if len(hp)>k:
                heapq.heappop(hp)
        res=[]
        while hp:
            dist,x,y=heapq.heappop(hp)
            res.append([x,y])
        return res