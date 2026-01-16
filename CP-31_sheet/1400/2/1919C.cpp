#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"
using ll = long long;
const ll INF = 1e9;


void solve() {
    ll n;
    cin >> n;
    ll bucketA = INF;
    ll bucketB = INF;
    // if both no penalty OR both penalty -> put in the bucket with smaller last elem
    ll x;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (bucketA < x && bucketB < x) {
            // penalty for both, put in smaller
            if (bucketA < bucketB) {
                bucketA = x;
            } else{
                bucketB = x;
            }
            res++;
        } else if (bucketA < x && bucketB >= x) {
            // bucket B no penalty
            bucketB = x;
        } else if (bucketA >= x && bucketB < x) {
            // bucket A no penalty
            bucketA = x;
        } else {
            // both no penalty, choose smaller
            if (bucketA < bucketB) {
                bucketA = x;
            } else {
                bucketB = x;
            }
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
