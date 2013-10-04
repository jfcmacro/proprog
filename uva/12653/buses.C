#include <iostream>
#include <map>

using namespace std;

const long TAM_BUSES=10;
const long TAM_MICRO=5;

map< long, long> casos;

void
f(long n, long tm, long tb) {

  if ((n - TAM_MICRO) >= 0) {
    f(n - TAM_MICRO, tm + 1, tb); 
  }

  if ((n - TAM_BUSES) >= 0) {
    f(n - TAM_BUSES, tm, tb + 1);
  }
  if (n == 0) {
    casos.insert(pair<long,long>(tm,tb));
  }
  //  cout << "n: " << n <<  " tb: " << tb << " tm: " << tm << endl;
}

long
_power(long a, long b) {
  long prd = 1;
  for (long i = 0; i < b; i++) {
    prd *= a;
  }
  return prd;
}

int
main(int argc, char *argv[]) {

  long n;
  long cb;
  long cm;
  
  while (cin >> n >> cm >> cb) {
    f(n,0,0);
    // cout << n << endl;
    long total = 0;

    for (map<long,long>::iterator it = casos.begin(); 
	 it != casos.end(); it++) {
      // cout << "nb: " << it->first << " nm: " << it->second << endl;
      long tmp = 0;
      tmp = (_power(cm,it->first) * _power(cb,it->second));
      tmp *= (it->first == 0 || it->second == 0 ? 1 : (it->first + it->second));
      total += tmp;
    }
    cout << total << endl;
    casos.clear();
  }
  return 0;
}
