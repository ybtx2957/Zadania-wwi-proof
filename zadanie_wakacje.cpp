#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b, c;
  int na, nb, nc;
  int a1 = 0, b1 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;

    na = max(b1, c1) + a;
    nb = max(a1, c1) + b;
    nc = max(a1, b1) + c;
    a1 = na;
    b1 = nb;
    c1 = nc;
  }
  cout << max(max(a1, b1), c1);
}
