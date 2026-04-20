class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> heap;
        for (int stone: stones){
            heap.push(stone);
        }
        while (heap.size()>1){
            int x=heap.top();
            heap.pop();
            int y=heap.top();
            heap.pop();
            if (x!=y){
                heap.push(abs(x-y));
            }
        }
        if (heap.size()==1){
            return heap.top();
        } else {return 0;}
    }
};
