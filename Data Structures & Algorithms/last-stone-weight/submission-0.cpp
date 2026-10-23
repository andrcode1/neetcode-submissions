class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxStones;
        for (auto& stone : stones) {
            maxStones.push(stone);
        }

        while (maxStones.size() > 1) {
            int maxStone = maxStones.top();
            maxStones.pop();
            int nextMaxStone = maxStones.top();
            maxStones.pop();

            int diff = maxStone - nextMaxStone;
            if (diff == 0) {
                continue;
            }

            maxStones.push(diff);
        }

        if (maxStones.size() == 1) {
            return maxStones.top();
        }
        return 0;
    }
};
