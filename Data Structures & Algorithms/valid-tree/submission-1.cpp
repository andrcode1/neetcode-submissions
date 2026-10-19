class Solution {
public:

    std::unordered_set<int> visited;
    std::unordered_set<int> visiting;

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()) {
            return true;
        }

        vector<vector<int>> adjList(n, vector<int>());
        for (const auto& edge: edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }

        std::queue<int> remainingNodes;
        remainingNodes.push(0);

        while (!remainingNodes.empty()) {
            int currNode = remainingNodes.front();
            remainingNodes.pop();
            visited.insert(currNode);

            for (int neighbor : adjList[currNode]) {
                if (visited.contains(neighbor)) {
                    continue;
                }
                if (visiting.contains(neighbor)) {
                    return false;
                }
                visiting.insert(neighbor);
                remainingNodes.push(neighbor);
            }
        }

        if (visited.size() != n) {
            return false;
        }
        return true;
    }
};

// input:
//  n = 5, 0..n-1
// {{0, 1}, {0,2}, {0,3}, {1,4}}

//output: true/false (whether graph is valid tree)
