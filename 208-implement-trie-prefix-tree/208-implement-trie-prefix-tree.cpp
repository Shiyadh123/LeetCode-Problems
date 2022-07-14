struct node{
    bool end=false;
    node* next[26]={NULL};
};
class Trie {
private:
    node* root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        int l=word.length();
        node* temp=root;
        for(int i=0;i<l;i++){
            if(temp->next[word[i]-'a']){
                temp=temp->next[word[i]-'a'];
            }else{
                node* newNode=new node();
                temp->next[word[i]-'a']=newNode;
                temp=temp->next[word[i]-'a'];
            }
            if(i==l-1){
                temp->end=true;
            }
        }
        return;
    }
    
    bool search(string word) {
        int l=word.length();
        node* temp=root;
        for(int i=0;i<l;i++){
            if(temp->next[word[i]-'a']==NULL) return false;
            temp=temp->next[word[i]-'a'];
            if(i==l-1){
                return temp->end==true;
            }
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        int l=prefix.length();
        node* temp=root;
        for(int i=0;i<l;i++){
            if(temp->next[prefix[i]-'a']==NULL) return false;
            temp=temp->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */