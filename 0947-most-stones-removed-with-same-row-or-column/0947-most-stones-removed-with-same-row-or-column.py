class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def findPar(self, node):
        if node == self.parent[node]:
            return node

        self.parent[node] = self.findPar(self.parent[node])
        return self.parent[node]

    def unionBySize(self, u, v):
        pu = self.findPar(u)
        pv = self.findPar(v)

        if pu == pv:
            return False

        if self.size[pu] < self.size[pv]:
            self.parent[pu] = pv
            self.size[pv] += self.size[pu]
        else:
            self.parent[pv] = pu
            self.size[pu] += self.size[pv]

        return True


class Solution:
    def removeStones(self, stones):
        # Maximum possible row/column value
        maxRow = 0
        maxCol = 0

        for r, c in stones:
            maxRow = max(maxRow, r)
            maxCol = max(maxCol, c)

        # Offset columns so row and column nodes don't overlap
        offset = maxRow + 1
        ds = DisjointSet(offset + maxCol + 1)

        # Connect row node with column node
        for r, c in stones:
            rowNode = r
            colNode = c + offset

            ds.unionBySize(rowNode, colNode)

        # Count connected components containing stones
        components = set()

        for r, c in stones:
            rowNode = r
            colNode = c + offset

            components.add(ds.findPar(rowNode))

        # From every connected component, we can remove
        # all stones except one
        return len(stones) - len(components)
        