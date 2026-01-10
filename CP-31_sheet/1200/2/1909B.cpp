#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<uint64_t> arr(n);
    for (uint64_t &x : arr) {
        cin >> x;
    }
    // 2 works in most cases, except when:
    // all are % 2 = 0 or all % 2 = 1
    // 2 4 6 8 10
    // when everything even, use 2, 4, 8, ... until it works
    uint64_t k = 1;
    while(k <= 1e18) {
        unordered_set<uint64_t> s;
        for (uint64_t x : arr) {
            s.insert(x % k);
        }
        if (s.size() == 2) {
            cout << k << endl;
            return;
        }
        k <<= 1;
    }
    cout << "BRUH" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}