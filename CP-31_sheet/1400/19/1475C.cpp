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

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    vector<pair<string, string>> edges(k);
    // for each edge, its edgeCount - neighboring edges for both vertices (then sum together) 
    ll x;
    for (auto &[boy, girl] : edges) {
        cin >> x;
        boy = "b" + to_string(x);
    }
    map<string, vector<string>> adj;
    for (auto &[boy, girl] : edges) {
        cin >> x;
        girl = "g" + to_string(x);
        adj[girl].push_back(boy);
        adj[boy].push_back(girl);
    }
    LOG(edges);
    // all the edges not containing u or v are valid second choices
    ll res = 0;
    for (auto [u, v] : edges) {
        LOG(u);
        LOG(v);
        LOG(k - (adj[u].size() + adj[v].size() - 1));
        res += k - (adj[u].size() + adj[v].size() - 1);
    }
    // double counted all the pairs, /2 to get actual pair count
    cout << res / 2 << endl;
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
