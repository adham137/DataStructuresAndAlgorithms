#include <iostream>
#include "AvlTree.h"
using namespace std;

AvlTree::AvlTree() {
	root = nullptr;
}

AvlTree::AvlTree(long value) {
	root = new Node(value);
}

void AvlTree::insert(long item) {
	if (root == nullptr) {
		root = new Node(item);
		return;
	}

	Node* ptr = root; //points to the desired location of item
	Node* pred = 0; //points to the item's parent node
	while (ptr) {
		pred = ptr;

		if (item == ptr->data) {
			return;
		}
		if (item > ptr->data) {
			ptr = ptr->right;
			continue;
		}
		if (item < ptr->data) {
			ptr = ptr->left;
			continue;
		}
	}
	ptr = new Node(item);
	if (pred->data < item) {
		pred->right = ptr;
	}
	else {
		pred->left = ptr;
	}
	AvlTree::update(root);
	AvlTree::balance(item);
}

void AvlTree::erase(long item) {
	Node* ptr = root;
	Node* parent = 0;
	bool found = false;

	//searching for intended node
	while (ptr) {

		if (ptr->data == item) {
			found = true;
			break;
		}
		if (ptr->data > item) {
			parent = ptr;
			ptr = ptr->left;
			continue;
		}
		if (ptr->data < item) {
			parent = ptr;
			ptr = ptr->right;
			continue;
		}
	}
	if (!found) {
		cerr << "item not found" << endl;
		return;
	}

	//2 children
	if ((ptr->left) && (ptr->right)) {
		//getting right leftmost
		Node* rightleftmost = ptr->right;
		while ((rightleftmost->left) != 0) {
			parent = rightleftmost;
			rightleftmost = rightleftmost->left;
		}
		ptr->data = rightleftmost->data;
		ptr = rightleftmost;
	}


	// 0 or 1 children
	Node* subtree = ptr->left;
	if (subtree == 0) {
		subtree = ptr->right;
	}

	if (parent == 0) {
		root = subtree;
	}else if (parent->left == ptr) {
		parent->left = subtree;
	}else {
		parent->right = subtree;
	}

	AvlTree::update(root);
	AvlTree::balance(item);
}

int AvlTree::hTree(Node* node){
	if (node == NULL)
		return 0;
	else
	{
		int left_side;
		int right_side;
		left_side = hTree(node->left);
		right_side = hTree(node->right);
		if (left_side > right_side)
		{
			return left_side + 1;

		}
		else
			return right_side + 1;
	}
}

void AvlTree::update(Node* node) {
	node->balanceFactor = hTree(node->left) - hTree(node->right);
	if (node->left) update(node->left);
	if (node->right) update(node->right);
}

void AvlTree::balance(long value) { 
	Node* ptr = root; //pointer we are going to use to iterate over the tree with
	Node* parent = nullptr; //pointer to the parent of ptr
	Node* node = nullptr; //pointer to the node we are going to balance
	Node* nodeParent = nullptr; //pointer to the parent of node

	//while loop to find unbalanced sub-tree
	while (ptr) {

		if ((ptr->balanceFactor == -2) || (ptr->balanceFactor == 2)) {
			node = ptr;
			nodeParent = parent;
		}

		parent = ptr;
		if (ptr->data > value)ptr = ptr->left;
		else ptr = ptr->right;
	}

	if (node == nullptr)return;

	else if (node->balanceFactor < 0) {
		if ((node->right)->balanceFactor < 0)AvlTree::rotateLeft(nodeParent, node);
		else AvlTree::rotateRightLeft(nodeParent, node);
	}

	else {
		if ((node->left)->balanceFactor > 0)AvlTree::rotateRight(nodeParent, node);
		else AvlTree::rotateLeftRight(nodeParent, node);
	}

	AvlTree::update(root);


}

//-------------------------DISPLAY FUNCTIONS-----------------------------

void AvlTree::display(string order ) {
	if (order == "in order") display1(root);
	else if (order == "pre order") display2(root);
	else if (order == "post order") display3(root);
	else if (order == "balance factors") display4(root);
}

//displaying inorder (LNR)
void AvlTree::display1(Node* ptr) {

	if (ptr == 0) return;
	display1(ptr->left);
	cout << ptr->data << " ";
	display1(ptr->right);
}

//displaying pre-order (NLR)
void AvlTree::display2(Node* ptr) {

	if (ptr == 0) return;
	cout << ptr->data << " ";
	display2(ptr->left);
	display2(ptr->right);
}

//displaying post-order (LRN)
void AvlTree::display3(Node* ptr) {

	if (ptr == 0) return;
	display3(ptr->left);
	display3(ptr->right);
	cout << ptr->data << " ";
}

//displaying node value and balance factor inorder (LNR)
void AvlTree::display4(Node* ptr) {

	if (ptr == 0) return;
	display4(ptr->left);
	cout << "data: " << ptr->data << " Balance factor: " << ptr->balanceFactor << endl;
	display4(ptr->right);
}

//---------------------------ROTATION FUNCTIONS---------------------------
void AvlTree::rotateRight(Node* parent , Node* ptr) {
	Node* child = ptr->left;

	if (parent == nullptr);
	else if (ptr == parent->right)parent->right = child;
	else parent->left = child;

	if (child->right)ptr->left = child->right;
	else ptr->left = nullptr;

	child->right = ptr;

}

void AvlTree::rotateLeft(Node* parent ,Node* ptr) {
	Node* child = ptr->right;
	
	if (parent == nullptr);
	else if (ptr == parent->right)parent->right = child;
	else parent->left = child;

	if (child->left)ptr->right = child->left;
	else ptr->right = nullptr;

	child->left = ptr;

}

void AvlTree::rotateRightLeft(Node* parent, Node* ptr) {

	Node* child = ptr->right;
	AvlTree::rotateRight(ptr,child);
	AvlTree::rotateLeft(parent,ptr);


}

void AvlTree::rotateLeftRight(Node* parent, Node* ptr) {

	Node* child = ptr->left;
	AvlTree::rotateLeft(ptr, child);
	AvlTree::rotateRight(parent, ptr);

}


//int main() {
//	cout << "enter main function" << endl;
//	AvlTree tree;
//	//50,45,75,65,70,35,25,15,60,20,41,30,55,10,80
//	tree.insert(50);
//	tree.insert(45);
//	tree.insert(75);
//	tree.insert(65);
//	tree.insert(70);
//	tree.insert(35);
//	tree.insert(25);
//	tree.insert(15);
//	tree.insert(60);
//	tree.insert(20);
//	tree.insert(40);
//	tree.insert(30);
//	tree.insert(55);
//	tree.insert(10);
//	tree.insert(80);
//	tree.display("balance factors");
//	return 0;
//}