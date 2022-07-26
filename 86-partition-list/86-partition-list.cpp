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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* current=dummy;
        ListNode* newHead=new ListNode();
        ListNode* tail=newHead;
        while(current->next){
            if(current->next->val<x){
                tail->next=current->next;
                current->next=current->next->next;
                tail=tail->next;
            }else{
                current=current->next;
            }
        }
        tail->next=dummy->next;
        return newHead->next;
    }
};