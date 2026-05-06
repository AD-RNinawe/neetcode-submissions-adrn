class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for (char task: tasks){
            count[task-'A']++;
        }
        priority_queue<int> heap;
        for(int cnt: count){
            if(cnt>0){
                heap.push(cnt);
            }
        }
        int time=0;
        queue<pair<int,int>> q;
        while(!heap.empty() || !q.empty()){
            time++;
            if(heap.empty()){
                time=q.front().second;
            }else{
                int cnt=heap.top()-1;
                heap.pop();
                if(cnt>0){
                    q.push({cnt,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
