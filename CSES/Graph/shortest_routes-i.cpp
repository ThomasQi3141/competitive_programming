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
using pll = pair<ll, ll>;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    // city -> weight, city
    map<ll, vector<pll>> adj;
    ll start, dest, curDist;
    for (int i = 0; i < m; i++) {
        cin >> start >> dest >> curDist;
        adj[start].push_back({curDist, dest});
    }
    vector<ll> dist(n + 1, INF);
    // creates a minH of pll
    // type stored, container to store heap internally, how to compare items
    priority_queue<pll, vector<pll>, greater<pll>> minH;
    minH.push({0, 1});
    while (!minH.empty()) {
        auto [curDist, node] = minH.top();
        LOG(curDist);
        LOG(node);
        minH.pop();
        if (curDist >= dist[node]) {
            continue;
        }
        dist[node] = curDist;
        LOG(node);
        LOG(dist);
        for (auto [nbDist, nb] : adj[node]) {
            LOG(curDist);
            if (curDist + nbDist < dist[nb]) {
                LOG(nb);
                LOG(curDist + nbDist);
                minH.push({curDist + nbDist, nb});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // REMEMBER TO COMMENT OUT IF NOT NEEDED
    while (t--) {
        solve();
    }
    return 0;
}
