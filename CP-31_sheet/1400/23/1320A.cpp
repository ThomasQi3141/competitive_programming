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
    vector<ll> B(n);
    for(ll &x : B) {
        cin >> x;
    }
    // maximize sum of b
    // c_i+1 - c_i = b_i+1 - b_i <-> c_i+1 - b_i+1 = c_i - b_i
    // dp[i] = c_i-b_i -> maxBeauty
    map<ll, ll> dp;
    for (int i = 0; i < n; i++) {
        // no reason not to add current val to the list
        dp[i - B[i]] += B[i];
    }
    // get max value from dp
    cout << max_element(dp.begin(), dp.end(), [](auto a, auto b) { return a.second < b.second; })->second << endl;
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
