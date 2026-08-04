class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, INT_MAX);

        queue<pair<int,int>> q;// {node, cost}

        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [node, cost] = q.front();
                q.pop();
                for (auto &[next, wt] : adj[node]) {
                    int newCost = cost + wt;
                    if (newCost < dist[next]) {
                        dist[next] = newCost;
                        q.push({next, newCost});
                    }
                }
            }
           stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];//this looks better 
    }
};