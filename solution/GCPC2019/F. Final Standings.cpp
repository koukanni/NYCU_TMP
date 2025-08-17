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

const ll MAXN = 1e2 + 5;
const ll MOD = 1000000000 + 7;
const double eps = 1e-9;

ll T, P;
double strength[MAXN];
double difficulty[MAXN];
char state[MAXN][MAXN];

void solve() {
  cin >> T >> P;
  for (ll t = 1; t < T; t++) cin >> strength[t];
  for (ll p = 1; p <= P; p++) cin >> difficulty[p];
  ll count_we_AC = 0;
  for (ll t = 1; t <= T; t++) {
    for (ll p = 1; p <= P; p++) {
      cin >> state[t][p];
    }
  }
  for (ll p = 1; p <= P; p++) {
    if (state[T][p] == 'X') count_we_AC++;
  }
  double ans = 1.0;
  for (ll t = 1; t < T; t++) {
    vector<double> problems;
    ll count_other_AC = 0, count_other_may_AC = 0;
    for (ll p = 1; p <= P; p++) {
      if (state[t][p] == 'X') count_other_AC++;
      else if (state[t][p] == '?') {
        count_other_may_AC++;
        problems.push_back(strength[t] * difficulty[p]);
      }
    }
    if (count_other_AC > count_we_AC) {
      ans = 0.0;
      break;
    }
    if (count_other_AC + count_other_may_AC <= count_we_AC) continue;
    ll at_most_AC = count_we_AC - count_other_AC;
    vector<double> dp(at_most_AC+1, 0.0);
    dp[0] = 1.0;
    for (auto ac_rate : problems) {
      for (ll k = at_most_AC; k >= 1; k--) {
        dp[k] = dp[k-1] * ac_rate + dp[k] * (1.0 - ac_rate);
      }
      dp[0] *= (1.0 - ac_rate);
    }
    double valid_prob = 0.0;
    for (ll k = 0; k <= at_most_AC; k++) valid_prob += dp[k];
    ans *= valid_prob;
  }
  cout << setprecision(10) << ans << "\n";
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