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
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        vector<int> output;
        Node* node = NULL;
        
        if (root == NULL) {
            return output;
        }
        
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            output.push_back(node->val);
            
            for (vector<Node*>::iterator it = node->children.begin();
                 it != node->children.end(); it++) {
                 s.push(*it);
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
