class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // adjacency List: {dest, time}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &it : times) {
            int src = it[0];
            int dst = it[1];
            int wt  = it[2];
            adj[src].push_back({dst, wt});
        }

        // min Heap -> {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>> //for min-heap
        > pq;
       vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            // Ignore outdated entries
            if (d > dist[node])
                continue;

            for (auto &edge : adj[node]) {
               int next = edge.first;
                int wt   = edge.second;
                if (d + wt < dist[next]) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};