class Solution:
    def dfs(self, i , adj, visited, path):
        visited[i] = 1
        path[i] = 1

        for neighbour in adj[i]:
            if not visited[neighbour]:
                if self.dfs(neighbour, adj, visited, path):
                    return True
            elif path[neighbour]: 
                return True
        path[i] = 0
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        "using dfs"
        'creating adjancency list from given input'
        adj = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            adj[b].append(a)

        'detect a cycle in graph'
        visited = [0] * numCourses
        path = [0] * numCourses
        for i in range(numCourses):
            if not visited[i]:
                if self.dfs(i, adj, visited, path):
                    return False
                
        return True
        