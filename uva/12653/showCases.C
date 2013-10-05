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

  cout << "enter a value of n> " << endl;
  cin >> n;

  for (int i = 5; i <= n; i += 5) {
    f(i,0,0);
    cout << "For current value of n: " << i << endl; 
    for (map<long,long>::iterator it = casos.begin(); 
	 it != casos.end(); it++) {
      cout << "nm: " << it->first << " nb: " << it->second << endl;
    }
    casos.clear();
  }
  return 0;
}
