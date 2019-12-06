#include <iostream>
#include <cstdlib>

using namespace std;

int
main(void) {

  const int MULTIPLES[] = { 3, 5 };

  int sum = 0;
  int min;
  int max;

  cin >> min >> max;

  for (int i = min; i < max; i++)
    for (int j = 0; j < sizeof(MULTIPLES)/sizeof(int); j++)
      if ((i % MULTIPLES[j]) == 0) { sum += i; break; }

  cout << sum << endl;

  return EXIT_SUCCESS;
}
