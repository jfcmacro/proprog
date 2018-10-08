#include <bits/stdc++.h>

using namespace std;

int tracklen[20];

bool alreadyFound = false;
int altsum = 0;
vector<int> other;
vector<int> subset;

void search(int,int,int);

int
main(void) {
  int tapelen;
  int ntrack;

  while (cin >> tapelen) {
    cin >> ntrack;
    for (int i = 0; i < ntrack; i++) {
      cin >> tracklen[i];
    }
    alreadyFound = false;
    altsum = 0;
    search(0,ntrack,tapelen);
    if (!alreadyFound) {
      int s = 0;
      for (int v : other) {
	cout << tracklen[v] << " ";
	s += tracklen[v];
      }
      cout << "sum:" << s << endl;
    }
  }
}

void search(int k,int n,int exp) {
  if (k == n) {
    int suma = 0;
    for (int v : subset) {
      suma += tracklen[v];
    }
    if (suma == exp) {
      if (!alreadyFound) {
	for (int v : subset) {
	  cout << tracklen[v] << " ";
	}
	cout << "sum:" << suma << endl;
      }
      alreadyFound = true;
    }
    else {
      if (suma < exp) {
	if (suma > altsum) {
	  other = subset;
	  altsum = suma;
	}
      }
    }
  }
  else {
    subset.push_back(k);
    search(k + 1,n,exp);
    subset.pop_back();
    search(k + 1,n,exp);
  }
}
