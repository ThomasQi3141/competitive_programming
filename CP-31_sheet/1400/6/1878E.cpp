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

bool works(ll l, ll k, ll r, const vector<array<pair<ll, ll>, 32>> &prefix) {
    ll number = 0;
    for (int i = 0; i < 32; i++) {
        auto [zeroCnt, oneCnt] = prefix[r][31 - i];
        if (l > 0) {
            zeroCnt -= prefix[l - 1][31 - i].first;
            oneCnt -= prefix[l - 1][31 - i].second;
        }
        
        if (zeroCnt == 0 && oneCnt > 0) {
            number |= (1ULL << (31 - i)); // set bit to 1
        } else {
            number &= ~(1ULL << (31 - i)); // set bit to 0
        }
    }
    return number >= k;
}

ll bs(ll left, ll k, const vector<array<pair<ll, ll>, 32>> &prefix) {
    ll l = left;
    ll r = prefix.size() - 1;
    ll mid;
    ll res = INF;
    while (l <= r) {
        mid = (l + r) / 2;
        if (works(left, k, mid, prefix)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll &x : arr) {
        cin >> x;
    }
    // per-bit prefix counts
    // prefix[i][jth bit][0cnt][1cnt]
    vector<array<pair<ll, ll>, 32>> prefix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (i > 0) {
                prefix[i][j] = prefix[i - 1][j];
            }
            // == has higher precedance than & LMAO, need quotation around &1
            if (((arr[i] >> j) & 1LL) == 0) {
                prefix[i][j].first++;
            } else {
                prefix[i][j].second++;
            }
        }
    }
    ll q;
    cin >> q;
    ll l, k;
    for (int i = 0; i < q; i++) {
        cin >> l >> k;
        l--;
        ll searchResult = bs(l, k, prefix);
        cout << (searchResult == INF ? -1 : searchResult + 1) << " ";
    }
    cout << endl;
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