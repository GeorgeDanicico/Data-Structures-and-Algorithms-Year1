#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	// initialize the stack
	this->stack = new BSTNode*[this->map.csize];
	this->first();
}
// Best case: theta(1) when the first element is the root or the left child of the root
// Worst case: theta(n) when the graph is degenerate and for each node until the leaf, it has only a left child
// Total complexity: O(n)
void SMMIterator::first(){
	this->stack_size = 0;
	BSTNode* node = this->map.tree.root;
	this->current_size = 0;

	while (node != nullptr) {
		this->stack[this->stack_size++] = node;
		node = node->left;
	}
	if (this->stack_size > 0) {
		this->current_node = this->stack[this->stack_size - 1];
		this->current_size = 1;
	}
	else
		this->current_node = nullptr;
}
// Best case: theta(1) when the first element is the root or the left child of the root
// Worst case: theta(n) when the graph is degenerate and for each node until the leaf, it has only a left child
// Total complexity: O(n)

void SMMIterator::next(){
	if (this->valid()) {
		if (this->current_size < this->current_node->current_size) {
			this->current_size++;
		}
		else {
			BSTNode* node = this->stack[--this->stack_size];
			node = node->right;
			while (node != nullptr) {
				this->stack[this->stack_size++] = node;
				node = node->left;
			}
			if (this->stack_size > 0) {
				this->current_node = this->stack[this->stack_size - 1];
				this->current_size = 1;
			}
			else
				this->current_node = nullptr;
		}
	}
	else
		throw exception();
}
// Best case: theta(1) if we didnt reach the end of an array for the current node
// Worst case: theta(n) when the graph is almost degenerate, the root has a right child, and from that child, each node has only
// a left child
// Total complexity: O(n)

bool SMMIterator::valid() const{
	if(this->current_node == nullptr)
		return false;
	return true;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

TElem SMMIterator::getCurrent() const{
	if (this->valid()) {
		TElem info{ this->current_node->key, this->current_node->values[current_size - 1] };
		return info;
	}
	else throw exception();
}
// Best case: theta(1)
// Worst case: theta(1)
// Total: theta(1)

SMMIterator::~SMMIterator()
{
	delete[] this->stack;
}


