/*-- AvlTree.h -------------------------------------------------------------

 This header file defines a AvlTree data type.
 Basic operations:
 Constructor:     Constructs an empty AvlTree
 insert:          Modifies a AvlTree by adding a value at the appropriate place
 erase:           Modifies a AvlTree by removing the value
 display:		  Display values of BST using different ways : "in-order" or "pre-order" or "post-order" or "view balance factors"

 update:          Update Node's balance factor upon insert
 balance:		  Balance the avl tree
 hTree:           Find height of a given sub-tree

 rotateRight:	  Preform simple right rotation
 rotateLeft:	  Preform simple left rotation
 rotateRightLeft: Preform right-left rotation
 rotateLeftRight: Preform left-right rotation
 ---------------------------------------------------------------------------*/

#pragma once
#include<string>
using namespace std;


//implementation of a AvlTree class 
class AvlTree {
private:
	class Node {
	public:
		// ******** NODE DATA MEMBERS **********

		long data; //data part of the node
		short balanceFactor; //balance factor of Node;
		Node* right; //ptr to the node to the right
		Node* left; //ptr to the node to the left

		Node(long value) {
			data = value;
			right = left = 0;
		}
	};

	// ******** BinarySearchTree DATA MEMBERS **********

	Node* root; //pointer to the root node
public:
	AvlTree();
	/*-----------------------------------------------------------------------
	 Construct a AvlTree object.

	 Precondition:  None.
	 Postcondition: An empty AvlTree object has been constructed.
	 root node is value is set to zero
	 -----------------------------------------------------------------------*/

	AvlTree(long value);
	/*-----------------------------------------------------------------------
	 Construct a AvlTree object.

	 Precondition:  None.
	 Postcondition: An empty AvlTree object has been constructed.
	 root node is value is set to value
	 -----------------------------------------------------------------------*/

	void insert(long item);
	/*-----------------------------------------------------------------------
	 insert into a AvlTree object.

	 Precondition:  check whether BST is empty.
	 Postcondition: Node object of given value is inserted into AvlTree at
					appropriate place , update function is called then 
					balance function is called.
	 -----------------------------------------------------------------------*/

	void display(string order = "in order");
	/*-----------------------------------------------------------------------
	 display values of a AvlTree object.

	 Precondition:  none.
	 Postcondition: display all values according to desired order.
	 -----------------------------------------------------------------------*/

	void erase(long item);
	/*-----------------------------------------------------------------------
	 erase from a AvlTree object.

	 Precondition:  AvlTree object is not empty.
	 Postcondition: Node object containing item is removed from AvlTree
					object , update function is called then 
					balance function is called.
	 -----------------------------------------------------------------------*/

private:

	void display1(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values of a AvlTree object in-order (LNR).
	 -----------------------------------------------------------------------*/

	void display2(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values of a AvlTree object pre-order (NLR).
	 -----------------------------------------------------------------------*/

	void display3(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values of a AvlTree object post-order (LRN).
	 -----------------------------------------------------------------------*/

	void display4(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values and balance factor of a AvlTree object post-order (LRN).
	 -----------------------------------------------------------------------*/

	int hTree(Node* node);
	/*-----------------------------------------------------------------------
	 find height of sub-tree in order to calculate balance factor

	 Precondition:  none.
	 Postcondition: Height of subtree is returned.
	 -----------------------------------------------------------------------*/

	void update(Node* node);
	/*-----------------------------------------------------------------------
	 update Balance Factors of AvlTree object Nodes.

	 Precondition:  none.
	 Postcondition: Balance factors are updated.
	 -----------------------------------------------------------------------*/

	void balance(long item);
	/*-----------------------------------------------------------------------
	 balance AvlTree object .

	 Precondition:  search for nodes with balance factors of -2 or 2.
	 Postcondition: call rotation functions.
	 -----------------------------------------------------------------------*/

	//---------------------------ROTATION FUNCTIONS---------------------------
	void rotateRight(Node* parent , Node* ptr);
	void rotateLeft(Node* parent, Node* ptr);
	void rotateRightLeft(Node* parent, Node* ptr);
	void rotateLeftRight(Node* parent, Node* ptr);
};
