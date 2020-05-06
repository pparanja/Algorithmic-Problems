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
    void processInOrder(TreeNode* root, int L, int R, int& sum) {
        if (root) {
            inOrder(root->left, L, R, sum);
            
            // Evaluate if current node's value satisfies the constraint.
            // If yes, add it to sum. 
            if (L <= root->val && root->val <= R) {
                sum += root->val;
            }

            inOrder(root->right, L, R, sum);
        }
    }
public:

    int rangeSumBST(TreeNode* root, int L, int R) {
        // This program traverses over BST using in-order fashion evalutating
        // each node that satisfies the given condition
        int sum = 0;
        processInOrder (root, L, R, sum);
        return sum;
    }
};
