class Twitter {
private:

    using Tweet = std::pair<int, int>; // timestamp, tweetId

    int timestamp = 0;
    std::unordered_map<int, vector<Tweet>> userTweets{}; //userid -> tweetIds
    std::unordered_map<int, std::unordered_set<int>> userFollowings{}; //userId -> their follows (userIds)

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<Tweet, vector<Tweet>, greater<Tweet>> feed;
        userFollowings[userId].insert(userId);

        for (int followee : userFollowings[userId]) {
            for (Tweet& tweet : userTweets[followee]) {
                feed.push(tweet);
                if (feed.size() > 10) {
                    feed.pop();
                }
            }
        }

        vector<int> res;
        while (feed.size() > 0) {
            Tweet tweet = feed.top();
            feed.pop();

            res.push_back(tweet.second);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */