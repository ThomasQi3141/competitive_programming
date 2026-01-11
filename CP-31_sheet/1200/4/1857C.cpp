#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

void solve() {
    int64_t n;
    cin >> n;
    int64_t bSize = n * (n - 1) / 2;
    LOG(bSize);
    vector<int64_t> arr(bSize);
    for (int64_t &x : arr) {
        cin >> x;
    }
    LOG(arr[0]);
    // NOTE: by sorting, we get something like
    // min(A[0], A[1]), min(A[0], A[2]), min(A[1], A[2]) where A is sorted
    sort(arr.begin(), arr.end());
    // n-1 occ, n-2 occ, n-3 occ, ...
    int64_t inc = n - 1;
    int64_t i = 0;
    while (i < bSize && inc > 0) {
        cout << arr[i] << " ";
        i += inc;
        inc--;
    }
    // last number can be whatever, no restrictions
    // can just take last elem of B
    cout << arr[arr.size() - 1] << endl;
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
