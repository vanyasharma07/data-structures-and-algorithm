class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<pair<int,int>, int>> q;

        // Put all 0s into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dist = curr.second;

            ans[r][c] = dist;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return ans;
    }
};