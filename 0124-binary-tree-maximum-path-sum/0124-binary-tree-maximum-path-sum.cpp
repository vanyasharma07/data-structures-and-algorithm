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
public:

    int findMax(TreeNode* root, int &maxi) {

        // Empty subtree
        if (root == NULL)
            return 0;

        // Find maximum contribution from left and right
        int left = max(0, findMax(root->left, maxi));
        int right = max(0, findMax(root->right, maxi));

        // Path passing through current node
        int currentPath = left + right + root->val;

        // Update global maximum
        maxi = max(maxi, currentPath);

        // Return maximum one-sided path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        findMax(root, maxi);

        return maxi;
    }
};