class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //check for boundaries, 
        //enqueue all boundary O's 
        //perform bfs for all boundary O's , and their neighbours
        //if any , mark as safe //after queue is empty, O's -> X's 
        //unmark the marked O's
        if(board.empty()) return;

        queue<pair<int,int>> q;

        int m = board.size();
        int n = board[0].size();

        // First row
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = 'S';
            }
        }

        // First column
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'S';
            }
        }

        // Last row
        for(int i = 0; i < n; i++){
            if(board[m-1][i] == 'O'){
                q.push({m-1, i});
                board[m-1][i] = 'S';
            }
        }

        // Last column
        for(int i = 0; i < m; i++){
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = 'S';
            }
        }

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){

                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   board[nr][nc] == 'O'){

                    board[nr][nc] = 'S';
                    q.push({nr, nc});
                }
            }
        }

        // Flip surrounded O's and restore safe O's
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};