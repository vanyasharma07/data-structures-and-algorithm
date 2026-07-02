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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root == nullptr)
            return {};

        vector<vector<int>> ans;

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto f = q.front();
            q.pop();

            TreeNode* node = f.first;

            int x = f.second.first;
            int y = f.second.second;

            nodes[x][y].insert(node->val);

            if(node->left)
                q.push({node->left,{x-1,y+1}});

            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }

        for(auto i : nodes){

            vector<int> temp;

            for(auto j : i.second){

                temp.insert(temp.end(),
                            j.second.begin(),
                            j.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};