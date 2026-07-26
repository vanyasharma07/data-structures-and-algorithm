class Solution {
public:

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>&q, int &fresh, int &mins){
        if(q.empty() || fresh == 0 ) return;
        int n =  q.size();
        for(int i= 0; i<n; i++ ){
            pair<int, int> orange = q.front();
            q.pop();
            int r = orange.first;
            int c = orange.second;

            //checking 4 neighbours
            int rows[] = {-1, 1, 0, 0};
            int coloums[] = {0, 0 , -1, 1};
            for(int k = 0; k<4; k++){
                int nr = r + rows[k];
                int nc = c + coloums[k];

                if(nr>=0 && nr<grid.size()&&nc>=0&&nc<grid[0].size()){
                    if(grid[nr][nc] == 1){
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                    else continue; 
                }
                else continue;
            }
        }
        mins ++;
        bfs(grid, q, fresh, mins);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //ALGORITHM 
        //scan the matrix once
        //keep the count of fresh oranges, and put rotten in queue
        //for n rotten in queue, run bfs once and update it's neighbours, decrease fresh count, put in the queue, decrease n , repeat

        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        int mins = 0;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        bfs(grid, q,fresh, mins);
        if (fresh > 0)
            return -1;

        return mins;
    }
};