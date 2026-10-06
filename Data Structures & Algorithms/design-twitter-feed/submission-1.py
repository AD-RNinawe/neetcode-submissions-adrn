class Twitter:

    def __init__(self):
        self.cnt=0
        self.tweetmap=defaultdict(list)
        self.followmap=defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetmap[userId].append([self.cnt,tweetId])
        if len(self.tweetmap[userId])>10:
            self.tweetmap[userId].pop(0)
        self.cnt-=1

    def getNewsFeed(self, userId: int) -> List[int]:
        res=[]
        minheap=[]
        self.followmap[userId].add(userId)
        if len(self.followmap[userId])>=10:
            maxheap=[]
            for followeeId in self.followmap[userId]:
                if followeeId in self.tweetmap:
                    idx=len(self.tweetmap[followeeId])-1
                    cnt,tweetId=self.tweetmap[followeeId][idx]
                    heapq.heappush(maxheap,[-cnt,tweetId,followeeId,idx-1])
                    if len(maxheap)>10:
                        heapq.heappop(maxheap)
            while maxheap:
                cnt,tweetId,followeeId,idx=heapq.heappop(maxheap)
                heapq.heappush(minheap,[-cnt,tweetId,followeeId,idx])
        else:
            for followeeId in self.followmap[userId]:
                if followeeId in self.tweetmap:
                    idx=len(self.tweetmap[followeeId])-1
                    cnt,tweetId=self.tweetmap[followeeId][idx]
                    heapq.heappush(minheap,[cnt,tweetId,followeeId,idx-1])
        while minheap and len(res)<10:
            cnt,tweetId,followeeId,idx=heapq.heappop(minheap)
            res.append(tweetId)
            if idx>=0:
                cnt,tweetId=self.tweetmap[followeeId][idx]
                heapq.heappush(minheap,[cnt,tweetId,followeeId,idx-1])
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followmap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followmap[followerId]:
            self.followmap[followerId].remove(followeeId)
