class Solution {
public:
    void dfs( int i, vector<vector<int>>& adj, int v, vector<int>&visited ){
        visited[i] = 1;//mark visited
        for(int neighbour = 0; neighbour<v; neighbour++){
            if(adj[i][neighbour] == 1 && !visited[neighbour]){
                dfs(neighbour, adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size(); //no of vertices
        vector<int>visited(v,0);
        int provinces = 0;

        for(int i = 0; i<v; i++){
            if(!visited[i]){
            provinces++;
            dfs(i, adj, v, visited);
            }
        }

        return provinces;

    }
};