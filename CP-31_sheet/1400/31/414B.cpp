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

void solve() {
    ll n, k;
    cin >> n >> k;
    // O(n ^ {3/2} * k)
    // precompute factors -> factors[i] = factors of i
    vector<ll> factors[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                factors[i].push_back(j);
                if (j != i / j) {
                    factors[i].push_back(j / i);
                }
            }
        }
    }
    // note to self: allocation & deallocation take lots of time -> try not to have vectors/stl objs insite 
    // the loops to avoid lots of alloc/free time and try to precompute in a decidable loop as much as possible

    // (endNum, length) -> count
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    // initialize all 1-length sequences to be 1
    for (int i = 1; i <= n; i++) {
        dp[i][1]++;
    }
    // iterate on the length (i is the length of the subseq)
    for (int i = 2; i <= k; i++) {
        // go through 1 to n (j is the number)
        for (int j = 1; j <= n; j++) {
            // find all the factors, we can append these numbers after j
            for (ll factor : factors[j]) {
                // update DP
                dp[factor][i] = (dp[factor][i] + dp[j][i - 1]) % MOD;
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + dp[i][k]) % MOD;
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
