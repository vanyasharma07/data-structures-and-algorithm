class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int j = 0;
        ans.push_back(intervals[0]);
        for(int i = 1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start <= ans[j][1]) {
                ans[j][1] = max(ans[j][1], end);
            }
        
            else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};