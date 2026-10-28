
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum = 0;
        long long maxSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Add incoming element.
            windowSum += nums[right];
            freq[nums[right]]++;

            // Keep window size at most k.
            if (right >= k) {
                int outgoing = nums[right - k];

                windowSum -= outgoing;
                freq[outgoing]--;

                if (freq[outgoing] == 0) {
                    freq.erase(outgoing);
                }
            }

            // Valid window of exactly k distinct elements.
            if (right >= k - 1 && freq.size() == k) {
                maxSum = max(maxSum, windowSum);
            }
        }

        return maxSum;
    }
};
