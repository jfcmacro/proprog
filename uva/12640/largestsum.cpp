#include <iostream>
#include <sstream>

using namespace std;

const int MAX = 100000000 + 1;
const int MAXNUM = 100000;

int sum[MAX];
int num[MAXNUM];
int
main() {

  sum[0] = 0;
  int i = 1;
  while (!cin.eof()) {
    string line;
    getline(cin,line);
    stringstream ss(line);
    while (!ss.eof()) {
      int x;
      ss >> x;
    }
  }
  return 0;
}
