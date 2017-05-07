#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps;
void swap(int & a, int & b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int randint(int a, int b) {
  return a + (rand() % (b - a + 1));
}

int qc(int n) {
  int result = 0;
  if (n<=1) return result;
  int p = randint(1, n);
  for (int i = 1; i <= n-1; ++i) {
    result++;
  }
  return result + qc(p-1) + qc(n-p);
}

float c(int n) {
  if (n <= 1) return 0;
  float sum = 0.0;
  for (int m=1; m <= n; m++)
    sum += n-1 + c(m-1) + c(n-m);
  return sum / n;
}

void quicksort(int a, int b) {
  if (a >= b) return;
  int p = randint(a,b); // pivot
  swap(x[a], x[p]);
  int m = a;
  int i;
  // in-place partition:
  for (i = a+1; i <= b; i++) {
    ++comps;
    if (x[i] < x[a])
      swap(x[++m], x[i]);
  }
  swap(x[a],x[m]);
  quicksort(a, m-1);
  quicksort(m+1, b);
}


#define NN 10

int main(int argc, char *argv[]) {
  srand((int)time(0));
  comps = 0;
  //change the following code
  for (int i=0; i<100; ++i) {
    x = new int[NN];
    for (int i=0; i<NN; ++i) {
      x[i] = rand() % NN;
    }
    quicksort(0, NN-1);
  }
  int avg = comps / 100;
  std::cout << avg <<  std::endl;
  std::cout << qc(10) << std::endl;
  std::cout << c(10) << std::endl;
  delete[] x;
  return 0;
}




