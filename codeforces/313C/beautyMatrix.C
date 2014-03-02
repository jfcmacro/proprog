#include <iostream>

using namespace std;

int
main() {
  int fourN;
  cin >> fourN;
  fourN >>= 2;
  if (fourN == 0) {
    int m;
    cin >> m;
    cout << m << endl;
  }
  else {
    int *nxtStage = new int[fourN];
    for (int i = 0; i < fourN; i++) {
      int m1, m2, m3, m4;
      cin >> m1 >> m2 >> m3 >> m4;
      int mm1 = m1 > m2 ? m1 : m2;
      int mm2 = m3 > m4 ? m3 : m4;
      nxtStage[i] = mm1 > mm2 ? mm1 : mm2;
    }
    int* cntStage = nxtStage;
    fourN >>= 2;

    while (fourN) {
      nxtStage = new int[fourN];
      for (int i = 0, j = 0; i < fourN; i+=4, j++) {
	int mm1 = cntStage[i+0] > cntStage[i+1] ? cntStage[i+0] 
	  : cntStage[i+1];
	int mm2 = cntStage[i+2] > cntStage[i+3] ? cntStage[i+2]
	  : cntStage[i+3];
	nxtStage[j] = mm1 > mm2 ? mm1 : mm2;
      }
      free(cntStage);
      cntStage = nxtStage;
      fourN >>= 2;
    }
    cout << cntStage[0] << endl;
    free(cntStage);
  }
  return 0;
}
