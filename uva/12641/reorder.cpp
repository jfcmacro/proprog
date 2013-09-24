#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int
main() {
  int n;
  string number;
  getline(cin, number);
  stringstream snum(number);
  snum >> n;

  map<char, map<char, string> > dict;

  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    stringstream ss(line);

    int nword = 0;
    while (!ss.eof()) {
      string str;
      ss >> str;
      if (str.length() > 2) {
	map<char, string>  m;
	m.insert( pair<char,string>(str[str.length() -1], str) );
	dict.insert (pair<char, map<char, string> >(str[0], m));
	map<char, map<char, string> >::iterator it = dict.begin();
      }
    }

    getline(cin,line);
    stringstream ss2(line);
 
    bool nofirst = true;

    while (!ss2.eof()) {
      string str;
      ss2 >> str;

      if (nofirst) {
    	nofirst = false;
      }
      else {
    	cout << " ";
      }

      if (str.length() > 2) {
	string word = dict[str[0]][str[str.length() -1]];
	
	if ( word.length() == 0) {
	  cout << str;
	}
	else {
	  cout << word;
	}
      }
      else {
	cout << str;
      }
    }

    cout << endl;
    dict.clear();
  }
  return 0;
}
