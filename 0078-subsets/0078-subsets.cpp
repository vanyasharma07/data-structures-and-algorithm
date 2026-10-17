class Solution {
public:

    // void solve(int index, vector<int>& nums,
    //            vector<int>& temp,
    //            vector<vector<int>>& ans)
    // {
    //     if(index == nums.size()) {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     temp.push_back(nums[index]);
    //     solve(index + 1, nums, temp, ans);
    //     temp.pop_back();
    //     solve(index + 1, nums, temp, ans);
    // }

    vector<vector<int>> subsets(vector<int>& nums) {

        // vector<vector<int>> ans;
        // vector<int> temp;

        // solve(0, nums, temp, ans);

        // return ans;

        //--------BITWISE APPROACH--------//
          int n = nums.size();
        int total = 1 << n;

        vector<vector<int>> ans;

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};