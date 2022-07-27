class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* curr=head;
        while(curr){
            Node* newNode=new Node(curr->val,curr->next,NULL);
            curr->next=newNode;
            curr=curr->next->next;
        }
        curr=head;
        while(curr){
            if(!curr->random) curr->next->random=NULL;
            else curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        Node* newHead=head->next;
        Node* temp=newHead;
        curr=head;
        while(curr){
            curr->next=curr->next->next;
            curr=curr->next;
            temp->next=temp->next?temp->next->next:NULL;
            temp=temp->next;
        }
        return newHead;
    }
};