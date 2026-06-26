#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a;
  vector<int> wys;
  vector<int> dp(n + 1);

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    wys.push_back(a);
  }
  dp[1] = abs(wys[1] - wys[0]);
  for (int i = 2; i < n; i++) {
    dp[i] = min(dp[i - 1] + abs(wys[i] - wys[i - 1]),
                dp[i - 2] + abs(wys[i] - wys[i - 2]));
  }
  cout << dp[n - 1];
}
