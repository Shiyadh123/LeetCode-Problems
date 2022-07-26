/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast=head,*slow=head;
        while(1){
            if(!fast||!fast->next) return NULL;
            else {
                fast=fast->next->next;
                slow=slow->next;
            }
            if(fast==slow) break;
        }
        fast=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};