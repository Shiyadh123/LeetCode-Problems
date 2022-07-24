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
    ListNode* fun(ListNode* curr){
        if(!curr||!(curr->next)) return curr;
        ListNode* newHead=fun(curr->next);
        curr->next->next=curr;
        curr->next=NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return fun(head);
    }
};