#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std;

struct Entry {
  string words;
  int counts;
  vector<int> pages;
  };

int find(string theword, vector<Entry>& list1);
void insert(string theword, int thepage, vector<Entry>& list1);
void printInOrder(ostream& output, vector<Entry>& list1);

