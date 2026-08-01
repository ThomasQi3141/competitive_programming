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
    // when 2 intersecting regions touch each other, its 1 region
    // for a given subset -> each touching region is like one group?

    // for each region x -> have the number of regions y ts is connected to
    // 2^n subsets
    // out of the 2^n-1 (if n > 1) subsets have this element
    // y of them don't contribute to anything when this interval included
    // consider all overlapping intervals into a group? 
    // sumof(y choose k for all k) that don't add anything * 
}

int main() {
    // file I/O
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    // file I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // Keep in for codeforces
    while (t--) {
        solve();
    }
    return 0;
}
