class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int kmin=1;
        int kmax= *max_element(piles.begin(),piles.end());
        int ans=kmax;
        while (kmin<=kmax){
            int candidate=(kmin+kmax)/2;
            int time=0;
            for (int p:piles){
                time+=(p+candidate-1)/candidate;
            }
            if (time<=h){
                ans=candidate;
                kmax=candidate-1;
            } else {
                kmin=candidate+1;
            }
        }
        return ans;
    }
};
