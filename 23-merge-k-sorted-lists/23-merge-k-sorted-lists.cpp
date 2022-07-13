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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        for(auto i:lists){
            if(i) pq.push({i->val,i});
        }
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(!pq.empty()){
            pair<int,ListNode*> curr=pq.top();
            pq.pop();
            if(!head){ head=curr.second;temp=curr.second;}
            else{ temp->next=curr.second; temp=temp->next;}
            if(curr.second->next) pq.push({curr.second->next->val,curr.second->next});
        }
        return head;
    }
};