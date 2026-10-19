class Solution {

class FindUnion {
private:
    int components;
    std::vector<int> parent;
    
public:
    FindUnion(int n) {
        components = n;
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int n) {
        if (parent[n] == n) {
            return n;
        }
        return (find(parent[n]));
    }

    void unionNodes(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) {
            return;
        }
        if (root1 < root2) {
            std::swap(root1, root2);
        }
        parent[root2] = root1;
        components--;
    }

    int getComponents() {
        return components;
    }
};

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        FindUnion fih(n);
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            fih.unionNodes(node1, node2);
        }
        return fih.getComponents();
    }
};
