class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> charCounts;
        for (char c : tasks) {
            charCounts[c]++;
        }
        std::priority_queue<int> ready;
        for (const auto& [keyChar, valueCount] : charCounts) {
            ready.push(valueCount);
        }

        std::queue<pair<int, int>> cooldown; // remaining count : ready time

        int globalTime = 0;
        while (!ready.empty() || !cooldown.empty()) {
            if (!cooldown.empty() && cooldown.front().second <= globalTime) {
                ready.push(cooldown.front().first);
                cooldown.pop();
            }

            if (ready.empty()) {
                globalTime++;
                continue;
            }

            int count = ready.top();
            ready.pop();
            count--;

            if (count > 0) {
                cooldown.push({count, globalTime + n + 1});
            }
        
            globalTime++;
        }

        return globalTime;
    }
};