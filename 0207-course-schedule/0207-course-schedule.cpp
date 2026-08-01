class Solution {
public:
    bool dfs(int i, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path ){
        vis[i] = 1;
        path[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]) {
                if(dfs(it, adj, vis, path))
                return true;
            }
            else if(path[it]) return true;
        }
        path[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
       //number of tasks = numcourses
       //to complete a task B we need to complete A first , hence {B,A}, A-->B here

       //we will first create the adjacency list from the given prerequisites
       vector<vector<int>>adj(numCourses);
        for(int i = 0; i<pre.size(); i++){
            int a = pre[i][1];
            int b = pre[i][0];
            adj[a].push_back(b);
        }

        //now we will detect cycle in this graph (dfs)
        vector<int>vis(numCourses, 0);
        vector<int>path(numCourses,0);
        for(int i = 0 ; i<numCourses; i++){
        if(!vis[i]){
        if(dfs(i, adj, vis, path))
            return false;
    }
}

        return true;
    }
};