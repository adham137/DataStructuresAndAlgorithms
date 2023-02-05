#include "StaticStack.h"

//-- Definition of the class constructor
StaticStack::StaticStack(int CAP) {
	top = -1;
	cap = CAP;
	arr = new int[cap];
}

//-- Definition of the class copy constructor
StaticStack::StaticStack(const StaticStack& original) {
	top = original.top;
	cap = original.cap;
	arr = new int[cap];
	int i;
	for (i = 0;i < cap;i++) {
		arr[i] = original.arr[i];
	}
}

//-- Definition of the class destructor
StaticStack::~StaticStack() {
	delete arr;
}

//-- Definition of empty function
bool StaticStack::empty() const{
	if (top == -1)return true;
	return false;
}

//-- Definition of full function
bool StaticStack::full() const {
	if (top == cap-1)return true;
	return false;
}

//-- Definition of push function
void StaticStack::push(const StackElement& value) {
	if (full()) {
		cerr << "*** Stack full -- can't add new value ***\n";
		exit(1);
	}
	top++;
	arr[top] = value;
}

//-- Definition of pop function
void StaticStack::pop() {
	if (empty()) {
		cerr << "*** Stack empty -- can't remove value ***\n";
		exit(1);
	}
	top--;
}

//-- Definition of getTop function
StackElement StaticStack::getTop() const {
	if (empty()) {
		cerr << "*** stack is empty -- returning garbage value ***\n";
		StackElement garbage = 0;
		return garbage;
	}
	return arr[top];
}

//-- Definition of display function
void StaticStack::display(ostream& out) const {
	int i;
	for (i = top;i < 0;i--) {
		out << arr[i] << " ";
	}
	cout << endl;
}

//-- Definition of assignment operator
const StaticStack& StaticStack::operator=(const StaticStack& rightHandSide)
{
	if (this != &rightHandSide)         // check that not st = st
	{
		this->~StaticStack();                  // destroy current linked list
		if (rightHandSide.empty())       // empty stack
			top = 0;
		else
		{                                // copy rightHandSide's array
			int i;
			for (i = 0;i < cap;i++) {
				this->arr[i] = rightHandSide.arr[i];
			}
		}
	}
	return *this;
}

//-- Definition of output operator
ostream& operator<< (ostream& out, const StaticStack& aStack)
{
	aStack.display(out);
	return out;
}

