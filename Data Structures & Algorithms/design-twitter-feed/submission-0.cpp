class Twitter {
public:
    int count;
    unordered_map<int, vector<pair<int,int>>> tweetmp;
    unordered_map<int, unordered_set<int>> followmp;

    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmp[userId].push_back({count,tweetId});
        if(tweetmp[userId].size()>10){
            tweetmp[userId].erase(tweetmp[userId].begin());
        }
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followmp[userId].insert(userId);
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> mheap;
        if(followmp[userId].size()>=10){
            priority_queue<vector<int>> heap;
            for (auto f: followmp[userId]){
                if(!tweetmp.count(f)) continue;
                int idx=tweetmp[f].size()-1;
                auto &p=tweetmp[f][idx];
                heap.push({-p.first,p.second,idx-1});
                if(heap.size()>10) heap.pop();
            }
            while (!heap.empty()){
                auto t=heap.top();
                heap.pop();
                mheap.push({-t[0],t[1],t[2],t[3]});
            }
        } else {
            for (auto f : followmp[userId]) {
                if (!tweetmp.count(f)) continue;
                int idx = tweetmp[f].size() - 1;
                auto &p = tweetmp[f][idx];
                mheap.push({p.first, p.second, f, idx - 1});
            }
        }
        while (!mheap.empty() && res.size() < 10) {
            auto t = mheap.top();
            mheap.pop();
            res.push_back(t[1]);
            int idx = t[3];
            if (idx >= 0) {
                auto &p = tweetmp[t[2]][idx];
                mheap.push({p.first, p.second, t[2], idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followmp[followerId].count(followeeId)) {
            followmp[followerId].erase(followeeId);
        }
    }
};
