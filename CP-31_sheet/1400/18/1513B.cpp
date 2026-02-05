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

// return true if b is a bitwise superset of a
bool isSuperSet(ll a, ll b) {
    for (int i = 0; i < 32; i++) {
        if (((a >> i) & 1 == 1) && ((b >> i) & 1 == 0)) {
            return false;
        }
    }
    return true;
}

void solve() {
    // global AND <= smaller number
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll minVal = INF, globalAnd = -INF;
    for (ll &x : arr) {
        cin >> x;
        minVal = min(minVal, x);
        if (globalAnd == -INF) {
            globalAnd = x;
        } else {
            globalAnd &= x;
        }
    }
    // if min val >= global AND then its impossible
    LOG(minVal);
    LOG(globalAnd);
    if (minVal > globalAnd) {
        cout << 0 << endl;
        return;
    }
    // elements after the first one ALL have to be a bitwise superset of the minVal
    // we need a minVal at the start and the end
    if (!all_of(arr.begin(), arr.end(), [&](ll x) { return isSuperSet(minVal, x); })) {
        LOG("NOTSUPERSET");
        cout << 0 << endl;
        return;
    }
    // now, all counts of minVal must be at the start/end, all other elements can be placed whereever
    ll minCnt = count(arr.begin(), arr.end(), minVal);
    // nP2 = (n!) / (n - 2)! = minCnt * (minCnt - 1) ways to place the minVals
    // -> minCnt * (minCnt - 1) * (n-2)! ways in total
    ll fact = 1;
    for (int i = 1; i <= n - 2; i++) {
        fact = (fact * i) % MOD;
    }
    fact = (fact * minCnt) % MOD;
    fact = (fact * (minCnt - 1)) % MOD;
    cout << fact << endl;
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