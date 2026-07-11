#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU {
    private:
        vector <ll> parent, rank;
    public:
        DSU(int n=2e5) : parent(n), rank(n, 1) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }

        ll uf_find(ll x) {
            if (x != parent[x]) {
                parent[x] = uf_find(parent[x]);
            }
            return parent[x];
        }

        bool uf_union(ll x, ll y) {
            ll xPar = uf_find(x), yPar = uf_find(y);
            // check if same tree
            if (xPar == yPar) return false;
            // put the smaller one into the bigger one
            if (rank[xPar] < rank[yPar]) {
                parent[xPar] = yPar;
                rank[yPar] += rank[xPar];
            } else {
                parent[yPar] = xPar;
                rank[xPar] += rank[yPar];
            }
        }
};