class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& words) {
        if (endword.empty() || find(words.begin(),words.end(),endword)==words.end()){
            return 0;
        }
        unordered_map<string,vector<string>> nei;
        words.push_back(beginword);
        for(const string&word:words){
            for(int j=0;j<word.size();j++){
                string pat=word.substr(0,j)+"*"+word.substr(j+1);
                nei[pat].push_back(word);
            }
        }
        unordered_set<string> vis{beginword};
        queue<string> q;
        q.push(beginword);
        int res=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word=q.front();q.pop();
                if(word==endword) return res;
                for(int j=0;j<word.size();j++){
                    string pat=word.substr(0,j)+"*"+word.substr(j+1);
                    for(const string& neiword: nei[pat]){
                        if(vis.find(neiword)==vis.end()){
                            vis.insert(neiword);
                            q.push(neiword);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
