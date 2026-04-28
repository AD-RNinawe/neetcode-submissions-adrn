class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=(nums1.size()+nums2.size()+1)/2;
        int r=(nums1.size()+nums2.size()+2)/2;
        return (get(nums1, nums1.size(),nums2, nums2.size(),l,0,0)+get(nums1,nums1.size(),nums2,nums2.size(),r,0,0))/2.0;
    }
    int get(vector<int>& a, int m, vector<int>& b, int n, int k, int sta, int stb){
        if(m>n){
            return get(b,n,a,m,k,stb,sta);
        }
        if(m==0){
            return b[stb+k-1];
        }
        if(k==1){
            return min(a[sta],b[stb]);
        }
        int i=min(m,k/2);
        int j=min(n,k/2);
        if(a[sta+i-1]>b[stb+j-1]){
            return get(a,m,b,n-j,k-j,sta,stb+j);
        } else{
            return get(a,m-i,b,n,k-i,sta+i,stb);
        }
    }
};
