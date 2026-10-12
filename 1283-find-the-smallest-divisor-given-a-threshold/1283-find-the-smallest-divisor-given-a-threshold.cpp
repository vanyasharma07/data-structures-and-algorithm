class Solution {
public:
    int sumDivisors(vector<int>&nums, int mid){
        int sum = 0;
        for(auto it: nums){
            sum = sum + ceil((double(it))/ double(mid));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low<= high){
            int mid = (high-low)/2 + low;
            if(sumDivisors(nums, mid) <= threshold){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};