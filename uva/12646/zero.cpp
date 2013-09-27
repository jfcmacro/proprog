#include <iostream>

using namespace std;

int
main() {
  short a, b, c;

  while (cin >> a >> b >> c) {

    if ((a == b) and (b == c)) {
      cout << "*" << endl;
    }
    else if ((a == b) and (b != c)) {
      cout << "C" << endl;
    } 
    else if ((a == c) and (a != b)) {
      cout << "B" << endl;
    }
    else if ((b == c) and (a != b)) {
      cout << "A" << endl;
    }
  }
  return 0;
}
