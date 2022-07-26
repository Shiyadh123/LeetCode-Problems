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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy =new ListNode(-1,head);
        ListNode* fst=dummy,*sec=head;
        int lastRemoved=-1000;
        while(sec){
            if(sec->val==lastRemoved||(sec->next&&sec->val==sec->next->val)){
                lastRemoved=sec->val;
                fst->next=sec->next;
                sec=sec->next;
            }else{
                fst=fst->next;
                sec=sec->next;
            }
        }
        return dummy->next;
    }
};