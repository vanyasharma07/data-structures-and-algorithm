class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int currEffort = p.first;
            int r = p.second.first;
            int c = p.second.second;

            // destination reached
            if (r == m - 1 && c == n - 1)
                return currEffort;

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int diff = abs(heights[r][c] - heights[nr][nc]);

                    int newEffort = max(currEffort, diff);

                    if (newEffort < effort[nr][nc]) {

                        effort[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};