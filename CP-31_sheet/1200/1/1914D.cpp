#include <bits/stdc++.h>
using namespace std;
// g++-15 -std=gnu++23 -O2 main.cpp

void solve() {
    int n;
    cin >> n;
    // a, b, c
    vector<array<int, 3>> arr(n);
    for (auto &x : arr) {
        cin >> x[0];
    }
    for (auto &x : arr) {
        cin >> x[1];
    }
    for (auto &x : arr) {
        cin >> x[2];
    }
    vector<array<int, 8>> dp(n);
    // dp[i][state] = max using arr[:i] ending with state
    // state = abc (binary) to decimal
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[0][0] = 0;         // 000
            dp[0][4] = arr[0][0]; // 100
            dp[0][2] = arr[0][1]; // 010
            dp[0][1] = arr[0][2]; // 001
            continue;
        }
        // update all states of dp[i]
        for (int k = 0; k < 8; ++k) {
            // can always use state from prev
            dp[i][k] = dp[i - 1][k];
            for (int j = 0; j < 3; ++j) {
                if ((k >> (2 - j)) & 1 == 1) {
                    // set jth bit (from left to right) to 0
                    int prevState = k & ~(1 << (2 - j));
                    dp[i][k] = max(dp[i][k], dp[i - 1][prevState] + arr[i][j]);
                }
            }
        }
    }
    // return max elem of last row
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
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