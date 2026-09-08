class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> color(graph.size(), -1);

        // Handle disconnected components
        for (int start = 0; start < graph.size(); start++) {

            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (auto neighbour : graph[node]) {

                    // If neighbour is not colored
                    if (color[neighbour] == -1) {

                        // Give opposite color
                        color[neighbour] = !color[node];

                        q.push(neighbour);
                    }

                    // If both have same color → not bipartite
                    else if (color[neighbour] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};