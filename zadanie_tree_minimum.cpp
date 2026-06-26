#include <bits/stdc++.h>
using namespace std;
#define int long long
int base = 2 << 20;
vector<int> tab(2 * base, LONG_MAX);

int query(int l, int r) {
  int res = LONG_MAX;
  l += base;
  r += base;
  while (l < r) {
    if (l % 2 == 1) {
      res = min(res, tab[l]);
      l++;
    }
    if (r % 2 == 1) {
      r--;
      res = min(res, tab[r]);
    }
    l /= 2;
    r /= 2;
  }
  return res;
}
void update(int pos, int val) {
  pos += base;
  tab[pos] = val;

  while (pos > 1) {
    pos /= 2;
    tab[pos] = min(tab[2 * pos], tab[2 * pos + 1]);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int q;
  cin >> q;
  for (int i = 1; i < n + 1; i++) {
    cin >> tab[base + i];
  }
  for (int i = base - 1; i > 0; i--) {
    tab[i] = min(tab[2 * i], tab[2 * i + 1]);
  }
  int a, b, c;

  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      update(b, c);
    } else {
      cout << query(b, c + 1) << endl;
    }
  }
  return 0;
}
