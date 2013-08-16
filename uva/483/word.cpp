#include <iostream>

using namespace std;

int
main() {
  string line;
  getline(cin, line);
  while (!cin.eof()) {

    const char *linep = line.c_str();
    char *realout = new char[line.length() + 1];
    char *out;
    out = realout;

    while (*linep) {

      if (*linep == ' ') {
	*out++ = *linep++;
      }
      else {

	const char *end,*start;
	end = linep;
	start = linep;
	while (*end && *end != ' ') {
	  end++;
	}
	linep = end;
	end--;
	while (end >= start) {
	  *out++ = *end--;
	}
	*out='\0';
      }
    }
    cout << realout << endl;
    getline(cin, line);
  }
  return 0;
}
