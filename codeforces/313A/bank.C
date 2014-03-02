#include <iostream>

using namespace std;

int
main() {
  int i;
<<<<<<< HEAD
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
=======
  
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
>>>>>>> 2abd09859eb107ae44fe8790bbad02df2eb1ed40
  return 0;
}
