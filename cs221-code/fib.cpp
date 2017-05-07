//
// Compile with: g++ -Wall fib.cpp -lgmpxx -lgmp -o fib
//
// To see how the difference in performance, try:
// The iterative version (linear time):
// ./fib i 1000000
// The matrix version (logarithmic time):
// ./fib m 1000000
//
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <gmpxx.h> // GNU Multiple Precision Arithmetic Library

using namespace std;

typedef mpz_class bigint; // use the name "bigint" for "mpz_class"

class Matrix
{
  vector<bigint> A;
  unsigned rows, cols;

public:
  Matrix(unsigned _rows, unsigned _cols, bigint x) : rows(_rows), cols(_cols)
  {
    for (unsigned i = 0; i < rows; i++)
    {
      for (unsigned j = 0; j < cols; j++)
      {
        A.push_back(x);
      }
    }
  };

  ~Matrix(){};

  Matrix &operator=(const Matrix &rhs)
  {
    rows = rhs.rows;
    cols = rhs.cols;
    A = rhs.A;
    return *this;
  }

  Matrix operator+(const Matrix &rhs)
  {
    Matrix result(rows, cols, 0);
    for (unsigned i = 0; i < rows; i++)
    {
      for (unsigned j = 0; j < cols; j++)
      {
        result(i, j) = (*this)(i, j) + rhs(i, j);
      }
    }
    return result;
  };

  Matrix operator-(const Matrix &rhs)
  {
    Matrix result(rows, cols, 0);
    for (unsigned i = 0; i < rows; i++)
    {
      for (unsigned j = 0; j < cols; j++)
      {
        result(i, j) = (*this)(i, j) - rhs(i, j);
      }
    }
    return result;
  };

  Matrix operator*(const Matrix &rhs)
  {
    Matrix result(rows, cols, 0);
    for (unsigned i = 0; i < rows; i++)
    {
      for (unsigned j = 0; j < cols; j++)
      {
        for (unsigned k = 0; k < rows; k++)
        {
          result(i, j) += (*this)(i, k) * rhs(k, j);
        }
      }
    }
    return result;
  };

  bigint &operator()(const unsigned row, const unsigned col)
  {
    return this->A[row * cols + col];
  };

  const bigint &operator()(const unsigned row, const unsigned col) const
  {
    return this->A[row * cols + col];
  };

  void print()
  {
    for (unsigned i = 0; i < rows; i++)
    {
      for (unsigned j = 0; j < cols; j++)
      {
        cout << (*this)(i, j) << " ";
      }
      cout << endl;
    }
  };
};

bigint fibMat(unsigned n)
{

  if (n <= 2)
    return 1;

  Matrix F(2, 2, 0);
  F(0, 0) = 1;
  F(0, 1) = 1;
  F(1, 0) = 1;
  F(1, 1) = 0; // F is Fibonacci matrix
  Matrix R(2, 2, 0);
  R(0, 0) = 1;
  R(0, 1) = 0;
  R(1, 0) = 0;
  R(1, 1) = 1; // R is identity matrix

  int x = n - 2;
  // Calculate R = F^x
  // Think of x in binary: x = 1011
  // F^x = F^(1000) * F^(0010) * F^(0001) (where the exponents are in binary)
  //     = F^8      * F^2      * F^1
  // So I need to multiply together all F^(2^k) where the kth bit of
  // x is 1 (counting the bits from rightmost=0 to leftmost).
  while (x > 0)
  {
    if (x % 2 == 1)
    { // if x odd, multiply R by current power of F
      R = R * F;
    }
    F = F * F; // square the matrix: F becomes F^2
    x = x / 2; // shift bits one place to the right: 1011 becomes 101
  }
  return R(0, 0) + R(0, 1);
}

// Iterative fibonacci
bigint fibIter(unsigned n)
{
  if (n <= 2)
    return 1;

  bigint a = 1, b = 1, c = 2;
  for (unsigned i = 3; i < n; i++)
  {
    a = b;
    b = c;
    c = a + b;
  }
  return c;
}

// Recursive fibonacci
bigint fibRec(unsigned n)
{
  if (n <= 2)
    return 1;
  return fibRec(n - 1) + fibRec(n - 2);
}

// Closed-form fibonacci
double fibClosed(unsigned n)
{
  double phi((1 + sqrt(5)) / 2);
  double psi((1 - sqrt(5)) / 2);
  return (pow(phi, n) - pow(psi, n)) / sqrt(5.0);
}

int main(int argc, char *argv[])
{
  unsigned n;

  string t("m");
  if (argc == 1 || argc > 3)
  {
    cerr << "Usage: " << argv[0] << " [{r,i,c,m}] n\n";
    return 1;
  }
  else
  {
    istringstream ss(argv[argc - 1]);
    if (!(ss >> n))
    {
      cerr << "Usage: " << argv[0] << " [{r,i,c,m}] n\n";
      return 1;
    }
    if (argc == 3)
    {
      istringstream ss(argv[1]);
      if (!(ss >> t) || (t != "r" && t != "i" && t != "c" && t != "m"))
      {
        cerr << "Usage: " << argv[0] << " [{r,i,c,m}] n\n";
        return 1;
      }
    }
  }

  if (t == "r")
    cout << fibRec(n) << endl;
  else if (t == "i")
    cout << fibIter(n) << endl;
  else if (t == "c")
    cout << fibClosed(n) << endl;
  else
    cout << fibMat(n) << endl;

  return 0;
}
