#include <bits/stdc++.h>
using namespace std;
// g++-15 -std=gnu++23 -O2 main.cpp

// solve one test case
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) {
        cin >> x;
    }
    // true for all k > 1
    if (k > 1) {
        cout << "YES" << endl;
        return;
    }
    // for k == 1 check if its already sorted, if not, then no
    for (int i = 0; i < arr.size() - 1; i ++) {
        if (arr[i] > arr[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // comment out for single test
    while (t--) {
        solve();
    }
    return 0;
}
