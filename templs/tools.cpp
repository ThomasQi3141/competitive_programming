#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// function for mathematical mod
auto mod = [](int64_t a, int64_t m) -> int64_t {
    a %= m;
    if (a < 0) a += m;
    return a;
};

// quick way to get if n is a power of 2
bool isPow2(ll n) {
    if (n <= 0) {
        return false;
    }
    return !(n & (n - 1));
}