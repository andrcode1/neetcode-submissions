class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        std::vector<int> order(tasks.size());
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int task1Index, int task2Index) {
            return tasks[task1Index][0] < tasks[task2Index][0];
        });

        using Task = pair<int, int>; //procesingTime, origIdx
        std::priority_queue<Task, vector<Task>, greater<>> ready;

        vector<int> res;
        long long time = 0;
        int currIdx = 0;

        while (currIdx < tasks.size() || !ready.empty()) {
            if (ready.empty()) {
                time = std::max(time, static_cast<long long>(tasks[order[currIdx]][0]));
            }

            while (currIdx < tasks.size() && tasks[order[currIdx]][0] <= time) {
                ready.push({tasks[order[currIdx]][1], order[currIdx]});
                currIdx++;
            }

            auto [procTime, origIdx] = ready.top();
            ready.pop();

            time += procTime;
            res.push_back(origIdx);
        }

        return res;
    }
};