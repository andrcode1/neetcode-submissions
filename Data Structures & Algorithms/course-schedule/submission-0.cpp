class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }

        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);

        for (const auto& edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];

            adjList[from].push_back(to);
            inDegree[to]++;
        }
        
        return existsCycle(adjList, inDegree);
    }

private:
    bool existsCycle(vector<vector<int>>& adjList, vector<int>& inDegree) {
        std::queue<int> zeroInDegree;

        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push(i);
            }
        }

        while (!zeroInDegree.empty()) {
            int node = zeroInDegree.front();
            zeroInDegree.pop();

            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }

        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] > 0) {
                return false;
            }
        }
        return true;
    }
};

// numCourses = 3
// [0, 1, 2]

// prerequisites = 
// {1, 0},
// {2, 1}

// true

// numCourses = 3
// [0, 1, 2]

// prerequisites = 
// {1, 0} = 0 -> 1
// {0, 1} = 1 -> 0
// {0, 2}

// {1, 0} = 0 -> 1
// {2, 1} = 1 -> 2
// {0, 2} = 2 -> 0

// {1, 0} = 0 -> 1
// {2, 0} = 0 -> 2
// {2, 1} = 1 -> 2