#include <bits/stdc++.h>
using namespace std;
// macros for logging in cerr
#ifdef LOCAL
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

#define LOG(x) cerr << "[LOG] " << #x << " = " << (x) << "\n"

template <class Map>
void LOGMAP(const Map& mp, const string& name = "map") {
    cerr << "[LOG] " << name << " (size=" << mp.size() << "): {";
    bool first = true;
    for (const auto& [k, v] : mp) {
        if (!first) cerr << ", ";
        first = false;
        cerr << k << ": " << v;
    }
    cerr << "}\n";
}

#else
#define LOG(x) ((void)0)
template <class Map>
void LOGMAP(const Map&, const string& = "map") { /* no-op */ }
#endif
using ll = long long;
const ll INF = 1e9;

void solve() {
    ll n;
    cin >> n;
    vector<ll> u(n);
    for (ll &x : u) {
        cin >> x;
    }
    // IDEA: basically totalSum - n % k weakest students from each uni (can just use a prefix sum to determine that)
    // university -> list of skills
    map<ll, vector<ll>> skills;
    // sum of all skill
    ll x;
    ll totalSkill = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        skills[u[i]].push_back(x);
        totalSkill += x;
    }
    // wastedSkill[i] = total wasted skill for choosing k = i + 1
    vector<ll> wastedSkill(n);
    vector<ll> diff(n + 1);
    // remaining wastedSkill entries should be totalSkill (can't reach this anyways)
    for (auto &[key, vec] : skills) {
        // make sure the 
        sort(vec.begin(), vec.end());
        // turn vec into a prefix
        for (int i = 1; i < vec.size(); i++) {
            vec[i] += vec[i - 1];
        }
        LOG(vec);
        for (int i = 0; i < vec.size(); i++) {
            ll idx = vec.size() % (i + 1) - 1;
            if (idx == -1) {
                // no wasted skill if is % (i+1) = 0
                continue;
            }
            wastedSkill[i] += vec[idx];
        }
        // last elem of vec is vecsum, keep track for when they can't make a team
        diff[vec.size()] += vec[vec.size() - 1];
    }
    // we also have to consider when a uni can't make a singular team -> use a diff array for that

    LOG(wastedSkill);
    LOG(diff);
    ll missedTeamDiff = 0;
    for (int i = 0; i < n; i++) {
        missedTeamDiff += diff[i];
        cout << totalSkill - wastedSkill[i] - missedTeamDiff << " ";
    }
    cout << endl;
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
