#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 1000010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef pair<ii, ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

bool used[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int n, k;
  cin >> n >> k;
  k = min(k, n - k);

  bool flag = 0;
  ll ans = 1, d = 1;
  for (int x = 1, nxt; nxt = x + k - n * (x + k > n), !used[x]; x = nxt) {
    used[x] = 1;
    if (flag) {
      ++d;
      flag = 0;
    }
    if (nxt < x && nxt > 1) {
      ++d;
      flag = 1;
    }
    ans += d;
    db(x, nxt, d, ans);
    cout << ans << ' ';
  }
  cout << endl;

  return 0;
}
