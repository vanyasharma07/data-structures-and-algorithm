class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        int count = 1;
        int ending = intervals[0][1];
        

        for(auto it: intervals){
            if(it == intervals[0]) continue;
            int start = it[0];
            int end = it[1];
            if(start>=ending){
                count ++;
                ending = end;
            }
        }
        return intervals.size() - count;
    }
};