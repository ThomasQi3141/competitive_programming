#include <bits/stdc++.h>
using namespace std;
// macros for logging in cerr
#ifdef LOCAL
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

template <class Map>
void LOGMAP(const Map& mp, const string& name = "map") {
    cerr << "[LOG] " << name << " (size=" << mp.size() << "): {";
    bool first = true;
    for (const auto& [k, v] : mp) {
        if (!first) cerr << ", ";
        first = false;
        cerr << k << ": " << v;
    }
    cerr << "}\n";
}

#else
#define LOG(x) ((void)0)
template <class Map>
void LOGMAP(const Map&, const string& = "map") { /* no-op */ }
#endif
using ll = long long;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

ll uf_find(ll x, vector<ll> &parent) {
    if (x != parent[x]) {
        parent[x] = uf_find(parent[x], parent);
    }
    return parent[x];
}

void uf_union(ll x, ll y, vector<ll> &rank, vector<ll> &parent) {
    ll xPar = uf_find(x, parent), yPar = uf_find(y, parent);
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
    // union find?
    ll n, m;
    cin >> n >> m;
    // UF data structures
    vector<ll> rank(n + 1, 1);
    vector<ll> parent(n + 1);
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
    ll curLen, first, val;
    for (int i = 0; i < m; i++) {
        cin >> curLen;
        if (curLen == 0) {
            continue;
        }
        cin >> first;
        for (int j = 0; j < curLen - 1; j++) {
            cin >> val;
            uf_union(first, val, rank, parent);
        }
    }
    LOG(rank);
    // just output rank of each thing
    for (int i = 1; i <= n; i++) {
        cout << rank[uf_find(i, parent)] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
