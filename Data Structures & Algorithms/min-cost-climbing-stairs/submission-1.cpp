class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int costPrevPrev = cost[0];
        int costPrev = cost[1];
        int currCost = std::min(costPrevPrev, costPrev);

        for (int i = 2; i < cost.size(); ++i) {
           currCost = cost[i] + std::min(costPrevPrev, costPrev);
           costPrevPrev = costPrev;
           costPrev = currCost;
        }

        return std::min(costPrevPrev, costPrev);
    }
};
