#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Robot {
  int posX, posY;
  int incrX, incrY;
  Robot(int x, int y, char to) : posX(x), posY(y) {
    switch (to) {
    case 'N': incrX = 0; incrY = -1; break;
    case 'S': incrX = 0; incrY = 1; break;
    case 'L': incrX = 1; incrY = 0; break;
    case 'O': incrX = -1; incrY = 0; break;
    }
  }

  int walk(vector<string>& robotland, string& movements);

private:
  void turnRight();
  void turnLeft();
};

void Robot::turnRight() {

  if (incrX == 0 && incrY == -1) {
    incrY = 0;
    incrX = 1;
  }
  else if (incrX == 0 && incrY == 1) {
    incrY = 0;
    incrX = -1;
  }
  else if (incrX == 1 && incrY == 0) {
    incrX = 0;
    incrY = 1;
  }
  else if (incrX == -1 && incrY == 0) {
    incrX = 0;
    incrY = -1;
  }
}

void Robot::turnLeft() {
  if (incrX == 0 && incrY == -1) {
    incrY = 0;
    incrX = -1;
  }
  else if (incrX == 0 && incrY == 1) {
    incrY = 0;
    incrX = 1;
  }
  else if (incrX == 1 && incrY == 0) {
    incrX = 0;
    incrY = -1;
  }
  else if (incrX == -1 && incrY == 0) {
    incrX = 0;
    incrY = 1;
  }
}

int Robot::walk(vector<string>& robotland, string& movements) {
  int stickets = 0;
  bool still = false;
  int nxtX = 0;
  int nxtY = 0;

  cout << "Show robotland" << endl;

  for (int i = 0; i < robotland.size(); i++) {
    cout << robotland[i] << endl;
  }

  for (int i = 0; i < movements.length() && !still; i++) {

    switch (movements[i]) {
    case 'D':
      turnRight();
      break;
    case 'E':
      turnLeft();
      break;
    case 'F':
      posX += incrX;
      posY += incrY;
      if (posX < 0 || posY < 0 || posY >= robotland.size() || posX >= robotland[i].length()) {
	still = true;
      }
      else {

	switch(robotland[posX][posY])
	case '*':
	  stickets++;
	robotland[posX][posY] = '.';
	break;

      case '#':
	still = true;
	break;

      case '.':
	break;
      }
      break;
    }
  }

  cout << "Show robotland end" << endl;

  for (int i = 0; i < robotland.size(); i++) {
    cout << robotland[i] << endl;
  }

  return stickets;
}

int
main() {
  vector<string> robotland;
  int n, m, s;
  int actuaX, actualY;
  Robot* robot;
  string movements;
  while (cin >> n >> m >> s) {
    if (n == 0 && m == 0 && s == 0)
      break;

    if (robotland.size() > 0) {

      robotland.erase(robotland.begin(), robotland.end());
    }

    for (int i = 0; i < n; i++) {
      string *actual;
      actual = new string();
      cin >> *actual;
      robotland.push_back(*actual);
      for (int j = 0; j < actual->length(); j++) {
	switch ((*actual)[j]) {
	case 'N':
	case 'S':
	case 'L':
	case '0':
	  if (robot) robot = new Robot(i,j,(*actual)[j]);
	  break;
	}
      }
    }
    cin >> movements;
    cout << robot->walk(robotland, movements) << endl;
    delete robot;
  }
  return 0;
}
