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
constexpr usize maxn = 200005;
int N, K, ptr, reach;
int L[maxn], R[maxn], ANS[maxn];
void dfs(int x, int d) {
  if (d == K) {
    reach = 1;
    return;
  }
  if (ptr < N) {
    L[x] = ++ptr;
    dfs(L[x], d + 1);
  }
  if (ptr < N) {
    R[x] = ++ptr;
    dfs(R[x], d + 1);
  }
}
void dfs2(int x) {
  if (L[x]) {
    dfs2(L[x]);
  }
  ANS[x] = ptr++;
  if (R[x]) {
    dfs2(R[x]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;
  ptr = 1;
  dfs(1, 1);
  if (ptr < N or not reach) {
    cout << "impossible\n";
    return 0;
  }
  ptr = 1;
  dfs2(1);
  rep (i, 1, N) cout << ANS[i] << " \n"[i == N];
  return 0;
}
