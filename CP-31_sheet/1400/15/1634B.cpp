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

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll curParity = 0;
    ll curNum;
    for (int i = 0; i < n; i++) {
        cin >> curNum;
        if (curNum % 2 != curParity) {
            curParity = 1;
        } else {
            curParity = 0;
        }
    }
    if ((x + curParity) % 2 == y % 2) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    // PARITY?????
    // x and x + 3 have DIFF parity! -> can just check parity of y against this
    // for +: same -> even, diff -> odd
    // for ^: same -> even, diff -> odd
    // both operations end up with the same parity
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
