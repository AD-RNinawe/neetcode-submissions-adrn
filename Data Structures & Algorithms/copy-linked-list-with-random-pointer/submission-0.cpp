/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;
        copy[NULL]=NULL;
        Node* curr=head;
        while (curr!=NULL){
            Node* duplicate=new Node(curr->val);
            copy[curr]=duplicate;
            curr=curr->next;
        }
        curr=head;
        while (curr!=NULL){
            Node* duplicate=copy[curr];
            duplicate->next=copy[curr->next];
            duplicate->random=copy[curr->random];
            curr=curr->next;
        }
        return copy[head];
    }
};
