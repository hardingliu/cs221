#include <iostream>
using namespace std;

int main () {
  int x = 5, y = 15;
  int * p1, *p2;
               // value of x y    p1     p2
               //          5 15 uninit uninit
  p1 = &x;     
  cout << x << endl;
  cout << y << endl;
  cout << p1 << endl;
  
  p2 = &y;
  cout << x << endl;
  cout << y << endl;
  cout << p1 << endl;
  cout << p2 << endl;

  *p1 = 6;
  cout << x << endl;
  cout << y << endl;
  cout << p1 << endl;
  cout << p2 << endl;

  *p1 = *p2;
  cout << x << endl;
  cout << y << endl;
  cout << p1 << endl;
  cout << p2 << endl;

  p2 = p1;
  cout << x << endl;
  cout << y << endl;
  cout << p1 << endl;
  cout << p2 << endl;

  *p1 = *p2+10;
  cout << x << endl;
  cout << y << endl;
  cout << p1 << endl;
  cout << p2 << endl;

  return 0;

}
