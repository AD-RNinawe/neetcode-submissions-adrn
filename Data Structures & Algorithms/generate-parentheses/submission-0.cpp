class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(0,0,n,res,s);
        return res;
    }
    void backtrack(int op,int cl, int n, vector<string>& res,string& s){
        if (op==cl && op==n){
            res.push_back(s);
            return;
        }
        if(cl>op)return;
        if(op<n){
            s+='(';
            backtrack(op+1,cl,n,res,s);
            s.pop_back();
        }
        if(cl<n){
            s+=')';
            backtrack(op,cl+1,n,res,s);
            s.pop_back();
        }
    }
};
