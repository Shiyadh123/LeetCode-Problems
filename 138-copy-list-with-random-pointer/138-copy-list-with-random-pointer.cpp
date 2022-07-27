class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummyHead=new Node(-1,NULL,NULL);
        Node* temp=dummyHead;
        Node* curr=head;
        unordered_map<Node*,Node*> address;
        while(curr){
            Node* newNode=new Node(curr->val,curr->next,NULL);
            temp->next=newNode;
            temp=temp->next; 
            address[curr]=temp;
            curr=curr->next;
        }
        curr=head;
        temp=dummyHead->next;
        while(curr){
            if(!curr->random) temp->random=NULL;
            else temp->random=address[curr->random];
            temp=temp->next; curr=curr->next;
        }
        return dummyHead->next;
    }
};