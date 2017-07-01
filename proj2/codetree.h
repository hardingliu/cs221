#include <assert.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// The struct of TreeNode in the priority queue and codetree, which
// has two pointers to TreeNode, left and right; as well as two ints, 
// the frequency of that char, represented by freq and ch.
struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int freq;
  int ch;
};
void printChar( int ch );
void printTreeHelper(TreeNode* r, std::string pre);
void printCodeHelper(TreeNode* r, string pre);

// The struct of CodeTree, which has a pointer to a TreeNode, which
// is the root.
struct CodeTree {
  TreeNode* root;
  
  void printTree() {
    printTreeHelper(root, "");
  }
  
  void printCode() {
    printCodeHelper(root, "");
  }
};
CodeTree CodeTree(int freq[]);
void destory(vector<TreeNode *> &heap);
void swapDown (vector<TreeNode *> &heap, int i);
void swapUp(vector<TreeNode *> &heap, int i);
void heapify(vector<TreeNode *> &heap);
vector<TreeNode *> pqueue(int freq[]);
TreeNode* deleteMin(vector<TreeNode *> &heap);
void insert(vector<TreeNode *> &heap, TreeNode* x);
