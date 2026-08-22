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
    unordered_map<int,int>mp;
    TreeNode* build(vector<int>& preorder, 
                    int preStart, int preEnd,
                    vector<int>& inorder,
                    int inStart, int inEnd){
            //no elements
            if (preStart > preEnd || inStart > inEnd) {
            return NULL;
            }

            //first element of preorder is the root
            TreeNode* root = new TreeNode(preorder[preStart]);

            //find the root position in inorder
            int rootIndex = mp[root->val];

            //numbe of nodes in the left subtree
            int leftSize = rootIndex- inStart;


        // Build left subtree
        root->left = build(
            preorder,
            preStart + 1,
            preStart + leftSize,
            inorder,
            inStart,
            rootIndex - 1
        );

        // Build right subtree
        root->right = build(
            preorder,
            preStart + leftSize + 1,
            preEnd,
            inorder,
            rootIndex + 1,
            inEnd
        );
        return root;
                
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //hashing inorder values
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};