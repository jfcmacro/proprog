#include <bits/stdc++.h>

using namespace std;

int
main() {

  int t = 0;
  int n;

  cin >> n;

  string in;
  char prev;
  for (int i = 0; i < n; i++) {
    cin >> in;
    if (i == 0) {
      prev = in[1];
      t++;
    }
    else {
      if (prev == in[0]) {
	t++;
      }
      prev = in[1];
    }
  }

  cout << t << endl;
}
