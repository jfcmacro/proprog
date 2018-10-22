#include <bits/stdc++.h>

using namespace std;


int
main() {
  int ns;
  string stones;
  char last;

  cin >> ns;
  
  cin >> stones;

  last = stones[0];
  int nsd = 0;
  
  for (int i = 1; i < ns; ++i) {
    if (last == stones[i]) {
      nsd++;
    }
    else {
      last = stones[i];
    }
  }

  
  cout << nsd << endl;

  return EXIT_SUCCESS;
}
