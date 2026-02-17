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
    ll n, m, k;
    cin >> n >> m >> k;
    // min heap of gaps
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> minH;
    vector<ll> arr(n);
    cin >> arr[0];
    // get remaining n - 1 positions
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        minH.push({arr[i] - arr[i - 1], arr[i - 1], arr[i]});
    }
    // just avoid the largest gaps via a heap
    // have to patch the smallest n - k gaps -> the rest of the positions only contribute to 1
    map<ll, ll> diff;
    ll res = 0;
    ll gapsToPatch = n - k;
    while (minH.size() > 0 && gapsToPatch > 0) {
        auto [curGap, a, b] = minH.top();
        minH.pop();
        diff[a]++;
        diff[b]--;
        LOG(res);
        res += curGap;
        gapsToPatch--;
    }
    // diff map to check if this is in a gap we bridged -> if it is, ignore
    ll curDiff = 0;
    for (int i = 0;i < n; i++) {
        curDiff += diff[arr[i]];
        if (curDiff == 1) {
            continue;
        } else {
            res++;
        }
    }
    cout << res << endl;
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
