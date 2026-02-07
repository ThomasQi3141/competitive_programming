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
    // variation of longest increasing subseq?
    // each index has to be a multiple of the prev and greater
    // idx -> cnt
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // O(n log n) approx?? 
    vector<ll> dp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (arr[j] > arr[i]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;;
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
