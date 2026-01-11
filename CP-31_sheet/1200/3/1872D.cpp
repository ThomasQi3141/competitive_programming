#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

void solve() {
    // greedily put largest numbers in the n // x positions
    // then put the smallest numbers in the n // y positions
    int64_t n, x, y;
    cin >> n >> x >> y;
    // O(n // x + n // y)

    // find the # of common multiples from 1 to n = # multiples of gcd
    int64_t numMult = n / lcm(x, y);
    int64_t sumX1 = (n - n / x + numMult) * (n - n / x + numMult + 1) / 2;
    int64_t sumX2 = n * (n + 1) / 2;
    int64_t sumX = sumX2 - sumX1;
    int64_t sumY = (n / y - numMult) * (n / y - numMult + 1) / 2;
    cout << (sumX - sumY) << endl;
    // closed form: sum from (n - n / x + commonMult) to n -> 1 to n - 1 to (n - n / x + commonMult)
    // int cur = n;
    // int64_t res = 0;
    // for (int i = x; i <= n; i += x) {
    //     // if its true, then they cancel out, so can put whatever
    //     if (i % y == 0) {
    //         continue;
    //     }
    //     res += cur;
    //     cur--;
    // }
    // closed form: i = 1, i <= n / y - numCommonMult, i++

    // cur = 1;
    // for (int i = y; i <= n; i += y) {
    //     if (i % x == 0) {
    //         continue;
    //     }
    //     res -= cur;
    //     cur++;
    // }
    // cout << res << endl;
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