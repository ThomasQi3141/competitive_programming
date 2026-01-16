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
    // if k >= 3 -> we can ALWAYS get 0
    // first apply k on same elements twice, then apply on the 2 same elem to get 0
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    // otherwise 1 <= k <= 2
    if (k == 1) {
        sort(arr.begin(), arr.end());
        ll curMin = arr[0];
        for (int i = 1; i < n; i++) {
            curMin = min(curMin, arr[i] - arr[i - 1]);
        }
        cout << curMin << endl;
    } else {
        sort(arr.begin(), arr.end());
        ll curMin = arr[0];
        for (int i = 1; i < n; i++) {
            curMin = min(curMin, arr[i] - arr[i - 1]);
        }
        vector<ll> diffs;
        diffs.reserve(n * n);
        // apply twice -> can also get diffs & add them
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diffs.push_back(abs(arr[i] - arr[j]));
            }
        }
        sort(diffs.begin(), diffs.end());
        // 2-pointer approach to get min diff between diffs and arr
        ll pos = 0;
        for (int i = 0; i < n; i++) {
            while (pos < diffs.size()) {
                curMin = min(curMin, abs(arr[i] - diffs[pos]));
                if (diffs[pos] >= arr[i]) {
                    break;
                }
                pos++;
            }
        }
        LOG(arr);
        LOG(diffs);
        cout << curMin << endl;
    }
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
