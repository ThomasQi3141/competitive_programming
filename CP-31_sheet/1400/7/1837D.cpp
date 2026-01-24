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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    // either valid or reverse-valid -> only 2 colors
    vector<ll> ans;
    ans.reserve(n);
    ll openCnt = 0;
    ll revClosedCnt = 0;
    for (char c : s) {
        if (c == '(') {
            if (revClosedCnt > 0) {
                revClosedCnt--;
                ans.push_back(2);
            } else {
                openCnt++;
                ans.push_back(1);
            }
        } else {
            if (openCnt > 0) {
                openCnt--;
                ans.push_back(1);
            } else {
                revClosedCnt++;
                ans.push_back(2);
            }
        }
    }
    if (openCnt > 0 || revClosedCnt > 0) {
        cout << -1 << endl;
    } else {
        // if all elem the same
        bool allSame = !ans.empty() && all_of(ans.begin(), ans.end(), [&](auto x){ return x == ans[0]; });
        if (allSame) {
            cout << 1 << endl;
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
        } else {
            cout << 2 << endl;
            for (ll & x : ans) {
                cout << x << " ";
            }
        }
        cout << endl;
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
