#include <bits/stdc++.h>

using namespace std;

int
main() {
  int n, h;

  cin >> n >> h;

  int w = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    w += a <= h ? 1 : 2;
  }

  cout << w << "\n";
}
