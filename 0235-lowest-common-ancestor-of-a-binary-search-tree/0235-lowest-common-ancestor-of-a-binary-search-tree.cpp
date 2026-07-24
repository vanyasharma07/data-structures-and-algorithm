/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p1, TreeNode* q1) {
        TreeNode* node = root; 
        TreeNode* lca = NULL;

        while(node != NULL){
            int data = node->val;
            int p = p1->val;
            int q = q1->val;
            //lca is one of p nd q
            if(data == p || data == q){
                lca = node;
                break;
            }
            //p and q are greater than node
            else if(data<p && data<q){
                node = node->right;
            }
            //p and q are smaller than node
            else if(data>p && data>q){
                node = node->left;
            }
            //p and q split
            else{
                lca = node;
                break;
            }
        }
        return lca;

    }
};