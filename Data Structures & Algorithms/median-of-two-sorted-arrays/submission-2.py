class Solution:
    def getkth(self,a,m,b,n,k,a_s: int=0,b_s: int=0):
        if m>n:
            return self.getkth(b,n,a,m,k,b_s,a_s)
        if m==0:
            return b[b_s+k-1]
        if k==1:
            return min(a[a_s],b[b_s])
        i=min(m,k//2)
        j=min(n,k//2)
        if a[a_s+i-1]>b[b_s+j-1]:
            return self.getkth(a,m,b,n-j,k-j,a_s,b_s+j)
        else:
            return self.getkth(a,m-i,b,n,k-i,a_s+i,b_s)
    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l=(len(nums1)+len(nums2)+1)//2
        r=(len(nums1)+len(nums2)+2)//2
        return (self.getkth(nums1, len(nums1), nums2, len(nums2), l) +
                self.getkth(nums1, len(nums1), nums2, len(nums2), r)) / 2.0
        