/*-- CircularQueue.h -------------------------------------------------------------

 This header file defines a CircularQueue data type.
 Basic operations:
 Constructor: Constructs an empty queue
 enqueue:     Modifies a queue by adding a value at the back
 dequeue:     Modifies a queue by removing the value at the front
 front:       Accesses the front queue value; leaves queue unchanged
 rear:		  Accesses the back queue value; leaves queue unchanged
 isEmpty:     Checks if a queue is empty
 isFull:	  checks if a queue is full
 display:     Displays the queue elements from front to back

 ---------------------------------------------------------------------------*/

#ifndef CircularQueue_h
#define CircularQueue_h

#include <iostream>
using namespace std;

typedef int QueueElement;

class CircularQueue
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    CircularQueue(int CAPACITY);
    /*-----------------------------------------------------------------------
     Construct a Queue object.

     Precondition:  None.
     Postcondition: An empty Queue object has been constructed; myFront
     and myBack are initialized to -1 and myArray is an array with
     cap elements of type QueueElement.
     ----------------------------------------------------------------------*/

     /***** Destructor *****/
    ~CircularQueue();
    /*-----------------------------------------------------------------------
     Class destructor

     Precondition:  None.
     Postcondition: The list in the queue has been deallocated.
     -----------------------------------------------------------------------*/

    bool isEmpty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.

     Precondition: None.
     Postcondition: True is returned if the queue is empty and false is
     returned otherwise.
     ----------------------------------------------------------------------*/

    bool isFull() const;
    /*-----------------------------------------------------------------------
     Check if queue is full.

     Precondition: None.
     Postcondition: True is returned if the queue is full and false is
     returned otherwise.
     ----------------------------------------------------------------------*/

    void enqueue(const QueueElement& value);
    /*-----------------------------------------------------------------------
     Add a value to a queue.

     Precondition:  queue is not full.
     Postcondition: value is added to back of queue provided there is space;
     otherwise, a queue-full message is displayed and execution is
     terminated.
     -----------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*-----------------------------------------------------------------------
     Output the values stored in the queue.

     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been output
     to out.
     -----------------------------------------------------------------------*/

    QueueElement front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless queue is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     ----------------------------------------------------------------------*/

    QueueElement rear() const;
    /*-----------------------------------------------------------------------
     Retrieve value at rear of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at rear of queue is returned, unless queue is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     ----------------------------------------------------------------------*/

    void dequeue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless queue
     is empty; in that case, an error message is displayed and
     execution is terminated.
     ----------------------------------------------------------------------*/

private:
    /***** Data Members *****/
    int first,
        last,
        cap;
    QueueElement* arr;
    
}; // end of class declaration


//------ Prototype of output operator
ostream& operator<< (ostream& out, const CircularQueue& aList);


#endif 