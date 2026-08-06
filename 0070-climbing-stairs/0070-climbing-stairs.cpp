class Solution {
public:
    // int solve(int n , vector<int>&dp){
    //     if(n<=2) return n;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = solve(n-1, dp) + solve(n-2,dp);
    // }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return solve(n, dp);
        if (n <= 2)
        return n;
        // vector<int>dp(n+1, -1);
        // dp[0] = 0;
        int prev1 = 1;
        int prev2 = 2;
        int ans = 0;
        for(int i=3 ; i<=n; i++){
            ans = prev2 + prev1;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;

    }
};