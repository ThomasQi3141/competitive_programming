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
    ll n, m;
    cin >> n >> m;
    // color -> list of row/col indices
    map<ll, vector<ll>> rowIndices;
    map<ll, vector<ll>> colIndices;
    ll x;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> x;
            rowIndices[x].push_back(r);
            colIndices[x].push_back(c);
        }
    }
    LOGMAP(rowIndices, "rowind");
    LOGMAP(colIndices, "colind");
    // - calculate x and y dist separately
    // need to get sum of all a < b, v[b] - b[a]
    // or -> i * v[i] - (sum of j {0 to i-1} v[j])
    // use a prefix sum to compute
    ll res = 0, prefix = 0;
    for (auto &[_, vec] : rowIndices) {
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++) {
            res += i * vec[i] - prefix;
            prefix += vec[i];
        }
        prefix = 0;
    }
    for (auto &[_, vec] : colIndices) {
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++) {
            res += i * vec[i] - prefix;
            prefix += vec[i];
        }
        prefix = 0;
    }
    cout << res << endl;
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
