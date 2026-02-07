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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }
    // dp[i][x] = max height ending with a player from [0]=none, [1] = first, [2] = second
    vector<array<ll, 3>> dp(n);
    dp[0][1] = arr[0].first;
    dp[0][2] = arr[0].second;
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0] + arr[i].first, dp[i - 1][2] + arr[i].first);
        dp[i][2] = max(dp[i - 1][0] + arr[i].second, dp[i - 1][1] + arr[i].second);
    }
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
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
