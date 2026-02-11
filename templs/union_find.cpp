#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll uf_find(ll x, vector<ll> &parent) {
    if (x != parent[x]) {
        parent[x] = uf_find(parent[x], parent);
    }
    return parent[x];
}

void uf_union(ll x, ll y, vector<ll> &rank, vector<ll> &parent) {
    ll xPar = uf_find(x, parent), yPar = uf_find(y, parent);
    // check if same tree already
    if (xPar == yPar) {
        return;
    }
    if (rank[xPar] < rank[yPar]) {
        rank[yPar] += rank[xPar];
        parent[xPar] = yPar;
    } else {
        rank[xPar] += rank[yPar];
        parent[yPar] = xPar;
    }
}


void solve() {
    ll n;
    // UF data structures
    vector<ll> rank(n + 1, 1);
    vector<ll> parent(n + 1);
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
}
