class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lr=0; int rr=matrix.size()-1;
        int midr=(lr+rr)/2;
        while (lr<=rr){
            midr=(lr+rr)/2;
            if (matrix[midr][0]==target or matrix[midr].back()==target){return true;}
            else if (matrix[midr][0]>target){rr=midr-1;}
            else if (matrix[midr].back()<target){lr=midr+1;}
            else {
                int lc=0; int rc=matrix[0].size()-1;
                while (lc<=rc){
                    int midc=(lc+rc)/2;
                    if (matrix[midr][midc]==target){return true;}
                    else if (matrix[midr][midc]<target){lc=midc+1;}
                    else {rc=midc-1;}
                }
                return false;
            }
        }
        return false;
    }
};
