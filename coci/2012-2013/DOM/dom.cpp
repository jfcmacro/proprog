#include <iostream>

using namespace std;

int
main() {
  string refWord("CAMBRIDGE");
  string output;
  string input;

  cin >> input;
  int j = 0;
  for (int i = 0; i < input.length(); i++) {
      bool encontrado = false;

      for (int k = 0;
	   k < refWord.length() and not encontrado;
	   k++) {
	if (input[i] == refWord[k])
	  encontrado = true;
      }

      if (not encontrado) {
	output.append(input,i, 1);
      }
  }

  cout << output << endl;
  return 0;
}
