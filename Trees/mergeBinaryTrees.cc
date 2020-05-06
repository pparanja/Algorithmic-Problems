/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void processInOrder(TreeNode* t1, TreeNode* t2, TreeNode* t) {
        if (!t1 && !t2) {
            return;
        }

        t->val = (t1?t1->val:0) + (t2?t2->val:0);
        
        if ((t1 && t1->left) || (t2 && t2->left)) {
            t->left = new TreeNode();
            processInOrder(t1?t1->left:NULL, t2?t2->left:NULL, t->left);
        }
        
        if ((t1 && t1->right) || (t2 && t2->right)) {
            t->right = new TreeNode();  
            processInOrder(t1?t1->right:NULL, t2?t2->right:NULL, t->right);
        }
    } 
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* t = NULL;
        if (t1 || t2) {
            t = new TreeNode();
        }
        processInOrder(t1, t2, t);
        return t;
    }
};
