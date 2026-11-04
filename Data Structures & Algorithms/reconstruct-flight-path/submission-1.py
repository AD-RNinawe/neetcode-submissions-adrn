class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj=defaultdict(list)
        for s,d in sorted(tickets)[::-1]:
            adj[s].append(d)
        st=["JFK"]
        res=[]
        while st:
            cur=st[-1]
            if not adj[cur]:
                res.append(st.pop())
            else:
                st.append(adj[cur].pop())
        return res[::-1]