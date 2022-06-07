class TextEditor {
public:
    string pre,post;
    TextEditor() {
        pre="";
        post="";
    }
    
    void addText(string text) {
        pre+=text;
    }
    
    int deleteText(int k) {
        int delCnt=min((int)pre.length(),k);
        for(int i=0;i<delCnt;i++){
            pre.pop_back();
        }
        return delCnt;
    }
    
    string cursorLeft(int k) {
        while(k--&&pre.length()){
            char tmp=pre.back();
            pre.pop_back();
            post.push_back(tmp);
        }
        return pre.substr(pre.length()-min(10,(int)pre.length()));
    }
    
    string cursorRight(int k) {
        while(k--&&post.length()){
            char tmp=post.back();
            post.pop_back();
            pre.push_back(tmp);
        }
        return pre.substr(pre.length()-min(10,(int)pre.length()));
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */