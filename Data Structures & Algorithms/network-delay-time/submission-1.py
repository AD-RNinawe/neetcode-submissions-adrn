class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges=collections.defaultdict(list)
        for u,v,w in times:
            edges[u].append((v,w))
        mheap=[(0,k)]
        vis=set()
        t=0
        while mheap:
            w1,n1=heapq.heappop(mheap)
            if n1 in vis:
                continue
            vis.add(n1)
            t=w1
            for n2,w2 in edges[n1]:
                if n2 not in vis:
                    heapq.heappush(mheap,(w1+w2,n2))
        return t if len(vis)==n else -1

        