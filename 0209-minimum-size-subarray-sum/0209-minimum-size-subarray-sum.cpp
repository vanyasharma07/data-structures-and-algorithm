
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int minLen = INT_MAX;
        long long windowSum = 0;

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            while (windowSum >= target) {
                minLen = min(minLen, right - left + 1);

                windowSum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
