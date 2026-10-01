class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.mheap,self.k=nums,k
        heapq.heapify(self.mheap)
        while len(self.mheap)>k:
            heapq.heappop(self.mheap)

    def add(self, val: int) -> int:
        heapq.heappush(self.mheap,val)
        if len(self.mheap)>self.k:
            heapq.heappop(self.mheap)
        return self.mheap[0]
