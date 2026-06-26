#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  long long a, b, c;
  cin >> n >> m;

  vector<vector<pair<long long, long long>>> tab(2 * (n + 1));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    tab[a].push_back({c, b});
    tab[a].push_back({c / 2, b + n}); // connections to higher dimension
    tab[a + n].push_back({c, b + n}); // higher dimension do siebie
  }
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  vector<long long> dist(n * 2 + 1, LONG_MAX);
  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [weight, node] = pq.top();
    pq.pop();
    if (weight > dist[node])
      continue;
    for (auto [w, v] : tab[node]) {
      if (dist[node] + w < dist[v]) {
        dist[v] = dist[node] + w;
        pq.push({dist[v], v});
      }
    }
  }

  cout << min(dist[n], dist[2 * n]);
}
