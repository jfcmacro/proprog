#include <bits/stdc++.h>

using namespace std;

bool check(string& s);
void process(string& s, int (*f)(int));

int
main() {
  string s;

  cin >> s;

  if (check(s)) {
    process(s,toupper);
  }
  else {
    process(s,tolower);
  }

  cout << s << endl;
  
  return EXIT_SUCCESS;
}

bool
check(string& s) {
  int lower = 0;
  
  for (char c : s) {
    lower += islower(c) ? 1 : 0;
  }
  
  int upper = s.size() - lower;
  
  return upper > lower;
}

void
process(string& s, int (*f)(int)) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = f(s[i]);
  }
}
