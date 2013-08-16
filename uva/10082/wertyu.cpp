#include <iostream>

using namespace std;

char row[] = "'1234567890-=QWERTYUIOP[]ASDFGHIJKL;'ZXCVBNM,./";

char symbols[256];

int
main() {

  for (int i = 1; row[i]; i++) { 
    symbols[row[i]] = row[i-1];
  }

  string line;
  getline(cin, line);

  while (!cin.eof()) {
    char *out = new char[line.length() + 1];
    const char *in = line.c_str();
    int i = 0;
    for (i = 0; i < line.length(); i++) {
      if (in[i] != ' ') {
	out[i] = symbols[in[i]];
      }
    }

    out[line.length()] = '\0';
    cout << out << endl;
    delete[] out;
    getline(cin, line);
  }

  return 0;
}
