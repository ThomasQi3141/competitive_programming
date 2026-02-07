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
    // prefix[i] = number of negative in arr[:i]
    vector<ll> prefix(n);
    ll val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (i == 0) {
            if (val < 0) {
                prefix[0] = 1;
            }
            continue;
        }
        if (val < 0) {
            prefix[i] = prefix[i - 1] + 1;
        } else {
            prefix[i] = prefix[i - 1];
        }
    }
    LOG(prefix);
    ll resNeg = 0, resPos = 0;
    // number of arr[0:i] with even/odd negCount
    ll even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (prefix[i] % 2 == 0) {
            resNeg += odd;
            resPos += even;
            even++;
            resPos++; // this current [0:i] is positive
        } else {
            resNeg += even;
            resPos += odd;
            odd++;
            resNeg++; // this current [0:i] is negative
        }
    }
    cout << resNeg << " " << resPos << endl;
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
