class Trienode{
public:
    Trienode* children[26];
    int idx;
    int refs;

    Trienode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        idx=-1;
        refs=0;
    }

    void addword(const string& word, int i){
        Trienode* cur=this;
        cur->refs++;
        for (char c: word){
            int idx=c-'a';
            if(!cur->children[idx]){
                cur->children[idx]=new Trienode();
            }
            cur=cur->children[idx];
            cur->refs++;
        }
        cur->idx=i;
    }
};

class Solution {
public:
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trienode* root = new Trienode();
        for(int i=0;i<words.size();i++){
            root->addword(words[i],i);
        }
        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                dfs(board,root,r,c,words);
            }
        }
        return res;
    }
    void dfs(auto& board, Trienode* node, int r, int c, auto& words){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='*'|| !node->children[board[r][c]-'a']){
            return;
        }
        char tmp=board[r][c];
        board[r][c]='*';
        Trienode* prev=node;
        node=node->children[tmp-'a'];
        if(node->idx!=-1){
            res.push_back(words[node->idx]);
            node->idx=-1;
            node->refs--;
            if(!node->refs){
                prev->children[tmp-'a']=nullptr;
                node=nullptr;
                board[r][c]=tmp;
                return;
            }
        }
        dfs(board, node, r + 1, c, words);
        dfs(board, node, r - 1, c, words);
        dfs(board, node, r, c + 1, words);
        dfs(board, node, r, c - 1, words);
        board[r][c]=tmp;
    }
};
