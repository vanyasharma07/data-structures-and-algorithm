from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)

        # Check if start or end is blocked
        if grid[0][0] == 1 or grid[n - 1][n - 1] == 1:
            return -1

        # Single cell grid
        if n == 1:
            return 1

        # Queue: (row, col, pathLength)
        q = deque()
        q.append((0, 0, 1))

        # Visited array
        vis = [[0] * n for _ in range(n)]
        vis[0][0] = 1

        # 8-direction neighbours
        dr = [-1, -1, -1, 0, 0, 1, 1, 1]
        dc = [-1, 0, 1, -1, 1, -1, 0, 1]

        while q:
            row, col, dist = q.popleft()

            for i in range(8):
                nr = row + dr[i]
                nc = col + dc[i]

                if (0 <= nr < n and
                    0 <= nc < n and
                    not vis[nr][nc] and
                    grid[nr][nc] == 0):

                    # Destination reached
                    if nr == n - 1 and nc == n - 1:
                        return dist + 1

                    vis[nr][nc] = 1
                    q.append((nr, nc, dist + 1))

        return -1