#include <bits/stdc++.h>
using namespace std;

static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
struct PairHash {
    size_t operator()(const pair<long long,long long>& p) const noexcept {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        uint64_t a = splitmix64((uint64_t)p.first + FIXED_RANDOM);
        uint64_t b = splitmix64((uint64_t)p.second + FIXED_RANDOM);
        return a ^ (b + 0x9e3779b97f4a7c15 + (a<<6) + (a>>2)); // combine
    }
};