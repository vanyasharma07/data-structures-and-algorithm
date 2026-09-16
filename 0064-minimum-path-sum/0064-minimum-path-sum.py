class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:

        n = len(grid)
        m = len(grid[0])
        # 1-d array, storing previous row values
        dp = [0] * m 

        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    dp[j] = grid[i][j]

                else:
                    up = grid[i][j]

                    if i > 0:
                        up += dp[j]
                    else:
                        up += 10**9

                    left = grid[i][j]

                    if j > 0:
                        left += dp[j - 1]
                    else:
                        left += 10**9

                    dp[j] = min(up, left)

        return dp[m - 1]