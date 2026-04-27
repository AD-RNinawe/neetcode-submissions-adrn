class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> l(n,-1);
        vector<int> r(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            } if(!st.empty()){
                l[i]=st.top();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                r[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            l[i]+=1;
            r[i]-=1;
            ans=max(ans,heights[i]*(r[i]-l[i]+1));
        }
        return ans;
    }
};
