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
    // dependent on the largest [count, k - (n % k)]
    // something like k - (n % k) + (count - 1) * k
    map<ll, ll> modCnt;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % k == 0) {
            continue;
        }
        modCnt[k - (x % k)]++;
    }
    if (modCnt.size() == 0) {
        cout << 0 << endl;
        return;
    }
    pair<ll, ll> maxPair = {0, 0};
    for (auto [key, val] : modCnt) {
        maxPair = max(maxPair, {val, key});
    }
    cout << (maxPair.first - 1) * k + maxPair.second + 1 << endl;
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
