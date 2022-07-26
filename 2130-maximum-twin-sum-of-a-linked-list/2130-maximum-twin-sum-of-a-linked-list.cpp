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
    int pairSum(ListNode* head) {
        int ans=INT_MIN;
        ListNode* fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow);
        fast=head;
        while(slow&&fast){
            ans=max(ans,slow->val+fast->val);
            slow=slow->next; fast=fast->next;
        }
        return ans;
    }
};