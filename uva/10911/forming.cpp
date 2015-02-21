#include <iostream>
#include <utility>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

unsigned int const MN = 8;

struct Info {
  char name[21];
  struct Pair {
    int x;
    int y;
  } pos;
} dataInfo[8];

double distTbl[8][8];

double dist(int x1, int y1, int x2, int y2) {
  int x = abs(x1 - x2);
  int y = abs(y1 - y2);

  return sqrt((double) (x * x) + (double) (y * y));
}

int
main() {

  int nrCase = 1;

  for (;;) {

    int n;
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < 2*n; i++) {
      cin >> dataInfo[i].name >> dataInfo[i].pos.x >> dataInfo[i].pos.y;
    }

    // compute dist
    for (int i = 0; i < n; i++) {

      for (int j = i+1; j < n; j++) {

	distTbl[i][j] = dist(dataInfo[i].pos.x, dataInfo[j].pos.x,
			     dataInfo[i].pos.y, dataInfo[j].pos.y);
      }
    }
    cout << "Case: " << nrCase++ << endl;
    // Program here
  }
  return 0;
}
