#include <bits/stdc++.h>

using namespace std;

vector<int> subset;
vector<int> elements;
int n;

void search(int k);

int
main() {
  int ne;
  
  while (true) {
    cin >> ne;

    if (ne == 0) break;
  
    cout << endl;
    
    subset.clear();
    elements.clear();
    for (int i = 0; i < ne; i++) {
      int v;
      cin >> v;
      elements.push_back(v);
    }

    n = ne - 1;
    search(0);
  }
}

void search(int k) {
  if (k == (n + 1)) {
    if (subset.size() == 6) {
      for (const int e : subset) {
	cout << elements[e] << " ";
      }
      cout << '\n';
    }
  }
  else {
    subset.push_back(k);
    search(k+1);
    subset.pop_back();
    search(k+1);
  }
}
