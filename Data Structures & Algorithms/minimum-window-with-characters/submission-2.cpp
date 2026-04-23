class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int> count,window;
        for(char c:t){
            count[c]++;
        }
        int have=0, need=count.size();
        pair<int,int> res={-1,-1};
        int reslen=INT_MAX;
        int l=0;
        for(int r=0;r<s.length();r++){
            char c=s[r];
            window[c]++;
            if (count.count(c) && window[c]==count[c]){
                have++;
            }
            while (have==need){
                if ((r-l+1)<reslen){
                reslen=r-l+1;
                res={l,r};
                }
                window[s[l]]--;
                if (count.count(s[l]) && window[s[l]]<count[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return reslen==INT_MAX ? "" : s.substr(res.first,reslen);
    }
};
