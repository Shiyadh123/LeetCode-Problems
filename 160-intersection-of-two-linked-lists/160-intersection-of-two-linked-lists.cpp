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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        while(headA!=NULL) {
            st1.push(headA);
            headA=headA->next;
        }
        while(headB!=NULL) {
            st2.push(headB);
            headB=headB->next;
        }
        ListNode * tmp;
        while(!st1.empty()&&!st2.empty()){
            if(st1.top()!=st2.top()) return st1.top()->next;
            tmp=st1.top();
            st2.pop();
            st1.pop();
        }
        if(st1.empty()) return tmp;
        if(st2.empty()) return tmp;
        return NULL;
    }
};
