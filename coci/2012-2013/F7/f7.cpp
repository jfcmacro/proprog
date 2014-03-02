#include <iostream>

using namespace std;

int pos[2300000];

int
main() {
  int n;
  cin >> n;
  int max = 0;

  for (int i = 0; i < n; i++) {
    int curPos;

    cin >> curPos;

    int lim = (curPos + n + 1);

    for (int j = curPos; j < lim; j++) {

      pos[j]++;

      if (pos[j] > max) max = pos[j];
    }

  }

  cout << max << endl;

  return 0;
}
