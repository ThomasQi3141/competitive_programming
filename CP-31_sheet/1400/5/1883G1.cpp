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

bool works(ll k, const vector<ll> &A, const vector<ll> &B) {
    // remove k largest elem from A, k smallest elem from B
    for (int i = 0; i < A.size() - k; i++) {
        if (A[i] >= B[i + k]) {
            return false;
        }
    }
    return true;
}

// O(n log n)
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    A[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> A[i];
    }
    vector<ll> B(n);
    for (ll &x : B) {
        cin >> x;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll l = 0;
    ll r = n;
    ll mid, res;
    while (l <= r) {
        mid = (l + r) / 2;
        if (works(mid, A, B)) {
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
