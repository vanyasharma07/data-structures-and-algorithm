class Solution:

    def dfs(self, node, graph, color):

        for neighbor in graph[node]:

            # Neighbor is not colored
            if color[neighbor] == -1:

                # Give opposite color
                color[neighbor] = 1 - color[node]

                # Continue DFS
                if not self.dfs(neighbor, graph, color):
                    return False

            # Neighbor has same color
            elif color[neighbor] == color[node]:
                return False

        return True

    def isBipartite(self, graph):

        V = len(graph)

        # -1 = uncolored
        # 0 and 1 = two colors
        color = [-1] * V

        # Handle disconnected components
        for start in range(V):

            if color[start] != -1:
                continue

            # Start this component
            color[start] = 0

            if not self.dfs(start, graph, color):
                return False

        return True