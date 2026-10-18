/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> visited;
        return cloneGraphDFS(node, visited);
    }

private:
    Node* cloneGraphDFS(Node* node, std::unordered_map<Node*, Node*>& visited) {  
        if (visited.count(node)) {
            return visited[node];
        }

        Node* copyNode = new Node(node->val);
        visited[node] = copyNode;

        for (Node* neighbor : node->neighbors) {
            copyNode->neighbors.push_back(cloneGraphDFS(neighbor, visited));
        }
        
        return copyNode;
    }

};