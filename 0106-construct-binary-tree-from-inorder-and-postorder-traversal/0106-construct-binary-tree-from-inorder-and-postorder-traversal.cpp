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

    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& inorder,
                    int inStart,
                    int inEnd,
                    vector<int>& postorder,
                    int postStart,
                    int postEnd) {

        // No elements
        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        // Last element of postorder is root
        int rootValue = postorder[postEnd];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int rootIndex = mp[rootValue];

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = build(
            inorder,
            inStart,
            rootIndex - 1,
            postorder,
            postStart,
            postStart + leftSize - 1
        );

        // Build right subtree
        root->right = build(
            inorder,
            rootIndex + 1,
            inEnd,
            postorder,
            postStart + leftSize,
            postEnd - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(
            inorder,
            0,
            inorder.size() - 1,
            postorder,
            0,
            postorder.size() - 1
        );
    }
};