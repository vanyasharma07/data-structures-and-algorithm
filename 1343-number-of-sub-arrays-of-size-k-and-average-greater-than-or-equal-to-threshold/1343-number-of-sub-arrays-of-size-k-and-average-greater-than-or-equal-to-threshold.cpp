
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long windowSum = 0;
        int count = 0;

        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        long long requiredSum = 1LL * k * threshold;

        if (windowSum >= requiredSum) {
            count++;
        }

        for (int right = k; right < arr.size(); right++) {
            windowSum += arr[right];
            windowSum -= arr[right - k];

            if (windowSum >= requiredSum) {
                count++;
            }
        }

        return count;
    }
};
