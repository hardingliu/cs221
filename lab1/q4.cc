#include <cstdlib> // for atoi
#include <iostream>
using namespace std;
// prototype
void moveDisks(int n, const char *FROM, const char *VIA, const char *TO);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " number_of_disks" << endl;
    return -1;
  }
  moveDisks(atoi(argv[1]), "peg A", "peg B", "peg C");
  return 0;
}
// put your moveDisks() function here

void moveDisks(int n, const char *FROM, const char *VIA, const char *TO)
{
  if (n == 0)
    return;
  else
  {
    moveDisks(n - 1, FROM, TO, VIA);
    cout << "Move disk from " << FROM << " to " << TO << endl;
    moveDisks(n - 1, VIA, FROM, TO);
  }
}
