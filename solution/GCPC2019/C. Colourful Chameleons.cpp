#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <numeric>
#include <unordered_map>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

ll fpow(ll a, ll b, ll m)
{
    if(!b) return 1;
    ll tmp = 1;
    for(ll cur = a; b; b >>= 1, cur = cur * cur % m) if(b & 1) tmp = tmp * cur % m;
    return tmp;
}
ll inv(ll a, ll m) {return fpow(a, m - 2, m);}

#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, n)  for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)

const ll MAXN = 1e5 + 5;
const ll MOD = 1000000000 + 7;
const double eps = 1e-9;

ll N, Y, C, x[MAXN];

void solve() {
  cin >> N >> C >> Y;
  for (ll i = 1; i <= N; i++) cin >> x[i];
  ll mod_value = (x[1] % (Y+1)), max_x = x[1];
  for (ll i = 1; i <= N; i++) {
    if (i == C) continue;
    if ((x[i] % (Y+1)) != mod_value) {
      cout << "impossible\n";
      return;
    }
    max_x = max(max_x, x[i]);
  }
  ll ans = 0;
  for (ll i = 1; i <= N; i++) ans += x[i];
  ans -= ((N-1) - Y) * max_x;
  cout << max_x << " " << ans << "\n";
}

signed main() {
  fastio
  solve();
  return 0;
}

/*
0. WA1 -> multiple input
1. WA7 -> specify mod, and use mod or not
*/