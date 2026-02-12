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

ll ask(ll i, ll j) {
    cout << "? " << i << " " << j << endl;
    cout.flush(); // NEED TO FLUSH
    ll x;
    cin >> x;
    return x;
}

// returns the 2 numbers that makes up prod
set<ll> getNums(ll prod, const set<ll>& vals) {
    for (ll x : vals) {
        if (prod % x == 0 && vals.contains(prod / x)) {
            return {x, prod / x};
        }
    }
    return {-1, -1};
}

// 4 8 15 16 23 42
// 2^2, 2^3, 3 * 5, 2^4, 23, 2 * 3 * 7
void solve() {
    set<ll> vals = {4, 8, 15, 16, 23, 42};
    // only need to confirm 5 positions, 6th one
    vector<ll> res;
    // we know exactly what 2 numbers it is, just not the position of them
    // using set so we can use set intersection
    set<ll> p12 = getNums(ask(1, 2), vals), p34 = getNums(ask(3, 4), vals), p15 = getNums(ask(1, 5), vals), p35 = getNums(ask(3, 5), vals);
    // insert the intersection between 12 and 15 -> res[0]
    set_intersection(p12.begin(), p12.end(), p15.begin(), p15.end(), back_inserter(res));
    // now, res[1] can be given from res[0]
    for (ll x : p12) {
        if (x != res[0]) {
            res.push_back(x);
        }
    }
    // same for res[2]
    set_intersection(p34.begin(), p34.end(), p35.begin(), p35.end(), back_inserter(res));
    // now get res[3] with the same idea
    for (ll x : p34) {
        if (x != res[2]) {
            res.push_back(x);
        }
    }
    // now get res[4] with the same idea
    for (ll x : p15) {
        if (x != res[0]) {
            res.push_back(x);
        }
    }
    // now, res[5] is just the remaining number
    for (ll x : vals) {
        // insert remaining thing left
        if (find(res.begin(), res.end(), x) == res.end()) {
            res.push_back(x);
            break;
        }
    }
    cout << "! ";
    for (int i = 0; i < 6; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    LOG(res);
    cout.flush();
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
