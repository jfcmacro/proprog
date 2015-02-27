#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;

vector <int> g[MAXN];
int color[MAXN];
enum {WHITE, GRAY, BLACK};

void dfs(int u) {
  color[u] = GRAY;

  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (color[v] == WHITE) dfs(v);
  }

  color[u] = BLACK;
}

void call_dfs(int n) {
  for (int u = 0; u < n; ++u) color[u] = WHITE;
  for (int u = 0; u < n; ++u)
    if (color[u] == WHITE) dfs(u);
}

int
main() {
  int caso;
  cin >> caso;
  for (int i = 0; i < caso; i++) {
    int nodes;
    cin >> nodes;
    for (int j = 0; j < nodes; j++) {
      g[j].clear();
      for (int k = 0; k < nodes; k++) {
        int value;
        cin >> value;
        if (value) { 
          g[j].push_back(k);
        }
      }
    }
  }
  return 0;
}
