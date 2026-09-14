class DisjointSet {
    vector<int> size, parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        // Already in the same component
        if (pu == pv)
            return;

        // Attach smaller component to larger component
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        // We need at least n-1 edges for n nodes
        if (connections.size() < n - 1)
            return -1;

        DisjointSet ds(n);

        int components = n;

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (ds.findPar(u) != ds.findPar(v)) {
                ds.unionBySize(u, v);
                components--;
            }
        }

        return components - 1;
    }
};