#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 200;

// Matriz de adyacencia
vector<int> g[MAXN];

enum COLORS { NOCOLOR, RED, BLUE };

COLORS d[MAXN];

bool bfs(int s, int n) {
     for (int i = 0; i < n; ++i) d[i] = NOCOLOR;
     queue<int> q;
     q.push(s);
     d[s] = RED;
     while (q.size() > 0) {
           int cur = q.front();
           q.pop();
           for (int i = 0; i < g[cur].size(); ++i) {
               int next = g[cur][i];
               if (d[next] == NOCOLOR) {
                  d[next] = d[cur] == RED ? BLUE : RED;
                  q.push(next);
               }
               else {
                  if (d[next] == d[cur]) 
                      return false;
               }
           }
     }
     return true;
}
   

int
main() {

   int n;
   while (cin >> n) {
         
      if (!n) break;
      
      int l;
      
      for (int i = 0; i < n; i++) g[i].clear();
      
      cin >> l;
      
      for (int j = 0; j < l; j++) {
          
          int from, to;
          cin >> from >> to;
          g[from].push_back(to);
      }
      if (!bfs(0, n)) 
         cout << "NOT BICOLORABLE." << endl;
      else
         cout << "BICOLORABLE." << endl;
   }
}

