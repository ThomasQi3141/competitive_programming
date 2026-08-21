from collections import defaultdict

class UF(dict):
    def __missing__(self, x):
        self[x] = x
        return x

class DSU:
    def __init__(self):
        self.rank = defaultdict(lambda : 1)
        self.parent = UF()
    
    def find(self, x):
        while x != self.parent[x]:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, x, y):
        xPar, yPar = self.find(x), self.find(y)
        if xPar == yPar:
            return False
        if self.rank[xPar] > self.rank[yPar]:
            # make sure rank[xPar] < rank[yPar]
            xPar, yPar = yPar, xPar
        self.parent[xPar] = yPar
        self.rank[yPar] += self.rank[xPar]
        return True