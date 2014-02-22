#include <iostream>

using namespace std;

int
main() {
  int i;
  
  cin >> i;
  if (i >= 0) {
    cout << i;
  }
  else {
    int val = -i;
    int alt1 = val / 10;
    int alt2 = (val / 100) * 10 + (val % 10);
    if (alt1 < alt2) cout << -alt1; else cout << -alt2;
  }
  cout << endl;
  return 0;
}
