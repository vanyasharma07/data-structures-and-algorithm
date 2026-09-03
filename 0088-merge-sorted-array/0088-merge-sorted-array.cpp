class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        // First approach:
        // Compare largest element of nums1
        // with smallest element of nums2.

        int left = m - 1;
        int right = 0;

        // Fix the order between the two arrays
        while (left >= 0 && right < n) {

            if (nums1[left] > nums2[right]) {

                swap(nums1[left], nums2[right]);

                left--;
                right++;
            }
            else {
                break;
            }
        }

        // Sort the valid part of nums1
        sort(nums1.begin(), nums1.begin() + m);

        // Sort nums2
        sort(nums2.begin(), nums2.end());

        // Put nums2 after nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};