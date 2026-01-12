#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

auto mod = [](int64_t a, int64_t m) -> int64_t {
    a %= m;
    if (a < 0) a += m;
    return a;
};

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

void solve() {
    int64_t n, x, y;
    cin >> n >> x >> y;
    vector<int64_t> arr(n);
    for (int64_t &val : arr) {
        cin >> val;
    }
    // need (a[i] + a[j]) % x = 0 -> -1 * a[i] % x = a[j] % x
    // need (a[i] - a[j]) % y = 0 -> a[i] % y = a[j] % y
    // (modX, modY) -> count
    uint64_t res = 0;
    unordered_map<pair<int64_t, int64_t>, int64_t, PairHash> modCnt;
    for (int64_t val : arr) {
        // NOTE: in c++ the % keeps the sign, so it can be negative & needs normalization
        res += modCnt[{mod(-val, x), mod(val, y)}];
        modCnt[{mod(val, x), mod(val, y)}]++;
    }
    cout << res << endl;
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
