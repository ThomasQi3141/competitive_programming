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

bool works(ll target, ll n, ll m, map<ll, ll> &workerCnt) {
    for (int i = 1; i <= n; i++) {
        if (workerCnt[i] > target) {
            // person i works target tasks at 1hr/task
            m -= target;
        } else {
            // person i works workerCnt[i] tasks at 1hr/task
            m -= workerCnt[i];
            // works the rest of the hours at 2hr/task
            m -= (target - workerCnt[i]) / 2;
        }
        if (m <= 0) {
            return true;
        }
    }
    return m <= 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    // binary search
    map<ll, ll> workerCnt;
    ll x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        workerCnt[x]++;
    }
    ll l = 0, r = 2 * m, mid, res;
    while (l <= r) {
        mid = (l + r) / 2;
        if (works(mid, n, m, workerCnt)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
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
