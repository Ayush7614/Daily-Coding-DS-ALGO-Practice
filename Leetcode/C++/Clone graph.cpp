//Link of question:
//https://leetcode.com/problems/clone-graph/

//Given:Given a reference of a node in a connected undirected graph.

//AIM: Return a deep copy (clone) of the graph.

//Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

//Example:

/*Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

*/
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
        if (!node)
            return nullptr;
        // explore
        // maintain an ajacency list of the nodes we have seen and their edges
        // but only add edges in a directed fashion
        // if an edge is new, add it and then add the node to the bfs queue
        // if the edge exists, then don't add it or the node to the bfs queue
        map<int, set<int>> adj_list;
        queue<Node*> nodeq;
        nodeq.push(node);
        do {
            Node* w = nodeq.front();
            nodeq.pop();
            if (adj_list.count(w->val) == 0)
                adj_list[w->val] = {};
            for (Node* v : w->neighbors) {
                if (adj_list[w->val].count(v->val) == 0) {
                    // new node
                    adj_list[w->val].insert(v->val);
                    nodeq.push(v);
                }
            }
        } while (!nodeq.empty());
        // copy
        // first create all of the nodes, then add their edges in a second pass
        map<int, Node *> node_copies;
        for (auto& [w, _] : adj_list) {
            node_copies[w] = new Node(w);
        }
        for (auto& [w, ns] : adj_list) {
            for (auto v : ns) {
                node_copies[w]->neighbors.push_back(node_copies[v]);
            }
        }
        return node_copies[1];
    }
};