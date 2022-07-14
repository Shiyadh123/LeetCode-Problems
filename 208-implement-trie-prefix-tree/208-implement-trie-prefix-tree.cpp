struct node{
    bool end=false;
    node* links[26]={NULL};
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putNode(char ch,node* newNode){
        links[ch-'a']=newNode;
    }

    node* getNode(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        end=true;
    }

    bool isEnd(){
        return end;
    }
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
            if(!temp->containsKey(word[i])){
                temp->putNode(word[i],new node());
            }
            temp=temp->getNode(word[i]);
        }
        temp->setEnd();
        return;
    }
    
    bool search(string word) {
        int l=word.length();
        node* temp=root;
        for(int i=0;i<l;i++){
             if(!temp->containsKey(word[i])) return false;
             temp=temp->getNode(word[i]);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
       int l=prefix.length();
        node* temp=root;
        for(int i=0;i<l;i++){
             if(!temp->containsKey(prefix[i])) return false;
             temp=temp->getNode(prefix[i]);
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