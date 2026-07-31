class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>&q){
       
        while(!q.empty()){
            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;
            int r[] = {-1,1,0,0};
            int c[] = {0,0,-1,1};
            for(int i = 0 ; i<4; i++){
                int cr = row + r[i];
                int cc = col + c[i];

                if(cr>=0 && cr<grid.size() && cc>=0 && cc<grid[0].size()){
                    if(grid[cr][cc] == 1){
                        q.push({cr,cc});
                         grid[cr][cc] = 0;
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //scan and put in queue the boundary 1's
        //till !queue.empty(), for each element, mark it , perform bfs, put in queue if neighbour found, continue with bfs, mark them as visited(unsafe)
        //in the end count the number of 1's that are safe
        queue<pair<int, int>>q;
        //scan the boundaries
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i<c; i++){
            if(grid[0][i] == 1) { q.push({0, i}) ;
            grid[0][i] = 0;
            }
        }
         for(int i = 0; i<r; i++){
            if(grid[i][0] == 1) { q.push({i, 0});
            grid[i][0] = 0;
            }        
        }
         for(int i = 0; i<c; i++){
            if(grid[r-1][i] == 1) { q.push({r-1, i});
            grid[r-1][i] = 0;
            }
        }
         for(int i = 0; i<r; i++){
            if(grid[i][c-1] == 1) { q.push({i, c-1});
            grid[i][c-1] = 0;
            }
        }
    
        //perform bfs 
       bfs(grid, q );

       //count safe 1's
        int count = 0;
        for(int i = 0 ; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    
    }
    
};