/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        Node* node = root;
        vector<vector<int>> output;
        vector<int> level;
        
        if (root == NULL) {
            return output;    
        }
        
        q.push(node);
        q.push(NULL);
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            if (node == NULL) {
                if (level.size()) {
                    output.push_back(level); 
                    q.push(NULL);
                }
                level.clear();
                continue;
            }
            
            level.push_back(node->val);
            
            for (vector<Node*>::iterator it = node->children.begin();
                 it != node->children.end(); it++) {
                q.push(*it);
            }                        
        }
        return output;
    }
};
