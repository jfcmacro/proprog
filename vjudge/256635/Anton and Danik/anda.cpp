#include <bits/stdc++.h>

using namespace std;

int
main() {
  int n;
  int nA = 0;
  int nD = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'A') nA++;
    else if (c == 'D') nD++;
  }

  if (nA > nD)
    cout << "Anton" << "\n";
  else if (nA < nD)
    cout << "Danik" << "\n";
  else
    cout << "Friendship" << "\n";
}
