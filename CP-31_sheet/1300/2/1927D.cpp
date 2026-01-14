#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

// O(n * q)
void solve() {
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    for (int64_t &x : arr) {
        cin >> x;
    }
    int64_t q;
    cin >> q;
    int64_t l, r;
    // track the last index where arr[i] \neq arr[i + 1]
    vector<int64_t> prefix(n);
    prefix[0] = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            prefix[i] = i;
        } else {
            prefix[i] = prefix[i - 1];
        }
    }
    for (int x : prefix) {
        cerr << x << " ";
    }
    while(q > 0) {
        cin >> l >> r;
        // 1-indexed -> 0-indexed
        l--;
        r--;
        if (prefix[r] == -1 || prefix[r] - 1 < l) {
            cout << "-1 -1" << endl;
        } else {
            // 0-indexed to 1-indexed
            cout << prefix[r] << " " << prefix[r] + 1 << endl;
        }
        q--;
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
