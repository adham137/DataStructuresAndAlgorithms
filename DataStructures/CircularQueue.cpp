#include "CircularQueue.h"

//-- Definition of the class constructor
CircularQueue::CircularQueue(int k) {
    cap = k;
    first = last = -1;
    arr = new int[cap];
}

//-- Definition of the class destructor
CircularQueue::~CircularQueue() {
    delete arr;
}

//-- Definition of enqueue function
void CircularQueue::enqueue(const QueueElement& value) {
    if (isFull()) {
        cerr << "*** Queue full -- can't add new value ***\n";
        exit(1);
    }

    if (isEmpty()) {
        first = last = 0;
        arr[last] = value;
        return;
    }
    last = ((last + 1) % cap);
    arr[last] = value;
}

//-- Definition of dequeue function
void CircularQueue::dequeue() {
    if (isEmpty()) {
        cerr << "*** Queue empty -- can't remove value ***\n";
        exit(1);
    }
    if (first == last) {
        first = last = -1;
        return;
    }
    first = ((first + 1) % cap);
    return;
}

//-- Definition of front function
QueueElement CircularQueue::front() const {
    if (isEmpty()) {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage = 0;
        return garbage;
    }
    return arr[first];
}

//-- Definition of rear function
QueueElement CircularQueue::rear() const {
    if (isEmpty()) {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage = 0;
        return garbage;
    }
    return arr[last];
}

//-- Definition of isEmpty function
bool CircularQueue::isEmpty() const {
    if (first == -1)return true;
    return false;
}

//-- Definition of isFull function
bool CircularQueue::isFull() const {
    if (((last + 1) % cap) == first) return true;
    return false;
}

//-- Definition of display function
void CircularQueue::display(ostream& out) const
{
    for (int i = first; i != last; i = (i + 1) % cap)
        out << arr[i] << "  ";
    cout << endl;
}

//--- Definition of output operator
ostream& operator<< (ostream& out, const CircularQueue& aQueue) {
    aQueue.display(out);
    return out;
}
