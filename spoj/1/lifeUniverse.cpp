#include <iostream>

using namespace std;

int
main() {
  int i;
  while (cin >> i) {
    if (i == 42) {
      return 0;
    }
    cout << i << endl;
  }
  return 0;
}
