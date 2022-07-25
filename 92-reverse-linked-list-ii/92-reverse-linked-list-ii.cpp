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
    ListNode* reverse(ListNode* start,ListNode* end){
        ListNode* tail=end->next;
        ListNode* prev=tail,* curr=start;
        while(curr!=tail){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy =new ListNode();
        dummy->next=head;
        ListNode* temp=dummy;
        ListNode* leftNode=NULL,* rightNode=NULL;
        int i=0;
        while(temp){
            if(i==left-1) leftNode=temp;
            if(i==right) rightNode=temp;
            temp=temp->next;
            i++;
        }
        // if(!leftNode||!rightNode) return  dummy->next;
        leftNode->next=reverse(leftNode->next,rightNode);
        return dummy->next;
    }
};