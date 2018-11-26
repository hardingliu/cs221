#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  Hashtable H(10000);

  for (int i = 0; i < 5000; i++) {
    H.linsert(rand() + 1);
  }
  cout << "Linear with 5000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 5000; i++) {
    H.qinsert(rand() + 1);
  }
  cout << "Quadartic with 5000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 5000; i++) {
    H.dinsert(rand() + 1);
  }
  cout << "Double with 5000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 6000; i++) {
    H.linsert(rand() + 1);
  }
  cout << "Linear with 6000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 6000; i++) {
    H.qinsert(rand() + 1);
  }
  cout << "Quadartic with 6000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 6000; i++) {
    H.dinsert(rand() + 1);
  }
  cout << "Double with 6000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 7000; i++) {
    H.linsert(rand() + 1);
  }
  cout << "Linear with 7000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 7000; i++) {
    H.qinsert(rand() + 1);
  }
  cout << "Quadartic with 7000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 7000; i++) {
    H.dinsert(rand() + 1);
  }
  cout << "Double with 7000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 8000; i++) {
    H.linsert(rand() + 1);
  }
  cout << "Linear with 8000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 8000; i++) {
    H.qinsert(rand() + 1);
  }
  cout << "Quadartic with 8000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 8000; i++) {
    H.dinsert(rand() + 1);
  }
  cout << "Double with 8000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 9000; i++) {
    H.linsert(rand() + 1);
  }
  cout << "Linear with 9000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 9000; i++) {
    H.qinsert(rand() + 1);
  }
  cout << "Quadartic with 9000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 9000; i++) {
    H.dinsert(rand() + 1);
  }
  cout << "Double with 9000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 10000; i++) {
    H.linsert(rand() + 1);
  }
  cout << "Linear with 10000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 10000; i++) {
    H.qinsert(rand() + 1);
  }
  cout << "Quadartic with 10000 keys and size 10000: ";
  H.printStats();

  H.clear();
  for (int i = 0; i < 10000; i++) {
    H.dinsert(rand() + 1);
  }
  cout << "Double with 10000 keys and size 10000: ";
  H.printStats();
}
