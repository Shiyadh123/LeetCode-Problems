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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head=NULL,*temp=NULL,*p=list1,*q=list2;
        while(p&&q){
            if(p->val<q->val){
                if(!head) head=p;
                if(!temp) temp=p;
                else {
                    temp->next=p; temp=temp->next;
                }
                p=p->next;
            }else{
                if(!head) head=q;
                if(!temp) temp=q;
                else {
                    temp->next=q; temp=temp->next;
                }
                q=q->next;
            }
        }
        if(!p){
            temp->next=q;
        }else{
            temp->next=p;
        }
        return head;
    }
    ListNode* divide(vector<ListNode*>& lists,int l,int r){
        if(l>=r) return lists[l];
        int m=(l+r)/2;
        ListNode* left=divide(lists,l,m);
        ListNode* right=divide(lists,m+1,r);
        return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return divide(lists,0,lists.size()-1);
    }
};