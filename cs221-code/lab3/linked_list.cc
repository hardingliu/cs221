// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    cout << curr->key;
    if (curr->next != NULL) cout << ", ";
  }
  cout << "]" << endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
vector<int> to_vector(Node* head) {
  vector<int> result;
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    result.push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){
  // ******** WRITE YOUR CODE HERE ********
  Node* curr = head;
  if (head == NULL){
    return;
  }

  else if (head->next == NULL){
    head = NULL;
    return;
  }
  else {
    Node* prev = head;
    while (curr->next != NULL){
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    
  }
  
  return;
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */ 
void remove(Node*& head, int oldKey) {
  // ******** WRITE YOUR CODE HERE ********
  Node* prev = head;
  
  if (! head){
    return;
  }

  else if (head->key == oldKey) { 
    head = head->next;
    return;
  }

  else {
    for (Node* curr = head->next; curr != NULL; curr = curr->next) {
      if (curr->key == oldKey) {
        prev->next = curr->next;
        return;
      }
    
      else {
        prev = prev->next;
      }
    }
  }

  return;
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){
  // ******** WRITE YOUR CODE HERE ********
  for (Node* curr = head; curr != NULL; curr = curr->next) {
    if (curr->key == oldKey) {
      Node* insertNode = new Node;
      insertNode->key = newKey;
      insertNode->next = curr->next;
      curr->next = insertNode;
      return; 
    }
  }
  
  return;
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  // ******** WRITE YOUR CODE HERE ********
    Node* result = NULL;
    Node* curr = result;
    
    while((list1 != NULL) && (list2 != NULL)){
      Node* temp1 = new Node;
      Node* temp2 = new Node;
      
      temp1->key = list1->key;
      temp1->next = temp2;
       
      temp2->key = list2->key;
      temp2->next = NULL;

      if (result == NULL){
        result = temp1; 
      }
      else{
        curr->next = temp1;
      }
      
      curr = temp2;
      
      list1 = list1->next;
      list2 = list2->next;
    
    }
    
    while (list2 != NULL){
      Node* temp2 = new Node;
      temp2->key = list2->key;
      temp2->next = NULL;
      if(! result) {
        result = temp2;
        curr = result; 
      }
      else {
        curr->next = temp2;
        curr = curr->next;
      }
      list2 = list2->next;
    }

    while (list1 != NULL){
      Node* temp1 = new Node;
      temp1->key = list1->key;
      temp1->next = NULL;
      if(! result) {
        result = temp1;
        curr = result;
      }
      else{
        curr->next = temp1;
        curr = curr->next;
      }
      list1 = list1->next;
    }

    return result;
}

Node* interleave1(Node* list1, Node* list2) {
  while((list1 != NULL) && (list2 != NULL)) {
    
  }
  
  
  return NULL;
}
