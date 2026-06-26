#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  long long a, b, c;
  cin >> n >> m;
  // weight, node
  vector<vector<pair<long long, long long>>> tab(n + 1);
  vector<long long> dist(n + 1, LONG_MAX);
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    tab[a].push_back({c, b});
    tab[b].push_back({c, a});
  }
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  pq.push({0, 1});
  dist[1] = 0;
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
  if (dist[n] == LONG_MAX) {
    cout << -1;
  } else {
    cout << dist[n];
  }
}
