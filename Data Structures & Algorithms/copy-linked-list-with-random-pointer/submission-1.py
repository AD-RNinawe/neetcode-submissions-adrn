"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        otc=collections.defaultdict(lambda:Node(0))
        otc[None]=None
        curr=head
        while curr:
            otc[curr].val=curr.val
            otc[curr].next=otc[curr.next]
            otc[curr].random=otc[curr.random]
            curr=curr.next
        return otc[head]
        