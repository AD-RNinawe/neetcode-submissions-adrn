class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool endofword=false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char c: word){
            if(curr->children.find(c)==curr->children.end()){
                curr->children[c]=new TrieNode();
            }
            curr=curr->children[c];
        }
        curr->endofword=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->children.find(c)==curr->children.end()){
                return false;
            }
            curr=curr->children[c];
        }
        return curr->endofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char c: prefix){
            if(curr->children.find(c)==curr->children.end()){
                return false;
            }
            curr=curr->children[c];
        }
        return true;
    }
};
