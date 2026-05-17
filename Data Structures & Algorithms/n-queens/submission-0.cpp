class Solution {
public:
    vector<string> board;
    vector<bool> col,posd,negd;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n,false);
        posd.resize(2*n,false);
        negd.resize(2*n,false);
        board.resize(n,string(n,'.'));
        backtrack(0,n);
        return res;
    }
    void backtrack(int r, int n){
        if(r==n){
            res.push_back(board);
        }
        for(int c=0;c<n;c++){
            if(col[c]||posd[r+c]||negd[r-c+n]){
                continue;
            }
            col[c]=true;
            posd[r+c]=true;
            negd[r-c+n]=true;
            board[r][c]='Q';
            backtrack(r+1,n);
            col[c]=false;
            posd[r+c]=false;
            negd[r-c+n]=false;
            board[r][c]='.';
        }
    }
};
