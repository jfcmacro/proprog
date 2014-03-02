#include <iostream>

using namespace std;


int
main() {
  int *frq;

  string s;
  cin >> s;
  frq = new int[s.length()];
  int nQ;
  cin >> nQ;
  frq[s.length() - 1] = 0;
  for (int j = s.length() - 2; j >= 0; j--) {
    frq[j] = (s[j] == s[j+1]) ? frq[j+1] + 1 : frq[j+1]; 
  }
  // for (int i = 0; i < s.length() - 1; i++) {
  //   cout << "i: " << i << " " << frq[i] << endl;
  // }

  for (int j = 0; j < nQ; j++) {
    int li, ri;
    cin >> li >> ri;
    int nH = 0;
    // for (int i = li-1; i < ri-1; i++) {
    //   if (s[i] == s[i+1]) nH++;
    // }
    cout << frq[li-1] - frq[ri-1] << endl; 
  }
  return 0;
}
