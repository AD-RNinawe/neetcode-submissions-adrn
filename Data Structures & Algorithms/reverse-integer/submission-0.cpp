class Solution {
public:
    int reverse(int x) {
        const int mn=-2147483648;
        const int mx=2147483647;
        int res=0;
        while(x!=0){
            int dig=x%10;
            x/=10;
            if(res>mx/10 || (res==mx/10 && dig>mx%10)) return 0;
            if(res<mn/10 || (res==mn/10 && dig<mn%10)) return 0;
            res=(res*10)+dig;
        }
        return res;
    }
};
