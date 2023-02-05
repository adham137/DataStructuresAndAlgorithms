#include "LinkedQueue.h"

//--- Definition of Queue constructor
LinkedQueue::LinkedQueue()
    : myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
LinkedQueue::LinkedQueue(const LinkedQueue& original)
{
    myFront = myBack = 0;
    if (!original.empty())
    {
        // Copy first node
        myFront = myBack = new LinkedQueue::Node(original.front());

        // Set pointer to run through original's linked list
        LinkedQueue::NodePointer origPtr = original.myFront->next;
        while (origPtr != 0)
        {
            myBack->next = new LinkedQueue::Node(origPtr->data);
            myBack = myBack->next;
            origPtr = origPtr->next;
        }
    }
}

//--- Definition of Queue destructor
LinkedQueue::~LinkedQueue()
{
    // Set pointer to run through the queue
    LinkedQueue::NodePointer prev = myFront,
        ptr;
    while (prev != 0)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

//--- Definition of assignment operator
const LinkedQueue& LinkedQueue::operator=(const LinkedQueue& rightHandSide)
{
    if (this != &rightHandSide)         // check that not q = q
    {
        this->~LinkedQueue();                  // destroy current linked list
        if (rightHandSide.empty())       // empty queue
            myFront = myBack = 0;
        else
        {                                // copy rightHandSide's list
            // Copy first node
            myFront = myBack = new LinkedQueue::Node(rightHandSide.front());

            // Set pointer to run through rightHandSide's linked list
            LinkedQueue::NodePointer rhsPtr = rightHandSide.myFront->next;
            while (rhsPtr != 0)
            {
                myBack->next = new LinkedQueue::Node(rhsPtr->data);
                myBack = myBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

//--- Definition of empty()
bool LinkedQueue::empty() const
{
    return (myFront == 0);
}

//--- Definition of enqueue()
void LinkedQueue::enqueue(const QueueElement& value)
{
    LinkedQueue::NodePointer newptr = new LinkedQueue::Node(value);
    if (empty())
        myFront = myBack = newptr;
    else
    {
        myBack->next = newptr;
        myBack = newptr;
    }
}

//--- Definition of display()
void LinkedQueue::display(ostream& out) const
{
    LinkedQueue::NodePointer ptr;
    for (ptr = myFront; ptr != 0; ptr = ptr->next)
        out << ptr->data << "  ";
    out << endl;

}

//--- Definition of output operator
ostream& operator<< (ostream& out, const LinkedQueue& aQueue) {
    aQueue.display(out);
    return out;
}

//--- Definition of front()
QueueElement LinkedQueue::front() const
{
    if (!empty())
        return (myFront->data);
    else
    {
        cerr << "*** Queue is empty "
            " -- returning garbage ***\n";
        QueueElement* temp = new(QueueElement);
        QueueElement garbage = *temp;     // "Garbage" value
        delete temp;
        return garbage;
    }
}

//--- Definition of dequeue()
void LinkedQueue::dequeue()
{
    if (!empty())
    {
        LinkedQueue::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
        if (myFront == 0)     // queue is now empty
            myBack = 0;
    }
    else
        cerr << "*** Queue is empty -- can't remove a value ***\n";
}