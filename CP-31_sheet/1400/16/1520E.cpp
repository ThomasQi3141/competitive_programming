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

void solve() {
    ll n;
    cin >> n;
    // why make it centered around middle sheep?
    // idea: for each start position x, change in cost = #left - #right
    // so at the middle, shifting left/right can't decrease the cost! -> minimum
    vector<ll> sheep;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '*') {
            sheep.push_back(i);
        }
    }
    ll middleIdx = (sheep.size() - 1) / 2;
    ll res = 0;
    // calculate cost of making sheep line around middle
    for (int i = middleIdx - 1; i >= 0; i--) {
        res += abs(sheep[i] - (sheep[middleIdx] - (middleIdx - i)));
    }
    for (int i = middleIdx; i < sheep.size(); i++) {
        res += abs(sheep[i] - (sheep[middleIdx] + (i - middleIdx)));
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
