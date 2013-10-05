#include <iostream>
#include <iomanip>

using namespace std;

const long TAM_BUSES=10;
const long TAM_MICRO=5;


long
_power(long a, long b) {
  long prd = 1;
  for (long i = 0; i < b; i++) {
    prd *= a;
  }
  return prd;
}

long
compCases(long n, long cm, long cb) {
  long pb = 1;
  long total = 0;
  long roofnm = n / TAM_MICRO;
  long pm = _power(cm, roofnm);

  for (long nb = 0, nm = roofnm; nm >= 0; nb++, nm -= 2) {
    long tmp = pb * pm;
    tmp *= (nb == 0 or nm == 0 ? 1 : nb + nm);
    total += tmp;
    pb *= cb;
    pm /= cm;
    pm /= cm;
  }
  return total % 1000000L;
}

int
main(int argc, char *argv[]) {

  long n, cm, cb;

  while (cin >> n >> cm >> cb) {
    cout << setw(6) << setfill('0') << compCases(n, cm, cb) << endl;
  }
  return 0;
}
