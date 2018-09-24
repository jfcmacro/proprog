#include <bits/stdc++.h>

using namespace std;

// int valores[100];

int comp(const void* a, const void* b);

int
main() {
  int nc = 0;
  cin >> nc;
  int valores[nc];
  for (int i = 0;i < nc; ++i) {
    cin >> valores[i];
  }
  qsort(valores, nc, sizeof(int),comp);
  for (int i = 0; i < nc; ++i) {
    cout << valores[i] << " ";
  }
  cout << "\n";
}

int
comp(const void *x, const void *y) {
  int *a = (int*)(x);
  int *b = (int*)(y);
  if (*a == *b) return 0;
  if (*a < *b) return -1;
  return 1;
}
