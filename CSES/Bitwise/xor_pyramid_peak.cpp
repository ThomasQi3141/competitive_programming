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
const ll MOD = 2;

void solve() {
    // think of the pyramid in reverse
    // x1 x2 x3 x4 x5
    // x1+x2 x2+x3 x3+x4 x4+x5
    // x1+2x2+x3 x2+2x3+x4 x3+2x4+x5
    // x1+3x2+3x3+x4 x2+3x3+3x4+x5
    // x1+4x2+6x3+4x4+x5
    // n elem list-> ith element contributes to the ith column amount in pascals triangle
    // n-1 choose i for each element
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &ll : arr) cin >> ll;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        // if n C i is odd, then i actually apply this
        // otherwise arr[i] gets applied an even number of times -> cancels out to 0
        if ((i & (n - 1)) == i) { // gets if n-1Ci is odd
            res ^= arr[i];
        }
    }
    cout << res << endl;
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
