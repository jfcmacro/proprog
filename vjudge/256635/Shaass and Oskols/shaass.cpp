#include <bits/stdc++.h>

using namespace std;

int wires[101];

int
main() {
  int nw;
  cin >> nw;
  
  for (int i = 1; i <= nw; i++) {
    cin >> wires[i];
  }

  int s;
  cin >> s;

  for (int i = 0; i < s; i++) {
    int sw, sb;
    cin >> sw >> sb;
    wires[sw - 1] += (sb - 1);
    wires[sw + 1] += (wires[sw] > sb ? wires[sw] - sb : 0);
    wires[sw] = 0;
  }

  for (int i = 1; i <= nw; i++) {
    cout << wires[i] << '\n';
  }
}
