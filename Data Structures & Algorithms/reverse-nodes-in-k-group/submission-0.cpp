/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int grp=0;
        while(curr!=nullptr && grp<k){
            curr=curr->next;
            grp++;
        }
        if (grp==k){
            curr=reverseKGroup(curr,k);
            while (grp-->0){
                ListNode* tmp=head->next;
                head->next=curr;
                curr=head;
                head=tmp;
            }
            head=curr;
        }
        return head;
    }
};
