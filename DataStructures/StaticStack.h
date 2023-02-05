/*-- StaticStack.h --------------------------------------------------------------

 This header file defines a Stack data type.
 Basic operations:
 constructor:  Constructs an empty stack
 empty:        Checks if a stack is empty
 full:         Checks if a stack is full
 push:         Modifies a stack by adding a value at the top
 getTop:          Accesses the top stack value; leaves stack unchanged
 pop:          Modifies stack by removing the value at the top
 display:      Displays all the stack elements
 --------------------------------------------------------------------------*/

#ifndef StaticStack_h
#define StaticStack_h

#include <stdio.h>
#include <iostream>
using namespace std;


typedef int StackElement;

class StaticStack
{
public:
    /***** Function Members *****/
    /***** Constructors *****/
    StaticStack(int CAP);
    /*-----------------------------------------------------------------------
     Construct a LinkedStack object.
     Precondition:  None.
     Postcondition: An empty StaticStack object with array size CAP 
                    has been constructed.
     ------------------------------------------------------------------------*/

    StaticStack(const StaticStack& original);
    //-- copy constructor

    /***** Destructor *****/
    ~StaticStack();
    /*------------------------------------------------------------------------
     Class destructor

     Precondition:  None
     Postcondition: The arr in the stack has been deallocated.
     ------------------------------------------------------------------------*/

     /***** Assignment *****/
    const StaticStack& operator= (const StaticStack& rightHandSide);
    /*------------------------------------------------------------------------
     Assignment Operator
     Precondition:  rightHandSide is the stack to be assigned and is
     received as a const reference parameter.
     Postcondition: The current stack becomes a copy of rightHandSide
     and a const reference to it is returned.
     ------------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
     Check if stack is empty.
     Precondition: None
     Postcondition: Returns true if stack is empty and false otherwise.
     -----------------------------------------------------------------------*/

    bool full() const;
    /*------------------------------------------------------------------------
     Check if stack is full.
     Precondition: None
     Postcondition: Returns true if stack is full and false otherwise.
     -----------------------------------------------------------------------*/

    void push(const StackElement& value);
    /*------------------------------------------------------------------------
     Add a value to a stack.

     Precondition:  value is to be added to this stack
     Postcondition: value is added at top of stack provided there is space;
     otherwise, a stack-full message is displayed and execution is
     terminated.
     -----------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*------------------------------------------------------------------------
     Display values stored in the stack.

     Precondition:  ostream out is open.
     Postcondition: Stack's contents, from top down, have been output to out.
     -----------------------------------------------------------------------*/

    StackElement getTop() const;
    /*------------------------------------------------------------------------
     Retrieve value at top of stack (if any).

     Precondition:  Stack is nonempty
     Postcondition: Value at top of stack is returned, unless the stack is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     -----------------------------------------------------------------------*/

    void pop();
    /*------------------------------------------------------------------------
     Remove value at top of stack (if any).

     Precondition:  Stack is nonempty.
     Postcondition: Value at top of stack has been removed, unless the stack
     is empty; in that case, an error message is displayed and
     execution allowed to proceed.
     -----------------------------------------------------------------------*/

private:
  
    /***** Data Members *****/
    int top,      // pointer to top of stack
        cap;
    StackElement* arr;
}; // end of class declaration

//------ Prototype of output operator
ostream& operator<< (ostream& out, const StaticStack& aStack);


#endif 

