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
    ListNode* fun(ListNode* curr,int &cnt,int n){
        if(!curr) return NULL;
        ListNode* nxt=fun(curr->next,cnt,n);
        curr->next=nxt;
        cnt++;
        if(cnt==n) return nxt;
        else return curr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        return fun(head,c,n);
    }
};