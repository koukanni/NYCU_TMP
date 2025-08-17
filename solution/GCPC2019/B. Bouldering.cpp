#pragma GCC optimize("Ofast,unroll-loops")

#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <limits>
#include <iostream>
#include <chrono>
#include <queue>
#include <random>
#include <functional>
#include <vector>
#include <bitset>
#include <ranges>

using namespace std;

#ifdef LOCAL
#include "debug"
#else
#define debug(...)
#endif

using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = int(1e9);
template <>
constexpr int64_t infty<int64_t> = int64_t(1e18);
template <>
constexpr __int128_t infty<__int128_t> = __int128_t(1e36);
template <>
constexpr double infty<double> = 1e30;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fi first
#define se second

template<class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, true : false);
}
template<class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, true : false);
}
constexpr f64 inf = f64(1E30);
constexpr f64 eps = f64(1E-12);
constexpr usize maxn = 26;
int H, W, R, T, value[maxn * maxn];
string S[maxn];
f64 dis[maxn * maxn][10 * maxn * maxn];
vector<pair<int, f64>> adj[maxn * maxn];
inline int id(int x, int y) {
  return W * (x - 1) + y;
}
int get(int x, int y, int u, int v) {
  return (u - x) * (u - x) + (v - y) * (v - y);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> H >> W >> R >> T;
  rep (i, 1, H) cin >> S[i], S[i] = '$' + S[i];
  rep (i, 1, H) rep (j, 1, W) if (S[i][j] != '.') value[id(i, j)] = int(S[i][j] - '0');
  rep (i, 1, H) rep (j, 1, W) if (S[i][j] != '.') {
    const int x = id(i, j);
    rep (k, 1, H) rep (l, 1, W) if (S[k][l] != '.') {
      const int y = id(k, l);
      const auto w = get(i, j, k, l);
      if (x != y and w <= R * R) {
        adj[x].emplace_back(y, sqrt(w));
      }
    }
  }
  const int V = H * W;
  const int maxT = min(T, H * W * 9);
  int lo, hi;
  per (i, H, 1) rep (j, 1, W) if (S[i][j] != '.') lo = id(i, j);
  rep (i, 1, H) rep (j, 1, W) if (S[i][j] != '.') hi = id(i, j);
  rep (i, 1, V) rep (j, 0, maxT) dis[i][j] = inf;
  dis[lo][value[lo]] = 0;
  priority_queue<tuple<f64, int, int>, vector<tuple<f64, int, int>>, greater<>> h;
  h.emplace(dis[lo][value[lo]], value[lo], lo);
  while (not h.empty()) {
    const auto [d, s, x] = h.top();
    h.pop();
    if (abs(dis[x][s] - d) > eps) {
      continue;
    }
    for (const auto &[y, w] : adj[x]) {
      const int ns = s + value[y];
      if (ns <= maxT and chmin(dis[y][ns], d + w)) {
        h.emplace(dis[y][ns], ns, y);
      }
    }
  }
  f64 ANS = inf;
  rep (s, 0, maxT) chmin(ANS, dis[hi][s]);
  if (ANS >= inf) {
    cout << "impossible\n";
  } else {
    cout << fixed << setprecision(17) << ANS << '\n';
  }
  return 0;
}