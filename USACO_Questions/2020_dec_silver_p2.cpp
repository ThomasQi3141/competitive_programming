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

// returns the total number of points bounded by the rectangle (x1, y1), (x2, y2) (assume x1 < x2), (y1 < y2)
ll totalPoints (const vector<vector<ll>> &prefix, ll x1, ll y1, ll x2, ll y2) {
    return prefix[x2][y2] - prefix[x1 - 1][y1 - 1] - prefix[x2 - 1][y1 - 1] - prefix[x1 - 1][y2 - 1];
}

bool compY(pll a, pll b) {
    return a.second < b.second;
}

void solve() {
    ll n;
    cin >> n;
    vector<pll> points(n);
    // do coordinate compression on x (how they rank against each other) and y
    for (auto &[x, y] : points)
        cin >> x >> y;
    // compress the coordinates on how they rank to each other
    sort(points.begin(), points.end());
    for (int i = 0; i < n; ++i)
        points[i].first = i;
    sort(points.begin(), points.end(), compY);
    for (int i = 0; i < n; ++i)
        points[i].second = i;
    // do a prefix sum of how many points there are
    vector<vector<ll>> prefix(n + 1, vector<ll>(n + 1, 0));
    // prefix[i][j] = number of points with x < i, y < j
    // do the + 1 method so that you can ALWAYS take -1
    for (auto &[x, y] : points)
        prefix[x + 1][y + 1] += 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            // subtract prefix[i - 1][j - 1] since its added twice
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    // NOTE: 
    ll res = 0;
    for (int i = 1; i <= n; ++i) 
        for (int j = i + 1; j <= n; ++j) {
            // NOTE: since points is sorted based on j == points[i][0][1] 
            ll minX = min(points[i].first, points[j].first), maxX = max(points[i].first, points[j].first);
            
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // Keep in for codeforces
    while (t--) {
        solve();
    }
    return 0;
}
