#include <iostream>

using namespace std;

int
main() 
{
       int *curr = new int[4];
       int *help = new int[4];
       int result[4];
       
       cin >> curr[0] >> curr[1];
       cin >> curr[2] >> curr[3];

       int posMax = 0;
       
       result[0] = result[1] = result[2] = result[3] = 0;
       
       for (int i = 0; i < 4; i++) {
             result[i] =  (curr[0] * curr[3] + curr[1] * curr[2]) / (curr[2] * curr[3]);
             if (result[i] >= result[posMax]) {
                 posMax = i;   
             }
             help[0] = curr[2];
             help[1] = curr[0];
             help[2] = curr[3];
             help[3] = curr[1];
             int *tmp = help;
             help = curr;
             curr = tmp;
       }
       cout << posMax << endl;
       return 0;
}
