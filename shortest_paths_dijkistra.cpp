#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a, b, c;
  vector<long long> dist(n + 1, LONG_MAX);
  vector<vector<pair<long long, long long>>> tab(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    tab[a].push_back({c, b});
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
  for (int i = 1; i < n + 1; i++) {
    cout << dist[i] << " ";
  }
}
