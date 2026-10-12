class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;
        while(low<= high){
            int mid =( high-low)/2 + low;
           
            if(mid == 0 || mid <= x / mid){
                ans = mid;
                low = mid+1;
            }
            else if(mid > x / mid){
                high = mid-1;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};