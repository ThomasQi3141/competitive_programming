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
    map<ll, ll> cnt;
    ll val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        cnt[val]++;
    }
    vector<ll> counts;
    for (auto [key, val] : cnt) {
        counts.push_back(val);
    }
    sort(counts.begin(), counts.end());
    reverse(counts.begin(), counts.end());
    // each count can contribute to <= count times
    // current count
    ll cur = INF, res = 0;
    for (ll x: counts) {
        if (x >= cur) {
            if (cur > 0) {
                cur--;
            }
        } else {
            cur = x;
        }
        res += cur;
    }
    cout << res << endl;
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
