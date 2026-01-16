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

bool works(ll k, const vector<pair<ll, ll>> &arr) {
    // track furthest and smallest position we can get to from prev
    ll minPos = 0;
    ll maxPos = 0;
    LOG(k);
    for (ll i = 0; i < arr.size(); i++) {
        minPos = max(arr[i].first, minPos - k);
        maxPos = min(arr[i].second, maxPos + k);
        // [minPos, maxPos] = [prevMin - k, prevMax + k] \intersection [L, R]
        // if the intersection empty -> minPos > maxPos
        // can't just compare the endpoints to interval +/- k, might be in interval but >k dist from endpoints
        if (minPos > maxPos) {
            return false;
        }
        LOG(minPos);
        LOG(maxPos);
    }
    return true;
}

// O(n log k)
void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (auto &[x, y] : arr) {
        cin >> x >> y;
    }
    ll l = 0;
    ll r = INF;
    ll mid;
    ll res = INF;
    while (l <= r) {
        mid = (l + r) / 2;
        if (works(mid, arr)) {
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
