#include <iostream>
#include <cstdlib> // for atoi
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Wrong number of arguments!" << endl;
    return 1;
  }
  int n = atoi(argv[1]);
  int a;
  srand (time(NULL)); 
  for (int i=1; i<=n; i++) {
    a = rand() % n;
    cout << "I " << a << endl;
  }
  return 0;
}
