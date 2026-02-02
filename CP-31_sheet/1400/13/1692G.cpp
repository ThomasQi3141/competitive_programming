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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll &x : arr) {
        cin >> x;
    }
    // k indices s.t. arr[i] < 2 * arr[i + 1] -> equiv to 2^i * a[i] < 2^(i+1) * a[i+1] forall i
    ll greaterCnt = 0;
    for (int i = 1; i < k; i++) {
        if (arr[i] * 2 > arr[i - 1]) {
            greaterCnt++; 
        }
    }
    ll res = 0;
    for (int i = k; i < n; i++) {
        if (arr[i] * 2 > arr[i - 1]) {
            greaterCnt++;
        }
        if (greaterCnt == k) {
            res++;
        }
        if (arr[i - k] < 2 * arr[i - k + 1]) {
            greaterCnt--;
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
