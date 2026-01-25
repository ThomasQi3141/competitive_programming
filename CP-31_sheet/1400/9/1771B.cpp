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
    // for each right index find the leftmost index s.t. it doesn't include an entire interval
    ll n, m;
    cin >> n >> m;
    // addSet, removeSet
    vector<ll> diffArr(n, -1);
    ll a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        diffArr[max(a, b)] = max(diffArr[max(a, b)], min(a, b));
    }
    // keep track of largest L s.t. [L, R] \in [0, i]
    ll curMaxL = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        curMaxL = max(curMaxL, diffArr[i] + 1);
        LOG(i);
        LOG(curMaxL);
        ll subLen = (i - curMaxL + 1);
        // [curMax, i] works -> all x s.t. x >= curMax works -> [x, i]
        res += subLen;
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
