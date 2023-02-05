using namespace std;

#include "LinkedStack.h"
//--- Definition of Stack constructor
LinkedStack::LinkedStack()
    : myTop(0)
{}

//--- Definition of Stack copy constructor
LinkedStack::LinkedStack(const LinkedStack& original)
{
    myTop = 0;
    if (!original.empty())
    {
        // Copy first node
        myTop = new LinkedStack::Node(original.top());

        // Set pointers to run through the stacks’ linked lists
        LinkedStack::NodePointer lastPtr = myTop,
            origPtr = original.myTop->next;

        while (origPtr != 0)
        {
            lastPtr->next = new LinkedStack::Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}

//--- Definition of Stack destructor
LinkedStack::~LinkedStack()
{
    // Set pointers to run through the stack
    LinkedStack::NodePointer currPtr = myTop,  // node to be deallocated
        nextPtr;          // its successor
    while (currPtr != 0)
    {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

//--- Definition of assignment operator
const LinkedStack& LinkedStack::operator=(const LinkedStack& rightHandSide)
{
    if (this != &rightHandSide)         // check that not st = st
    {
        this->~LinkedStack();                  // destroy current linked list
        if (rightHandSide.empty())       // empty stack
            myTop = 0;
        else
        {                                // copy rightHandSide's list
            // Copy first node
            myTop = new LinkedStack::Node(rightHandSide.top());

            // Set pointers to run through the stacks' linked lists
            LinkedStack::NodePointer lastPtr = myTop,
                rhsPtr = rightHandSide.myTop->next;

            while (rhsPtr != 0)
            {
                lastPtr->next = new LinkedStack::Node(rhsPtr->data);
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

//--- Definition of empty()
bool LinkedStack::empty() const
{
    return (myTop == 0);
}

//--- Definition of push()
void LinkedStack::push(const StackElement& value)
{
    myTop = new LinkedStack::Node(value, myTop);
}

//--- Definition of display()
void LinkedStack::display(ostream& out) const
{
    LinkedStack::NodePointer ptr;
    for (ptr = myTop; ptr != 0; ptr = ptr->next)
        out << ptr->data << endl;
}

//--- Definition of output operator
ostream& operator<< (ostream& out, const LinkedStack& aStack)
{
    aStack.display(out);
    return out;
}

//--- Definition of top()
StackElement LinkedStack::top() const
{
    if (!empty())
        return (myTop->data);
    else
    {
        cerr << "*** Stack is empty "
            " -- returning garbage ***\n";
        StackElement* temp = new(StackElement);
        StackElement garbage = *temp;     // "Garbage" value
        delete temp;
        return garbage;
    }
}

//--- Definition of pop()
void LinkedStack::pop()
{
    if (!empty())
    {
        LinkedStack::NodePointer ptr = myTop;
        myTop = myTop->next;
        delete ptr;
    }
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}
