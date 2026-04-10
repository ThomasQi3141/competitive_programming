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
const ll INF = 1e10;
const ll MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<bool>> free(n, vector<bool>(m, false));
    ll r, c;
    cin >> r >> c;
    // 1-indexed
    r--;
    c--;
    ll x, y;
    cin >> x >> y;
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            free[i][j] = (line[j] == '.');
        }
    }
    vector<vector<ll>> dist(n, vector<ll>(m, INF));
    dist[r][c] = 0;
    // IDEA: the number of right moves = left + (currentColumn - originColumn)
    // so we want to minimize the number of left moves -> minimizes both!
    // dist is the minimum number of left moves it takes to get to (r, c)
    deque<pair<ll, ll>> q;
    q.push_back({r, c});
    vector<pair<ll, ll>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (q.size() > 0) {
        auto [row, col] = q.front();
        q.pop_front();
        for (auto [dx, dy] : dirs) {
            pair<ll, ll> nb = {row + dx, col + dy};
            ll weight = (dy == -1 ? 1 : 0);
            // if its in bounds & its free
            if (0 <= nb.first && nb.first < n && 0 <= nb.second && nb.second < m && free[nb.first][nb.second]) {
                // check if this improves the dist
                if (dist[row][col] + weight < dist[nb.first][nb.second]) {
                    dist[nb.first][nb.second] = dist[row][col] + weight;
                    if (weight == 0) {
                        // 0 left moves
                        q.push_front(nb);
                    } else {
                        // 1 left move
                        q.push_back(nb);
                    }
                }
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // need left to match right
            // NOTE: if we end up on right of c, we need extra j - c steps
            // if we end up on the left of c, we can use j - c less right steps
            ll rightCount = dist[i][j] + j - c;
            if (dist[i][j] <= x && rightCount <= y) {
                res++;
            }
        }
    }
    LOG(dist);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // REMEMBER TO COMMENT OUT IF NOT NEEDED
    while (t--) {
        solve();
    }
    return 0;
}
