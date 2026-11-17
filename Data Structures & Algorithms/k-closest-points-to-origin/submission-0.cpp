class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& point1, const vector<int>& point2) {
            int distance1 = (point1[0]*point1[0] + point1[1]*point1[1]);
            int distance2 = (point2[0]*point2[0] + point2[1]*point2[1]);
            return distance2 > distance1;
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> furthestPoints(points.begin(), points.end(), comp);

        while (furthestPoints.size() > k) {
            furthestPoints.pop();
        }

        std::vector<std::vector<int>> res;
        while(!furthestPoints.empty()) {
            const auto& point = furthestPoints.top();
            res.push_back(point);
            furthestPoints.pop();
        }

        return res;
    }
};
