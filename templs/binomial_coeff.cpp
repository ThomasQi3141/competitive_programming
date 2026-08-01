#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9+7;

ll binomial_dp (ll n, ll k) {
    // dp[i][j] = iCj
    vector<vector<ll>>dp(n + 1, vector<ll>(k + 1, 0));
    for (int i = 0; i <= n; ++i) {
        // iC0 = 1 forall i
        dp[i][0] = 1;
        // iCi = 1 forall i
        if (i <= k) dp[i][i] = 1;
    }

    for (ll i = 0; i <= n; i++) {
        // need to take min of i and k because iCj where j > i is undefined-ish
        for (ll j = 1; j <= min(i, k); ++j) {
            if (i != j) // skip over base case  
                // can also take care of the MOD here
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    return dp[n][k];
}

// gives x^n mod MOD in O(log MOD) time
ll exp(ll x, ll n) {
    x %= MOD;
    ll res = 1;
    while (n > 0) {
        // works because n/2 floors it either way
        if (n % 2 == 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

// binomial using modular inverse via FlT
// NOTE: this only works for p > n!!!
ll binomial_modinv (ll n, ll k) {
    // calculate n! % MOD
    vector<ll> fact(n + 1);
    vector<ll> inv(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    // calculate modular inverse factorials -> inv[i] = (i!)^-1
    // NOTE: (i!)^-1 * i = ((i-1)!)^-1
    // by FLT a^p-2 is the modular inverse of a mod p
    inv[n] = exp(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) inv[i] = ((i + 1) * inv[i + 1]) % MOD;
    ll res = (fact[n] * inv[k]) % MOD;
    res = (res * inv[n - k]) % MOD;
    return res;
}