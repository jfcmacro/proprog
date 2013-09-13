#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct ctrlAbbr {
  ctrlAbbr(); //: abbr(""), act(false) { } 
  ctrlAbbr(string& abbr, bool& act) : abbr(abbr), act(act) { } 
  string abbr;
  bool   act;
};

ctrlAbbr::ctrlAbbr() : abbr(""), act(false) { }


// ctrlAbbr::ctrlAbbr() {
//   abbr = "";
//   act = false;
// }

typedef vector<string> ctrlWord ;

map<string, ctrlAbbr> fromWord;
map<string, ctrlWord> fromAbbr;
string special = "-,.\"():;!? ";

bool foundSpecial(char& c) {
  int i;
  for (i = 0; i < special.length(); i++) {
    if (c == special[i]) 
      break;
  }
  if (i < special.length()) 
    return true;
  return false;
}

string& toAbbr(string& word) {
  string* abbr = new string();
  abbr->append(word.substr(0,1));
  stringstream strstrm; 
  strstrm << word.length() - 2;
  abbr->append(strstrm.str());
  abbr->append(word.substr(word.length()-1, 1));
  return *abbr;
}

int
main(int argc, char *argv[]) {
  string line;

  do  {
    getline(cin,line); 
    int pos = 0;
    while (pos < line.length()) {
 
      if (foundSpecial(line[pos])) { // Special char
	cout << line[pos];
	pos++;
      }
      else {
	int final = pos + 1;
	while (final < line.length() && !foundSpecial(line[final])) {
	  final++;
	}
	
	string word = line.substr(pos,final-pos);
	pos = final;
	
	ctrlAbbr& ca = fromWord[word];
	if (ca.abbr == "") { // first Time or is an abbr
	  vector<string> l = fromAbbr[word];
	  if (l.size() == 0) {
	    ca.abbr = toAbbr(word);
	    ca.act  = false;
	    fromWord[word] = ca;
	    vector<string> *lst = new vector<string>();
	    lst->push_back(word);
	    fromAbbr[toAbbr(word)] = *lst;
	    cout << word;
	  }
	  else if (l.size() != 1) {
	    cout << l[0];
	  }
	  else {
	    cout << word;
	  }
	}
	else if (!ca.act) {
	  ca.act = true;
	  cout << word;
	}
	else {
	  vector<string> lst = word[ca.abbr];
	  if (lst.lenght() == 1) {
	    cout << ca.abbr;
	  }
	  else {
	    cout << word;
	  }
	}
      }
    }
    cout << endl;
  } while (!cin.eof());
}
