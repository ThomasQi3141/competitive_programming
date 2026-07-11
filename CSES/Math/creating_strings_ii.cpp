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

ll exp(ll x, ll n) {
    x %= MOD;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    map<char, int> count;
    for (char c: s) {
        count[c] += 1;
    }
    ll n = s.size();
    vector<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) 
        fact[i] = (i * fact[i - 1]) % MOD;
    vector<ll> inv(n + 1);
    inv[n] = exp(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) 
        inv[i] = ((i + 1) * inv[i + 1]) % MOD;
    // need to return n! / prod(c!) for each count
    ll res = fact[n];
    for (auto &[key, val] : count) {
        res = (res * inv[val]) % MOD;
    }
    LOG(fact);
    LOG(inv);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // REMEMBER TO COMMENT OUT IF NOT NEEDED
    while (t--) {
        solve();
    }
    return 0;
}
