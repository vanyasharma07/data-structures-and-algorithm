class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m = len(heights)
        n = len(heights[0])

        # effort[r][c] = minimum effort required to reach (r, c)
        effort = [[float('inf')] * n for _ in range(m)]

        # Min heap: (currentEffort, row, col)
        pq = []

        effort[0][0] = 0
        heapq.heappush(pq, (0, 0, 0))

        # 4-direction movement
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        while pq:
            currEffort, r, c = heapq.heappop(pq)

            # Destination reached
            if r == m - 1 and c == n - 1:
                return currEffort

            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]

                if 0 <= nr < m and 0 <= nc < n:

                    # Effort of this edge
                    diff = abs(heights[r][c] - heights[nr][nc])

                    # Maximum difference encountered in this path
                    newEffort = max(currEffort, diff)

                    # Relaxation
                    if newEffort < effort[nr][nc]:
                        effort[nr][nc] = newEffort
                        heapq.heappush(pq, (newEffort, nr, nc))

        return 0