// dbg.h -- local-only debug helpers. Never submitted; the template
// only includes this when compiled with -DLOCAL (or -DDEBUG).
#pragma once
#include <bits/stdc++.h>
using namespace std;

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
// Maps print as {k: v, ...}; everything else as {a, b, ...}.
template <typename T, typename = void> struct is_map_like : false_type {};
template <typename T>
struct is_map_like<T, void_t<typename T::mapped_type>> : true_type {};

template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (const auto &i : x) { // const& so vector<bool> works
    cerr << (f++ ? ", " : "");
    if constexpr (is_map_like<T>::value) {
      __print(i.first);
      cerr << ": ";
      __print(i.second);
    } else {
      __print(i);
    }
  }
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
  apply(
      [&](const auto &...args) {
        ((cerr << (f++ ? ", " : ""), __print(args)), ...);
      },
      x);
  cerr << '}';
}

template <size_t N> void __print(const bitset<N> &x) { cerr << x; }

// ---- adaptors: copied by value, so logging is non-destructive -
template <typename T, typename C> void __print(stack<T, C> s) {
  vector<T> v;
  while (!s.empty()) {
    v.push_back(s.top());
    s.pop();
  }
  reverse(v.begin(), v.end()); // bottom -> top
  __print(v);
}
template <typename T, typename C> void __print(queue<T, C> q) {
  vector<T> v;
  while (!q.empty()) {
    v.push_back(q.front());
    q.pop();
  }
  __print(v); // front -> back
}
template <typename T, typename C, typename Cmp>
void __print(priority_queue<T, C, Cmp> pq) {
  vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  __print(v); // pop order
}

// ---- variadic driver -----------------------------------------
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(const T &t, const V &...v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
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
