#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

const int MAXN = 1e6; // replace w/ max of n
// smallest prime factor
int spf[MAXN + 1];

void sieve() {
    // initialize each SPF to i by default
    for (int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        // if still "defaulted"
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    // prime factorization for all -> yes if each count % len = 0
    int64_t n;
    cin >> n;
    map<int64_t, int64_t> count;
    int64_t x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        while (x > 1) {
            count[spf[x]]++;
            x /= spf[x];
        }
    }
    for (auto &[key, value] : count) {
        if (value % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    sieve();
    while (t--) {
        solve();
    }
    return 0;
}
