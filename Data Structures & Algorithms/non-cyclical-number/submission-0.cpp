class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while(vis.find(n)==vis.end()){
            vis.insert(n);
            n=sumofsq(n);
            if(n==1) return true;
        }
        return false;
    }
    int sumofsq(int n){
        int res=0;
        while(n>0){
            int dig=n%10;
            dig=dig*dig;
            res+=dig;
            n/=10;
        }
        return res;
    }
};
