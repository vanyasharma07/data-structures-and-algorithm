class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:

        n = len(triangle)
        dp = triangle[n - 1].copy()
        for i in range(n - 2, -1, -1):

            for j in range(i + 1):

                dp[j] = triangle[i][j] + min(
                    dp[j],       # below
                    dp[j + 1]   # diagonal
                )

        return dp[0]
        