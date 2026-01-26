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
    // 1 -> 2 -> 4 -> 8 -> 6 -> 2 etc... arbitrary number of times
    // 3 -> 6 -> 2
    // 5 -> 0 (stuck) 
    // 7 -> 4 -> 2
    // 9 -> 8 -> 6 -> 2
    // conclusion: 5 & 0 are stuck
    // for any number NOT ending in 5 or 0, we can get to (k * 10 + 2) in one cycle?
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll &x : arr) {
        cin >> x;
    }
    // %5 == 0 means ending w/ 5 or 0
    bool all5or0 = all_of(arr.begin(), arr.end(), [](auto x){ return x % 5 == 0; });
    bool any5or0 = any_of(arr.begin(), arr.end(), [](auto x){ return x % 5 == 0; });
    if (any5or0 && !all5or0) {
        cout << "NO" << endl;
        return;
    }
    // each number is x * 10 + c
    map<ll, ll> dist;
    if (all5or0) {
        // distance to 0
        dist[0] = 0;
        dist[5] = 1;
    } else {
        // "distance" to 2 -> k where x + 10 + c -> (x + k) * 10 + 2
        dist[1] = 0;
        dist[2] = 0;
        dist[3] = 1;
        dist[4] = 2;
        dist[6] = 1;
        dist[7] = 3;
        dist[8] = 2;
        dist[9] = 3;
    }
    if (all5or0) {
        // once it gets to 0 its stuck
        for (ll &x : arr) {
            if (x % 10 == 5) {
                x += 5;
            }
        }
        // & to capture all vars BY REFERENCE in the scope, so that we can use arr[0]
        if (all_of(arr.begin(), arr.end(), [&](auto x) { return x == arr[0]; })){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        
        for (ll &x : arr) {
            x = ((x / 10) + (dist[x % 10])) * 10 + 2;
        }
        // 2 to "next" 2 has a dist of 2
        // 2 -> 4 -> 8 -> 16 -> 22
        // so they can all be the same if x % 2 is same
        if (all_of(arr.begin(), arr.end(), [&](auto x) { return (x / 10) % 2 == (arr[0] / 10) % 2; })) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    LOG(arr);
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
