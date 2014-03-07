#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;

int
main() {

    int n;
    cin >> n;
    int max = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end(), greater<int>());

    for (vector<int>::iterator it = p.begin(); it != p.end(); it++)
        cout << *it << endl;
    // int lim = (curPos + n + 1);

    /* for (int j = curPos; j < lim; j++) {

      pos[j]++;

      if (pos[j] > max) max = pos[j];
    } */
    cout << max << endl;
    return 0;
}
