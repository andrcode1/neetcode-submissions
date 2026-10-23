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

            if (maxStone > nextMaxStone) {
                maxStones.push(maxStone - nextMaxStone);
            }
        }

        if (!maxStones.empty()) {
            return maxStones.top();
        }
        return 0;
    }
};
