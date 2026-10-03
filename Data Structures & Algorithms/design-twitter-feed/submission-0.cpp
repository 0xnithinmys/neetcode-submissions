class Twitter {
   public:
    unordered_map<int, vector<vector<int>>> u;
    priority_queue<tuple<int, int, int>> pq;

    Twitter() {}
    int x = 0;

    void postTweet(int userId, int tweetId) {
       if (u[userId].empty()) {
    u[userId].push_back(vector<int>());
    u[userId].push_back(vector<int>());
}

        pq.push({x, userId, tweetId});
        x++;

        u[userId][0].push_back(tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        queue<tuple<int, int, int>> q;

        while (!pq.empty() && v.size() < 10) {
            auto i = pq.top();

            if (get<1>(i) == userId) {
    v.push_back(get<2>(i));
}
else {
    for (int k = 0; k < u[userId][1].size(); k++) {
        if (u[userId][1][k] == get<1>(i)) {
            v.push_back(get<2>(i));
            break;
        }
    }
}

            q.push({get<0>(i), get<1>(i), get<2>(i)});

            pq.pop();
        }

        while (!q.empty()) {
            auto x = q.front();
            pq.push({get<0>(x), get<1>(x), get<2>(x)});
            q.pop();
        }

        return v;
    }

    void follow(int followerId, int followeeId) {
        if (u[followerId].empty()) {
            u[followerId].push_back(vector<int>());
            u[followerId].push_back(vector<int>());
        }

        u[followerId][1].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (u.find(followerId) == u.end()) return;
        vector<int> v = u[followerId][1];

        v.erase(remove(v.begin(), v.end(), followeeId), v.end());
        u[followerId][1] = v;
    }
};
