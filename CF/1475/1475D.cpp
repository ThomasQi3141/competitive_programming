#include <bits/stdc++.h>
using namespace std;
// ============================ DEBUG ============================
// Enabled by -DLOCAL or -DDEBUG. Everything below compiles to nothing
// in a release build, so debug calls are free on the judge.
#if defined(LOCAL) || defined(DEBUG)
#define DBG_ON 1
#else
#define DBG_ON 0
#endif
 
#if DBG_ON
 
// ---- scalars -------------------------------------------------
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
// ---- forward declarations (needed for mutual recursion) -------
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename... Ts> void __print(const tuple<Ts...> &x);
template <size_t N> void __print(const bitset<N> &x);
 
// ---- generic iterable: vector, set, map, array, deque, ... ----
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << '}';
}
 
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
 
template <typename... Ts> void __print(const tuple<Ts...> &x) {
  int f = 0;
  cerr << '{';
  apply([&](const auto &...args) { ((cerr << (f++ ? ", " : ""), __print(args)), ...); }, x);
  cerr << '}';
}
 
template <size_t N> void __print(const bitset<N> &x) { cerr << x; }
 
// ---- adaptors: copied by value, so logging is non-destructive -
template <typename T, typename C> void __print(stack<T, C> s) {
  vector<T> v;
  while (!s.empty()) { v.push_back(s.top()); s.pop(); }
  reverse(v.begin(), v.end());  // bottom -> top
  __print(v);
}
template <typename T, typename C> void __print(queue<T, C> q) {
  vector<T> v;
  while (!q.empty()) { v.push_back(q.front()); q.pop(); }
  __print(v);  // front -> back
}
template <typename T, typename C, typename Cmp>
void __print(priority_queue<T, C, Cmp> pq) {
  vector<T> v;
  while (!pq.empty()) { v.push_back(pq.top()); pq.pop(); }
  __print(v);  // pop order
}
 
// ---- variadic driver -----------------------------------------
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
 
// ---- the macros ----------------------------------------------
// dbg(a, b, c) -> solve:42 [a, b, c] = [1, {2, 3}, "hi"]
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__ << "] = [";    \
    _print(__VA_ARGS__);                                                       \
    cerr << flush;                                                             \
  } while (0)
 
// LOG(x) -> [LOG] x = value      (same shape as before)
#define LOG(x)                                                                 \
  do {                                                                         \
    cerr << "[LOG] " << #x << " = ";                                           \
    __print(x);                                                                \
    cerr << "\n" << flush;                                                     \
  } while (0)
 
// LOGMAP(mp, "name") -> [LOG] name (size=2): {k: v, k: v}
template <class Map> void LOGMAP(const Map &mp, const string &name = "map") {
  cerr << "[LOG] " << name << " (size=" << mp.size() << "): {";
  bool first = true;
  for (const auto &[k, v] : mp) {
    if (!first) cerr << ", ";
    first = false;
    __print(k);
    cerr << ": ";
    __print(v);
  }
  cerr << "}\n" << flush;
}
 
#else
#define dbg(...) ((void)0)
#define LOG(x) ((void)0)
template <class Map> void LOGMAP(const Map &, const string & = "map") {}
#endif
// ========================== END DEBUG ==========================
 
using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> apps(n);
    for (pll &x : apps) cin >> x.first;
    for (pll &x : apps) cin >> x.second;
    // greedy in terms of ratio until we have cur >= m -> at most 1 extra app deleted
    // swap out one of our 2-costs for some other 1-cost OR take some 1 or 2-cost out? 

    // NOTE: a.f / a.s < b.f / b.s -> a.f * b.s < b.f * a.s!!! NO ROUNDING ERRORS! 
    sort(apps.begin(), apps.end(), [](auto a, auto b) { return a.first * b.second < b.first * a.second; });
    LOG(apps);
    ll mem = 0, conv = 0, pos = n - 1;
    ll min2Cost = INF, min1Cost = INF;
    while (mem < m) {
        if (pos < 0) {
            cout << -1 << endl;
            return;
        }
        // wanna make sure mem < m
        mem += apps[pos].first;
        conv += apps[pos].second;
        // keep track of the smallest 2-cost and 1-cost
        if (apps[pos].second == 2) {
            min2Cost = min(min2Cost, apps[pos].first);
        } else {
            min1Cost = min(min1Cost, apps[pos].first);
        }
        pos--;
    }
    // case 1: can take a 2-cost out
    if (min2Cost <= mem - m) {
        cout << conv - 2 << endl;
        return;
    }
    // case 2: can take 1-cost out
    if (min1Cost <= mem - m) {
        cout << conv - 1 << endl;
        return;
    }
    // if we have a 2-cost in our min config
    // see if we can swap out our smallest 2-cost with a 1-cost s.t. mem >= m still
    if (min2Cost != INF) {
        // case 3: swap out minimum 2-cost for remaining 1-cost
        while (pos >= 0) {
            if (apps[pos].second == 1 && min2Cost - apps[pos].first <= mem - m) {
                cout << conv - 1 << endl;
                return;
            }
            pos--;
        }
    }
    // if we can't find, then its just regular
    cout << conv << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // Keep in for codeforces
    while (t--) {
        solve();
    }
    return 0;
}
