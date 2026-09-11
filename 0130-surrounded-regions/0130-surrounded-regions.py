class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        m = len(board)
        n = len(board[0])

        q = deque()

        # Add all boundary O's to queue
        for i in range(m):
            if board[i][0] == 'O':
                q.append((i, 0))
                board[i][0] = 'S'

            if board[i][n - 1] == 'O':
                q.append((i, n - 1))
                board[i][n - 1] = 'S'

        for j in range(n):
            if board[0][j] == 'O':
                q.append((0, j))
                board[0][j] = 'S'

            if board[m - 1][j] == 'O':
                q.append((m - 1, j))
                board[m - 1][j] = 'S'

        # BFS from boundary O's
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:

            r, c = q.popleft()

            for dr, dc in directions:

                nr = r + dr
                nc = c + dc

                if (0 <= nr < m and
                    0 <= nc < n and
                    board[nr][nc] == 'O'):

                    board[nr][nc] = 'S'
                    q.append((nr, nc))

        # Flip surrounded O's and restore safe O's
        for i in range(m):
            for j in range(n):

                if board[i][j] == 'O':
                    board[i][j] = 'X'

                elif board[i][j] == 'S':
                    board[i][j] = 'O'
        