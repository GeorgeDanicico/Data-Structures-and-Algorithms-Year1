#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

void SortedMultiMap::resize(BSTNode* node)
{
	// copy the old elements;
	TValue* new_values = new TValue[2 * node->capacity];
	for (int i = 0; i < node->capacity; i++) {
		new_values[i] = node->values[i];
	}
	// clear the memory from the previous array
	free(node->values);

	node->values = new_values;
	node->capacity *= 2;
}
// Best case: theta(n) where n is the previous capacity
// Worst case: theta(n)
// Total: theta(n)


BSTNode* SortedMultiMap::initNode()
{
	BSTNode* n = new BSTNode();
	n->capacity = 8;
	n->current_size = 0;
	n->left = nullptr;
	n->right = nullptr;
	n->values = new TValue[n->capacity];
	
	return n;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

BSTNode* SortedMultiMap::findMinimum(BSTNode* root)
{
	// return the minimum number by going to the left as much as we can
	BSTNode* node = root;
	BSTNode* previous_node = nullptr;
	while (node->left != nullptr) {
		previous_node = node;
		node = node->left;
	}
	// before returning the element, set the link of the parent's left to nullptr
	if (previous_node != nullptr) {
		previous_node->left = node->right;
	}

	return node;
}
// Best case: theta(1) -> when the root does not have a left child.
// Worst case: theta(n) -> the tree is degenerate
// Total: O(n)

void SortedMultiMap::removeNode(BSTNode* parent, BSTNode* child)
{
	// when we have to delete a node, we have 3 cases, when the node does not have a left node, nor a right one.
	// when the node has only on child, the left one, or the right one
	// and when the node has both left and right

	// Case 1
	bool isRoot = (child == this->tree.root ? true : false);
	if (child->left == nullptr && child->right == nullptr) {
		delete child->values;
		if (parent != nullptr && parent->left == child)
			parent->left = nullptr;
		else if(parent != nullptr) parent->right = nullptr;
		delete child;
		if (isRoot == true) {
			this->tree.root = nullptr;
		}
	}
	else if (child->left != nullptr && child->right != nullptr) {
		// Case 3
		BSTNode* minimum = this->findMinimum(child->right);

		if (minimum != child->right)
			minimum->right = child->right;

		minimum->left = child->left;

		if (isRoot) {
			this->tree.root = minimum;
		}
		else {
			if (parent->left == child)
				parent->left = minimum;
			else parent->right = minimum;
	
		}
		delete child->values;
		delete child;
	}
	else {

		// Case 2
		BSTNode* node = child;
		if (isRoot) {
			this->tree.root = (child->left != nullptr ? child->left : child->right);
			delete child->values;
			delete child;
		}
		else {
			if (parent->left == node) {
				parent->left = (child->left != nullptr ? child->left : child->right);
			}
			else
				parent->right = (child->left != nullptr ? child->left : child->right);
		
			delete node->values;
			delete node;
			node = nullptr;
		}

	}


}
// Best case: theta(1) -> if one of the first 2 cases happen 
// Worst case: theta(n) -> if the third case happens, because of the findMinimum function
// Total: O(n)

void SortedMultiMap::inorderTravesal(BSTNode* node)
{
	if (node != nullptr) {
		this->inorderTravesal(node->left);
		this->inorderTravesal(node->right);
		delete node->values;
		delete node;
	}
}
// Best case: theta(n)
// Worst case: theta(n)
// Total: theta(n)


SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation
	this->rel = r;
	this->tree.root = nullptr;
	this->csize = 0;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

void SortedMultiMap::add(TKey c, TValue v) {
	// if the tree is empty, we initialize the root of the tree
	if (this->tree.root == nullptr) {
		this->tree.root = this->initNode();
		this->tree.root->key = c;
		this->tree.root->values[0] = v;
		this->tree.root->current_size++;
	}
	else {
		BSTNode* node = this->tree.root;
		BSTNode* previous_root = nullptr;

		// searching for the position in the tree
		bool found = false;
		// we parse the tree until we find the required position or the given key
		while (node != nullptr && found == false) {
			previous_root = node;
			if (node->key == c) {
				found = true;
			}
			else {
				if (this->rel(c, node->key))
					node = node->left;
				else
					node = node->right;
			}
		}
		// if the element was found, we add a new value, and do a resize if necessary
		if (found == true) {
			// do the resize if the dynamic array of the corresponding key is full.
			if (node->capacity == node->current_size)
				this->resize(node);
			node->values[node->current_size++] = v;

		}
		else {
			// if the element was not found, we create a new node, add the value, and then set the link
			BSTNode* new_node = initNode();
			new_node->key = c;
			new_node->values[new_node->current_size++] = v;

			if (this->rel(c, previous_root->key))
				previous_root->left = new_node;
			else previous_root->right = new_node;
		}
	}
	// increment the number of elements of the BST.
	this->csize++;
}
// Best case: theta(1) -> if the node we are searching for is the root, and the array has enough space
// Worst case: theta(n) -> if the tree is degenerate and also if the array of the node is full and resize is necessary.
// Total: O(n)

vector<TValue> SortedMultiMap::search(TKey c) const {
	// get the root of the tree
	BSTNode* node = this->tree.root;
	bool found = false;

	while (node != nullptr && found == false) {
		if (node->key == c)
			found = true;
		else {
			if (this->rel(c, node->key)) {
				node = node->left;
			}
			else node = node->right;
		}
	}

	if (found == false) {
		return vector<TValue>();
	}
	else 
		return vector<TValue>(node->values, node->values + node->current_size);
}
// Best case: theta(1) -> if the node we are searching for is the root
// Worst case: theta(n) -> if the tree is degenerate to the left.
// Total: O(n)

bool SortedMultiMap::remove(TKey c, TValue v) {
	// we parse the tree to find the element.
	BSTNode* node = this->tree.root;
	BSTNode* previous_root = nullptr;
	bool found = false;

	// search for the key in the tree
	while (node != nullptr && found == false) {
		if (node->key == c)
			found = true;
		else {
			if (this->rel(c, node->key)) {
				previous_root = node;
				node = node->left;
			}
			else { 
				previous_root = node;
				node = node->right; 
			}
		}
	}
	// if the key was not found in the multimap, we exit the remove function returning false
	if (found == false)
		return false;
	else {
		bool value_found = false;
		int i = 0;

		while(i<node->current_size && value_found == false) {
			if (node->values[i] == v) {
				value_found = true;
				// delete the element
				int pos = i;
				for (int j = pos; j < node->current_size - 1; j++) {
					node->values[j] = node->values[j + 1];
				}
				node->current_size--;
				this->csize--;
				if (node->current_size == 0)
					this->removeNode(previous_root, node);
			}
			i++;
		}
		return value_found;
	}
}
// Best case: theta(1) if the node we are searching for is the root, and the value required is the last value in the array.
// Worst case: theta(n + m) if the tree is degenerate and the node we are searching is the last, or the size of the node's values array is greater then the height of the tree.
// Total: O(n + m)

int SortedMultiMap::size() const {
	return csize;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

bool SortedMultiMap::isEmpty() const {
	return csize == 0;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

vector<TValue> SortedMultiMap::removeKey(TKey key)
{
	BSTNode* node = this->tree.root;
	BSTNode* previous = NULL;

	bool found = false;
	// Searching the element in the BST
	// We will keep the previous for the current node in order to remove the 
	while (node != nullptr && found == false) {
		
		if (node->key == key) {
			found = true;
		}
		else {
			if (this->rel(key, node->key)) {
				previous = node;
				node = node->left;
			}
			else {
				previous = node;
				node = node->right;
			}
		}
	}
	// if the element was not found, we return an empty vector.
	if (found == false) {
		return vector<TValue>();
	}
	else {
		// otherwise we iterate throw the DA and add all the elements in the vector
		// and return it.
		vector<TValue> v;
		TValue* Val = node->values;
		for (int i = 0; i < node->current_size; i++) {
			v.push_back(Val[i]);
			this->csize--;
		}
		this->removeNode(previous, node);
		return v;
	}
}
// Best case: theta(1) // when the key we want to delete is the key of the root and the size of the array is 1.
// Worst case: theta(n + m) // when the graph is degenerate, or when the array of the key has the size m, where m > n
// Total: O(n + m)

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

SortedMultiMap::~SortedMultiMap() {

	this->inorderTravesal(this->tree.root);
}
// Best case: theta(n)
// Worst case: theta(n)
// Total: theta(n)
