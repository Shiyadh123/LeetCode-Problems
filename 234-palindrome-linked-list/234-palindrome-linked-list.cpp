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
ListNode* reverse(ListNode* node){
    ListNode* prev=NULL;
    while(node){
        ListNode* nxt=node->next;
        node->next=prev;
        prev=node; node=nxt;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow);
        fast=head;
        while(slow&&fast){
            if(slow->val!=fast->val) return false;
            slow=slow->next; fast=fast->next;
        }
        return true;
    }
};