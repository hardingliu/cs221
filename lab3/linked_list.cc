// linked_list.cc -- functions for linked_list lab (cs221)

#include "linked_list.h"
#include <assert.h>

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */
void insert(Node *&head, int newKey)
{
	Node *curr = new Node(newKey, head);
	//curr->key = newKey;
	//curr->next = head;

	head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */
void print(Node *head)
{
	std::cout << "[";
	for (Node *curr = head; curr != NULL; curr = curr->next)
	{
		std::cout << curr->key;
		if (curr->next != NULL)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */
int size(Node *head)
{
	if (!head)
		return 0;
	return 1 + size(head->next);
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */
std::vector<int> to_vector(Node *head)
{
	std::vector<int> result;
	for (Node *curr = head; curr != NULL; curr = curr->next)
	{
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
void delete_last_element(Node *&head)
{
	// ******** WRITE YOUR CODE HERE ********
	if (head) {
		Node *temp = head;
		if (!head->next) {
			delete temp;
			head = NULL;
		} else {
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
	}
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
void remove(Node *&head, int oldKey)
{
	// ******** WRITE YOUR CODE HERE ********
	if (head) {
		Node *temp = head;
		if (head->key == oldKey) {
			head = head->next;
			delete temp;
		} else {
			Node *prev = temp;
			temp = temp->next;
			while (temp) {
				if (temp->key == oldKey) {
					prev->next = temp->next;
					delete temp;
				}
				prev = temp;
				temp = temp->next;
			}
		}
	}
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
void insert_after(Node *head, int oldKey, int newKey)
{
	// ******** WRITE YOUR CODE HERE ********
	if (head) {
		Node *temp = head;
		while (temp) {
			if (temp->key == oldKey) {
				Node *new_node = new Node(newKey, temp->next);
				temp->next = new_node;
				break;
			} 
			temp = temp->next;
		} 
	}
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
Node *interleave(Node *list1, Node *list2)
{
	// ******** WRITE YOUR CODE HERE ********
	std::vector<int> l1 = to_vector(list1);
	std::vector<int> l2 = to_vector(list2);
	Node *list3 = NULL;
	Node *temp = NULL;
	int l1_index;
	int l2_index;

	if (l1.size() == 0 && l2.size() == 0) {
		return list3;
	} else if (l1.size() == 0) {
		temp = new Node(l2[0], NULL);
		l2_index = 1;
		l1_index = 0;
	} else {
		temp = new Node(l1[0], NULL);
		l2_index = 0;
		l1_index = 1;
	}

	list3 = temp;
	int next = 2;

	while (l1_index < l1.size() && l2_index < l2.size()) {
		if (next == 2) {
			temp->next = new Node(l2[l2_index], NULL);
			temp = temp->next;
			l2_index++;
			next--;
		} 
		if (next == 1) {
			temp->next = new Node(l1[l1_index], NULL);
			temp = temp->next;
			l1_index++;
			next++;
		}
	}
	if (l1_index >= l1.size()) {
		while (l2_index < l2.size()) {
			temp->next = new Node(l2[l2_index], NULL);
			temp = temp->next;
			l2_index++;
		}
	} else {
		while (l1_index < l1.size()) {
			temp->next = new Node(l1[l1_index], NULL);
			temp = temp->next;
			l1_index++;
		}
	}
	return list3;
}
