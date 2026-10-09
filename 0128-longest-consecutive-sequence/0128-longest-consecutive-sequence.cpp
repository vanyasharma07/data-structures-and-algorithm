class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int>st;
        int longest = 1;
        int n = nums.size();
        for(auto it:nums ){
            st.insert(it);
        }
        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};