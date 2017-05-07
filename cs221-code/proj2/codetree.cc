#include "codetree.h"
// Given function, to print a single char.
void printChar( int ch ) {
  if( ch < 16 ) {
    std::cout << "x0" << std::hex << ch;
  } else if( ch < 32 || ch > 126 ) {
    std::cout << "x" << std::hex << ch;
  } else {
    std::cout << "\"" << (char)ch << "\"";
  }
}
// Given function, to print the codetree.
void printTreeHelper(TreeNode* r, std::string pre) {
  if( r == NULL ) return;
  if( r->right == NULL ) { // implies r->left == NULL
    printChar(r->ch);
    std::cout << std::endl;
  } else {
    std::cout << "." << std::endl;
    std::cout << pre << "|`1-";
    printTreeHelper(r->right, pre + "|   ");
    std::cout << pre + "|   " << std::endl;
    std::cout << pre << "`-0-";
    printTreeHelper(r->left, pre + "    ");
  }
}

// To print the code.
void printCodeHelper(TreeNode* r, string pre) {
  if (r == NULL) return;
  if (r->left == NULL) { // implies r->right == NULL
    printChar(r->ch);
    cout << ":" << pre << endl;
    cout << endl;
  } else {
    printCodeHelper(r->left, pre +"0");
    printCodeHelper(r->right, pre + "1");
  }
}

// To destory the heap, which is implemented by a vector of pointers to TreeNode.
void destory(vector<TreeNode *> &heap) {
  for (int i=0; i < (int) heap.size(); i++) {
    delete heap[i];
  }
  heap.clear();
}

// To swapDown a Node at i of a heap, to keep the heap a min-heap.
void swapDown (vector<TreeNode *> &heap, int i) {
  int left = i*2 + 1;
  int right = i*2 + 2;
  int min = i;
  if (left < (int) heap.size() && heap[left]->freq < heap[min]->freq) {
    min = left;
  }
  if (right < (int) heap.size() && heap[right]->freq < heap[min]->freq) {
    min = right;
  }
  if (min != i) {
    swap(heap[i], heap[min]);
    swapDown(heap, min);
  }
}

// To swapUp a Node at i of a heap, to keep the heap a min-heap.
void swapUp(vector<TreeNode *> &heap, int i) {
  if (i == 0) return;
  int p = (i - 1)/2;
  if (heap[i]->freq < heap[p]->freq) {
    TreeNode* temp = heap[i];
    heap[i] = heap[p];
    heap[p] = temp;
    swapUp(heap, p);
  }
}

// To heapify a vecotr of pointers to TreeNode.
void heapify(vector<TreeNode *> &heap) {
  for (int i = (int) (heap.size() - 2) / 2 ; i >=0; i--)
    swapDown(heap, i);
}

// Implementation of the priority queue, by passing an array of 256 integers. The
// resulted priority queue should be a vector of pointers to TreeNode, in non-decreasing 
// order, regarding their frequencies.
vector<TreeNode *> pqueue(int freq[]) {
  vector<TreeNode *> heap;
  for (int i=0; i< 256; i++) {
    if (freq[i] != 0) {
      TreeNode* node = new TreeNode;
      node->left = NULL;
      node->right = NULL;
      node->freq = freq[i];
      node->ch = i;
      heap.push_back(node);
      node = NULL;
      delete node;
    }
  }
  heapify(heap);
  return heap;
}

// To delete the min. element of a priority queue, returning a pointer to a TreeNode.
TreeNode* deleteMin(vector<TreeNode *> &heap) {
  assert(!heap.empty());
  TreeNode* node = heap[0];
  heap[0] = heap[heap.size()-1];
  heap.resize(heap.size()-1);
  swapDown(heap, 0);
  return node;
}

// To insert a pointer to a TreeNode x, into a heap.
void insert(vector<TreeNode *> &heap, TreeNode* x) {
  heap.push_back(x);
  swapUp(heap, (int) heap.size() - 1);
}

// To construct a codetree by passing an array of 256 integers.
struct CodeTree CodeTree(int freq[]) {
  vector<TreeNode *> heap = pqueue(freq);
  while (heap.size() > 1) {
    TreeNode* pnode = new TreeNode;
    TreeNode* node0 = new TreeNode;
    TreeNode* node1 = new TreeNode;
    node0 = deleteMin(heap);
    node1 = deleteMin(heap);
    pnode->left = node0;
    pnode->right = node1;
    pnode->freq = node0->freq + node1->freq;
    pnode->ch = 0;
    insert(heap, pnode);
    pnode = NULL;
    node0 = NULL;
    node1 = NULL;
    delete pnode;
    delete node0;
    delete node1;
  }
  struct CodeTree ct;
  ct.root =  heap[0];
  return ct;
}
