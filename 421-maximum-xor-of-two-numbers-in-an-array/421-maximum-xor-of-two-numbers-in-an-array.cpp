struct node{
    node* links[2]={NULL};
    bool containsKey(int bit){
        return links[bit];
    }
    void putNode(int bit,node* nn){
        links[bit]=nn;
    }
    node* getNode(int bit){
        return links[bit];
    }
};
class Trie{
    public:
        node* root;
    Trie(){
        root=new node();
    }
    void insert(int n){
        node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(n&(1<<i))>0?1:0;
            if(!curr->containsKey(bit)){
                curr->putNode(bit,new node());
            }
            curr=curr->getNode(bit);
        }
    }
    int findXor(int n){
        int ans=0;
        node* curr=root;
        for(int i=31;i>=0;i--){
            int currBit=((n&(1<<i))==0?0:1);
            int reqBit=abs(currBit-1);
            if(curr->containsKey(reqBit)) {
                ans=ans|(1<<i);
                curr=curr->getNode(reqBit);
            }else{
                curr=curr->getNode(currBit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj=new Trie();
        for(auto i:nums) obj->insert(i);
        int ans=0;
        for(auto i:nums){
            ans=max(ans,obj->findXor(i));
        }
        return ans;
    }
};