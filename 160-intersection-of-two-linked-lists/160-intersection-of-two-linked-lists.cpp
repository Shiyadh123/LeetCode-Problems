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
        int l1=0,l2=0;
        ListNode *t1=headA;
        ListNode *t2=headB;
        ListNode *u1=headA;
        ListNode *u2=headB;
        while(u1!=NULL) {
            l1++;
            u1=u1->next;
        }
        while(u2!=NULL) {
            l2++;
            u2=u2->next;
        }
        if(l1>l2){
            int k=l1-l2;
            while(k--){
                t1=t1->next;
            }
        }
        else if(l2>l1){
            int k=l2-l1;
            while(k--){
                t2=t2->next;
            }
        }
        while(t1!=NULL&&t2!=NULL){
            if(t1==t2) return t1;
            t1=t1->next;
            t2=t2->next;
        }
        return NULL;
    }
};
