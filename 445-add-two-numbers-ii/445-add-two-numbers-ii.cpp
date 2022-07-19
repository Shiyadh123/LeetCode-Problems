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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1,st2;
        ListNode* nxtNode=NULL, *currNode;
        ListNode* temp=l1;
        while(temp){
            st1.push(temp);
            temp=temp->next;
        }
        temp=l2;
        while(temp){
            st2.push(temp);
            temp=temp->next;
        }
        int rem=0;
        while(!st1.empty()||!st2.empty()){
            int a=0,b=0;
            if(!st1.empty()) { a=st1.top()->val; st1.pop(); }
            if(!st2.empty()) { b=st2.top()->val; st2.pop(); }
            int quo=(a+b+rem)%10;
            currNode=new ListNode(quo);
            currNode->next=nxtNode;
            nxtNode=currNode;
            rem=(a+b+rem)/10;
        }
        if(rem){
            currNode=new ListNode(rem);
            currNode->next=nxtNode;
        }
        return currNode;
    }
};