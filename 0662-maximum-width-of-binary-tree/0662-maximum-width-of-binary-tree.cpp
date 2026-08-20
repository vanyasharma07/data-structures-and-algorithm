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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // Store {node, index}
        // For a node at index i:
        // left child  = 2*i + 1
        // right child = 2*i + 2
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            // Index of the first node in this level
            unsigned long long firstIndex = q.front().second;

            unsigned long long lastIndex = firstIndex;

            for (int i = 0; i < levelSize; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize index to prevent overflow
                index = index - firstIndex;

                lastIndex = index;

                if (node->left) {
                    q.push({
                        node->left,
                        2 * index + 1
                    });
                }

                if (node->right) {
                    q.push({
                        node->right,
                        2 * index + 2
                    });
                }
            }

            // Width = last position - first position + 1
            maxWidth = max(maxWidth, lastIndex + 1);
        }

        return (int)maxWidth;
    }
};