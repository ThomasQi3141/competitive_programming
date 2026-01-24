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
#else
#define LOG(x) ((void)0)
#endif
using ll = long long;
const ll INF = 1e9;

void dfs(ll node, ll prev, ll prevEdgeIdx, map<pair<ll, ll>, ll> &edgeToIdx, map<ll, vector<ll>> &adj, vector<ll> &dp) {
    // must read prev node before current node
    // so current node AT LEAST has same reading as prev node (might be after if index lower)
    if (prev != -1) {
        dp[node] = dp[prev];
    }
    if (edgeToIdx.contains({node, prev}) && edgeToIdx[{node, prev}] < prevEdgeIdx) {
        dp[node] = dp[prev] + 1;
    }
    for (ll nb : adj[node]) {
        if (nb == prev) {
            continue;
        }
        dfs(nb, node, edgeToIdx[{node, prev}], edgeToIdx, adj, dp);
    }
}

void solve() {
    ll n;
    cin >> n;
    ll u, v;
    map<pair<ll, ll>, ll> edgeToIdx;
    map<ll, vector<ll>> adj;
    vector<ll> dp(n + 1, 1);
    // dp[node] = reading of node
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        edgeToIdx[{u, v}] = i;
        edgeToIdx[{v, u}] = i;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // every inversion is a new reading (sometimes)
    dfs(1, -1, -INF, edgeToIdx, adj, dp);
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
