class Solution {
public:

    class FindUnion {
    private:
        int components = 0;
        vector<int> parent;
        vector<int> size; 

    public:
        FindUnion(int n) {
            components = n;
            parent.resize(n);
            size.resize(n);

            std::iota(parent.begin(), parent.end(), 0);
            std::fill(size.begin(), size.end(), 1);
        }

        int find (int n) {
            if (parent[n] == n) {
                return n;
            }
            return find(parent[n]);
        }

        bool unionNodes(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return false;
            }
            if (root1 < root2) {
                std::swap(root1, root2);
            }
            parent[root2] = root1;
            size[root1] += size[root2];
            components--;
            return true;
        }

        int getComponents() {
            return components;
        }
    };

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()) {
            return true;
        }

        FindUnion dsu(n);  // O(V)
        for (const auto& edge : edges) { // O(E)
            int node1 = edge[0];
            int node2 = edge[1];
            if (!dsu.unionNodes(node1, node2)) { // O(V) amortized
                return false;
            }
        }
        return dsu.getComponents() == 1;
    }
};
// input:
//  n = 5, 0..n-1
// {{0, 1}, {0,2}, {0,3}, {1,4}}

//output: true/false (whether graph is valid tree)
