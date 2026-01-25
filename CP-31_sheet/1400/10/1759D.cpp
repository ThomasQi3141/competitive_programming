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
#else
#define LOG(x) ((void)0)
#endif
using ll = long long;
const ll INF = 1e9;


void solve() {
    ll n, m;
    cin >> n >> m;
    // maximize (2 * 5) ^ x for some x in the PF of res
    ll cnt2 = 0;
    ll cnt5 = 0;
    ll cur = n;
    while (cur % 2 == 0) {
        cur /= 2;
        cnt2++;
    }
    cur = n;
    while (cur % 5 == 0) {
        cur /= 5;
        cnt5++;
    }
    // need largest x s.t. (cnt2x + cnt2) = (cnt5x + cnt5) = x
    // multiply by 2 when we need 2, multiply by 5 when we need 5, multiply by 10 when we need 10
    ll largestX = 1;
    ll x = 1;
    while (true) {
        if (cnt5 < cnt2) {
            if (x * 5 > m) break;
            x *= 5;
            cnt5++;
        } else if (cnt2 < cnt5) {
            if (x * 2 > m) break;
            x *= 2;
            cnt2++;
        } else {
            if (x * 10 > m) break;
            x *= 10;
            cnt2++;
            cnt5++;
        }
    }
    // now, just find largest multiple of x <= m -> equiv to (m / x) * x
    cout << (m / x) * x * n << endl;
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
