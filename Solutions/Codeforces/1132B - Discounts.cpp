#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define null nullptr
#define st first
#define nd second
#define mod 1000000007
#define maxn 300003

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

int a[maxn];

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + 1 + n, greater<int>());
  int m;
  cin >> m;
  while (m--) {
    int q;
    cin >> q;
    cout << sum - a[q] << '\n';
  }

  return 0;
}
