#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

struct LLHash {
    static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

    size_t operator()(int64_t x) const noexcept {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return (size_t)splitmix64((uint64_t)x + FIXED_RANDOM);
    }
};

void solve() {
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    // prefix sum -> when odd subtract, when even add
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> arr[i];
        } else {
            int64_t x;
            cin >> x;
            if (i % 2 == 0) {
                arr[i] = arr[i - 1] + x;
            } else {
                arr[i] = arr[i - 1] - x;
            }
        }
    }
    // NOTE: unordered_set with custom hash has similar performance to regular set (log n) time
    unordered_set<int64_t, LLHash> seen;
    for (int64_t x : arr) {
        if (x == 0 || seen.contains(x)) {
            cout << "YES" << endl;
            return;
        }
        seen.insert(x);
    }
    cout << "NO" << endl;
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