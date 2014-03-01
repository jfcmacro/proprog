#include <iostream>

using namespace std;

int
main() {
  int i;
  cin >> i;
  if (i >= 0) {
    cout << i << endl;
  }
  else {
    int alt1, alt2;
    i = -i;
    alt1 = i / 100 + i % 10;
    alt2 = i / 10;
    cout << "Resultado: " << alt1 << " " <<  alt2 << endl;
    if (alt1 > alt2) {
      cout << -alt2 << endl;
    }
    else {
      cout << -alt1 << endl;
    }
  }
  return 0;
}
