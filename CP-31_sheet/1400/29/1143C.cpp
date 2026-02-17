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

vector<ll> res;

// returns if all children dont respect
bool dfs(ll node, vector<vector<ll>> &children, vector<bool> &respect) {
    bool dfsResult = true;
    for (ll x : children[node]) {
        dfsResult = dfs(x, children, respect) && dfsResult;
    }
    // none of children respect it + doesn't respect
    if (dfsResult && !respect[node]) {
        res.push_back(node);
    }
    return !respect[node];
}

void solve() {
    // delete i s.t. ci = 1 and ci = 1 for all children
    ll n;
    cin >> n;
    vector<vector<ll>> children(n + 1);
    vector<bool> respect(n + 1);
    ll p, c, root;
    for (int i = 1; i <= n; i++) {
        cin >> p >> c;
        if (p != -1) {
            children[p].push_back(i);
        } else {
            root = i;
        }
        respect[i] = (c == 0);
    }
    // all nodes outputted will be in a "path" of not respect! -> figure them out with DFS then sort
    res.clear(); // clear res from last run first
    dfs(root, children, respect);
    // return -1 if nothing
    if (res.size() == 0) {
        cout << -1 << endl;
        return;
    }
    sort(res.begin(), res.end());
    for (ll x : res) {
        cout << x << " ";
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
