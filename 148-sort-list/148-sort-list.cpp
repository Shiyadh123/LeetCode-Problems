class Solution {
public:
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* newHead=new ListNode(0,NULL);
        ListNode* temp=newHead;
        while(head1&&head2){
            if(head1->val<head2->val){
                temp->next=head1;
                head1=head1->next;
            }else{
                temp->next=head2;
                head2=head2->next;
            }
            temp=temp->next;
        }
        if(head1){
            temp->next=head1;
        }
        if(head2){
            temp->next=head2;
        }
        return newHead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* fast=head,*slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* secHead=slow->next;
        slow->next=NULL;
        head=sortList(head);
        secHead=sortList(secHead);
        return merge(head,secHead);
    }
};
