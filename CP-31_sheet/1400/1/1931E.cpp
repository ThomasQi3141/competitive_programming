#include <bits/stdc++.h>
using namespace std;
#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"
using ll = long long;

// O(log n)
ll calc0s(ll x) {
    // gets number of trailing 0s
    ll res = 0;
    while (x % 10 == 0) {
        x /= 10;
        res++;
    }
    return res;
}

ll digits(ll x) {
    x = llabs(x);
    return (int)to_string(x).size();
}

void printNums(multiset<pair<ll, ll>> &nums) {
    for (auto &[a, b] : nums) {
        cerr << "(" << a << "," << b << ")" << "";
    }
    cerr << endl;
}


void solve() {
    ll n, m;
    cin >> n >> m;
    // anna wants to choose numbers like x * 10 ** y -> the bigger the better
    // sasha wants to concat to minimize anna from reversing -> concat smallest trailing 0 with biggest trailing 0
    multiset<pair<ll, ll>> nums; // multiset is basically sortedlist -> O(log n) add/remove & O(1) min/max
    // only keep track of trailing 0s & number of total digits
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        nums.insert({calc0s(x), digits(x)});
    }
    ll turn = 0;
    // make sure at least anna plays
    while (nums.size() > 1 || turn == 0) {
        if (turn % 2 == 0) {
            // anna -> reverse biggest trailing 0
            // erase by iterator = remove that instance
            auto it = prev(nums.end()); // max trailing 0 -> after era
            // note: rbegin is a reverse iterator so doesn't work w/ erase
            nums.insert({0, it->second - it->first});
            // erase after using the values, if erase first its undefined behaviour
            nums.erase(it);
        } else {
            // sasha -> concat smallest trailing 0 with biggest trailing 0
            auto minIt = nums.begin();
            auto maxIt = prev(nums.end());
            // concat w/ minIt at the end
            nums.insert({minIt->first, minIt->second + maxIt->second});
            nums.erase(minIt);
            nums.erase(maxIt);
        }
        turn++;
        LOG(turn);
    }

    if (nums.begin()->second > m) {
        cout << "Sasha" << endl;
    } else {
        cout << "Anna" << endl;
    }
    return;
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
