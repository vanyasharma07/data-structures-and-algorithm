class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, node):
        if node == self.parent[node]:
            return node

        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def unionBySize(self, u, v):
        pu = self.find(u)
        pv = self.find(v)

        if pu == pv:
            return

        if self.size[pu] < self.size[pv]:
            self.parent[pu] = pv
            self.size[pv] += self.size[pu]
        else:
            self.parent[pv] = pu
            self.size[pu] += self.size[pv]


class Solution:
    def accountsMerge(self, accounts):

        n = len(accounts)

        # Create DSU for all accounts
        ds = DisjointSet(n)

        # email -> account index
        emailToAccount = {}

        # Step 1: Connect accounts having common emails
        for i in range(n):
            for j in range(1, len(accounts[i])):

                email = accounts[i][j]

                if email not in emailToAccount:
                    emailToAccount[email] = i
                else:
                    ds.unionBySize(i, emailToAccount[email])

        # Step 2: Group emails by their ultimate parent
        mergedEmails = [[] for _ in range(n)]

        for email, accountIndex in emailToAccount.items():

            parent = ds.find(accountIndex)

            mergedEmails[parent].append(email)

        # Step 3: Sort emails and create answer
        ans = []

        for i in range(n):

            if not mergedEmails[i]:
                continue

            mergedEmails[i].sort()

            current = [accounts[i][0]]
            current.extend(mergedEmails[i])

            ans.append(current)

        return ans

        