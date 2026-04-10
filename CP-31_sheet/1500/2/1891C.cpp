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
	ll n;
	cin >> n;
    // whenever current combo >= maxElem -> attack?
    // otherwise do attack 1 on smallest
    // 1 2 2 3 4 5
    multiset<ll> set;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        set.insert(x);
    }
    ll combo = 0, res = 0;
    while (set.size() > 0) {
        if (set.size() == 1) {
            // ceil
            if (combo >= *set.rbegin()) {
                combo = 0;
                set.erase(prev(set.end()));
                res++;
            } else {
                // special case for this one -> if x == 1 then only need to remove, no need to combo
                if (*set.rbegin() == 1) {
                    res++;
                    set.erase(prev(set.end()));
                } else {
                    // + 1 / 2 for the ceil effect -> need to apply att1 then combo
                    res += (*set.rbegin() - combo + 1) / 2 + 1;
                    set.erase(prev(set.end()));
                }
            }
            continue;
        }
        // combo >= biggest elem
        if (combo >= *set.rbegin()) {
            combo = 0;
            // have to use prev(set.end()) to give a NOT reverse iterator
            // rbegin() gives a reverse iterator, C++ doesn't take that
            set.erase(prev(set.end()));
            res++;
        } else {
            auto it = set.begin();
            ll num = *it;
            set.erase(it);
            res += num;
            combo += num;
        }
        LOG(combo);
        LOG(vector<ll>(set.begin(), set.end())); // doesn't run in non-debug settings
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
