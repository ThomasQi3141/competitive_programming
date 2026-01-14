#include <bits/stdc++.h>
using namespace std;

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

// template for factoring
vector<pair<int,int>> factor(int x) {
    vector<pair<int,int>> f;
    while (x > 1) {
        int p = spf[x], cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        f.push_back({p, cnt});
    }
    return f;
}