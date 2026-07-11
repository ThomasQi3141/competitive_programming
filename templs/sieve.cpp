#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Sieve {
        // initialize each SPF to i by deafult
        vector<ll> spf;
        int maxN;
        Sieve(int maxN = 2e5) : spf(maxN + 1), maxN(maxN) {
            for (int i = 0; i <= maxN; ++i) spf[i] = i;
        }
        void sieve() {
            for (int i = 2; i * i <= maxN; ++i) 
                if (spf[i] == i) // if still defaulted, go through all multiples of this and set it to i
                    for (int j = i * i; j <= maxN; j += i)
                        if (spf[j] == j) spf[j] = i;
        }
};

// template for factoring
vector<pair<ll, ll>> factor(ll x) {
    // contains (prime, power) for each prime factor
    vector<pair<ll, ll>> f;
    Sieve s;
    while (x > 1) {
        ll p = s.spf[x], cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        f.push_back({p, cnt});
    }
    return f;
}