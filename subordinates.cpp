#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tab;
vector<int> visited;
vector<int> friendly_spiderman;
int dfs(int node) {

  int friends = 0;
  friends++;
  for (int i : tab[node]) {
    if (!visited[i]) {
      visited[i] = true;
      friends += dfs(i);
      // cout << "node: " << i << endl;
      // cout << "friends " << friends << endl;
    }
  }
  friendly_spiderman[node] = friends - 1;
  return friends;
}

int main() {
  int n;
  cin >> n;
  int a;
  tab.resize(n + 2);
  visited.resize(n + 2);
  friendly_spiderman.resize(n + 2);
  for (int i = 2; i <= n; i++) {
    cin >> a;
    tab[a].push_back(i);
  }
  visited[1] = true;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << friendly_spiderman[i] << " ";
  }
}
