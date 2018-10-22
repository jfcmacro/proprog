#include <bits/stdc++.h>

using namespace std;

int
main() {
  int np;

  cin >> np;

  int ns = 0;
  int a[3];
  for (int i; i < np; i++) {
    cin >> a[0] >> a[1] >> a[2];
    if ((a[0] + a[1] + a[2]) >= 2) {
      ns++;
    }
  }
  cout << ns << endl;
  return EXIT_SUCCESS;
}
