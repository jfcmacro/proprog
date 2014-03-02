#include <iostream>

using namespace std;

int
main() {
  int vNSC;
  int wNSC;
  float priceNSC;
  int n;
  int vO;
  int wO;
  float priceO;
  cin >> vNSC >> wNSC;
  priceNSC = (float) vNSC / (float) wNSC * 1000.0f;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> vO >> wO;
    priceO = (float) vO / (float) wO * 1000.0f;
    if (priceNSC > priceO) priceNSC = priceO;
  }
  cout.setf(ios_base::fixed);
  cout.precision(2);
  cout << priceNSC << endl;
  return 0;
}
