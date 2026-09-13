class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        V = len(graph)
        # reversed graph 
        adjRev = [[]for _ in range(V)]

        #indegree array 
        indegree = [0] * V

        #building reverse graph 
        
        for i in range(V):
            for it in graph[i]:
                adjRev[it].append(i)
                indegree[i] += 1

        q = deque()
        safe = []

        for i in range(V):
            if indegree[i] == 0:
                q.append(i)
        
        # topo sort 
        while q :
            node = q.popleft()
            safe.append(node)

            for i in adjRev[node]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.append(i)
            
        safe.sort()
        return safe
        