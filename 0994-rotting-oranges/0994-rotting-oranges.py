class Solution:
    def bfs(self, grid, q, fresh, time):
        while q and fresh>0:
            #all rotten at this time in queue
            n = len(q)
            for _ in range(n):
                row, col = q.popleft()
                #looking for neighbours in 4 directions
                rows = [-1,1,0,0]
                cols = [0,0,-1,1]

                for k in range(4):
                    nr = row + rows[k]
                    nc = col + cols[k]
                    if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]):
    
                        if grid[nr][nc] == 1:
                            fresh -= 1
                            grid[nr][nc] = 2
                            q.append((nr,nc))
            time += 1
        return fresh, time

    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        fresh = 0
        time = 0 
        for row in range (0, len(grid)):
            for col in range (0, len(grid[0])):
                if grid[row][col] == 1 :
                    fresh += 1
                elif grid[row][col] == 2 :
                    q.append((row,col))

        #multisource bfs
        fresh , time = self.bfs(grid, q, fresh, time)

        if fresh > 0 : 
            return -1
        
        return time
