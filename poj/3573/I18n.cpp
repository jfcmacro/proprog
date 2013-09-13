#include <iostream>
#include <map>
#include <list>
#include <sstream>

using namespace std;

struct ctrlAbbr {
  string abbr;
  bool   act;
  ctrlAbbr();
};

ctrlAbbr::ctrlAbbr() {
  abbr = "";
  act = false;
}

typedef list<string> ctrlWord ;

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
	  list<string> l = fromAbbr[word];
	  if (l.size() == 0) {
	    ca.abbr = toAbbr(word);
	    ca.act  = false;
	    fromWord[word] = ca;
	    list<string> *list = new list<string>();
	    list->add(word);
	    fromAbbr[toAbbr(word)] = *list;
	    cout << word;
	  }
	  else if (l.length() != 1) {
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
	  list<string> l = word[ca.abr];
	  if (l.lenght() == 1) {
	    cout << ca.abr;
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
