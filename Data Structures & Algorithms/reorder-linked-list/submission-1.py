# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        s,f=head,head.next
        while f and f.next:
            s=s.next
            f=f.next.next
        sec=s.next
        prev=s.next=None
        while sec:
            tmp=sec.next
            sec.next=prev
            prev=sec
            sec=tmp
        first,second=head,prev
        while second:
            tmp1,tmp2=first.next,second.next
            first.next=second
            second.next=tmp1
            first,second=tmp1,tmp2