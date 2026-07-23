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
    // bool find(TreeNode* &curr, TreeNode* &prev, int key){
    //     if(curr->val > key ){
    //         find(curr->left, curr, key)
    //     }
    //     if(curr->val < key ){
    //         find(curr->right, curr, key)
    //     }
    //     if(curr->val == key ){
    //         return 1 ; 
    //     }
    //     return 0;
    // }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if(root == NULL) return NULL;
        // TreeNode* prev = root;
        // TreeNode* curr = root;
        // int ans = find(curr, prev, key);//now we will have the node, it's parent
        // if(ans) return root;
        // //now that we have the node we can delete the node based on 3 conditions i.e. node has 0,1,2 children
        // //if root is to be deleted
        // if(prev == curr){
        //     if(curr->left == NULL && curr->right == NULL) return NULL;
        //     if(curr->left != NULL && curr->right == NULL || curr->left = NULL && curr->right != NULL ) {
        //         if(curr->left){
        //             TreeNode* ans = curr->left;
        //             curr->left == NULL; 
        //             return ans;
        //         }
        //         if(curr->right){
        //             TreeNode* ans = curr->right;
        //             curr->right == NULL; 
        //             return ans;
        //         }
        //     }
        //     if(curr->left != NULL && curr->right != NULL){
        //         TreeNode* new = curr->left;
        //         while(new->right!= NULL){
        //             new = new->right;
        //         }
        //         new->right == curr->right;
        //         curr->left == NULL;
        //         curr->right == NULL;
        //         return new;
        //     }
        
        //     }
        
        // //0 childern
        // if(curr->left == NULL && curr->right == NULL){
        //     if(prev->left == node) prev->left == NULL; 
        //     if(prev->right == node) prev->right == NULL; 
        //     return root;
        // }
        // //1 child
        // if(curr->left != NULL && curr->right == NULL || curr->left = NULL && curr->right != NULL ){
        //     if(prev->left == node) prev->left == curr->left;
        //     if(prev->right == node) prev->right == curr->right ; 
        //     return root; 
        // }
        // //2 children
        // if(curr->left != NULL && curr->right != NULL){
        //     if(prev->left == curr){
        //         prev->left == curr->left;
        //         TreeNode* new = prev->left;
        //         while(new->right != NULL){
        //             new = new->right;
        //         }
        //         new->right = curr->right;
        //     }
        //      if(prev->right == curr){
        //         prev->right == curr->right;
        //         TreeNode* new = prev->right;
        //         while(new->left != NULL){
        //             new = new->left;
        //         }
        //         new->left = curr->left ;
                
        //     }
        //     return root;
        // }

        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        // Find node and its parent
        while (curr && curr->val != key) {
            parent = curr;

            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
         // Key not found
        if (curr == nullptr)
            return root;
        
        // Case 1 : Node has at most one child
        if (curr->left == nullptr || curr->right == nullptr) {
            TreeNode* child;
            if (curr->left)
                child = curr->left;
            else
                child = curr->right;

            // deleting root
            if (parent == nullptr)
                return child;
            if (parent->left == curr)
                parent->left = child;
            else
                parent->right = child;
            return root;
        }

         // Case 2 : Node has two children
        // Find inorder predecessor (largest in left subtree)

        TreeNode* predParent = curr;
        TreeNode* pred = curr->left;

        while (pred->right) {
            predParent = pred;
            pred = pred->right;
        }
        // Copy predecessor value
        curr->val = pred->val;
        // Remove predecessor node
        if (predParent == curr)
            predParent->left = pred->left;
        else
            predParent->right = pred->left;

        return root;

    }
};