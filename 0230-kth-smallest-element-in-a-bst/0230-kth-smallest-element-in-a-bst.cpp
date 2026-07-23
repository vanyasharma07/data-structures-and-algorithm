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
    void inorder(TreeNode* node, int &k, int &ans){
    
        if(node == NULL || k == 0 ) return ;
        inorder(node->left, k, ans);

        k--;
        if(k == 0) ans = node->val;
       
        inorder(node->right, k, ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        //inorder traversal 
        int ans = -1;
        inorder(root, k , ans);
        return ans;
    }
};