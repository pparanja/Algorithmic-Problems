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
//Method - 1 : Creating new tree 

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

//==============================================================================================
//Method - 2 : Modifying same tree 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // Modify one of the existing tree to hold the output
        if (!t1) {
            return t2;
        }
        
        if (!t2) {
            return t1;
        }
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;    
    }
};
