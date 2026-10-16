class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int costPrevPrev = cost[0];
        int costPrev = cost[1];

        for (int i = 2; i < cost.size(); ++i) {
           int currCost = cost[i] + std::min(costPrevPrev, costPrev);
           costPrevPrev = costPrev;
           costPrev = currCost;
        }

        return std::min(costPrevPrev, costPrev);
    }
};
