class Solution:
    def dfs(self, i, visited, isConnected):
        visited[i] = 1
        for neighbour in range (0,len(isConnected)):
            if isConnected[i][neighbour] == 1 and visited[neighbour] == 0:
                self.dfs(neighbour, visited, isConnected)
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = [0] * len(isConnected)
        provinces = 0
        for i in range(len(isConnected)):
            if visited[i] == 0:
                provinces += 1
                self.dfs(i, visited, isConnected)

        return provinces 