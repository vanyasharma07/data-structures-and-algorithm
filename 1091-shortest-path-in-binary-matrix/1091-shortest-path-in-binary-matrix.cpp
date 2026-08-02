class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // check if start or end is 1
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // Single cell grid
        if(n == 1)
            return 1;

        queue<pair<pair<int,int>, int>> q; //push {{row,col}, pathLength}
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({{0,0}, 1});
        vis[0][0] = 1;
        //for 8-direction neighbour
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n &&nc >= 0 && nc < n &&!vis[nr][nc] &&grid[nr][nc] == 0){
                    if(nr == n-1 && nc == n-1)
                        return dist + 1;
                    vis[nr][nc] = 1;
                    q.push({{nr,nc}, dist + 1});
                }
            }
        }
        return -1;
    }
};