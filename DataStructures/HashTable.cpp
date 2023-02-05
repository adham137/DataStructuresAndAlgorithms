#include "HashTable.h"

HTable::HTable()
{
    numberOfElements = 0;
}
//------------------------ Hash function ----------------------------------------
int HTable::hash(string ID)
{
    int sum = 0;
    for (int i = 0; i < ID.length(); i++)
        sum += ID[i];
    return sum % TableSize;
}
//----------------- insert Linear probing ---------------------------------------
void HTable::insertLinear(string studentID, string studentName)
{
    int index = hash(studentID);
    int loc;
    Node n(index, studentID, studentName);

    if (table[index].ID == studentID) {
        cout << "Student with ID: " << studentID << " and name: " << studentName << " already exists." << endl;
        return;
    }

    if (table[index].key == -1 || table[index].key == -2) { // No collision
        table[index] = n;
        numberOfElements++;
    }
    else { // Collision
        for (int i = 1; i < TableSize; i++) {
            loc = (i + index) % TableSize;
            if (table[loc].ID == studentID) {
                cout << "Student with ID: " << studentID << " and name: " << studentName << " already exists." << endl;
                return;
            }
            if (table[loc].key == -1 || table[loc].key == -2) { // No collision
                table[loc] = n;
                numberOfElements++;
                return;
            }
        }
    }
}
//----------------- remove Linear probing ---------------------------------------
void HTable::removeLinear(string studentID) {
    int index = hash(studentID);
    int loc;
    if (table[index].ID == studentID) {
        table[index].key = -2;
        table[index].ID = "";
        table[index].value = "";
        numberOfElements--;
        return;
    }
    else {
        for (int i = 1; i < TableSize; i++) {
            loc = (i + index) % TableSize;
            if (table[loc].key == -1) {
                cout << "Student with ID: " << studentID << " NOT exists." << endl;
                return;
            }
            if (table[loc].ID == studentID) {
                table[loc].key = -2;
                table[loc].ID = "";
                table[loc].value = "";
                numberOfElements--;
                return;
            }
        }
    }
}
//----------------- search Linear probing ---------------------------------------
int HTable::searchLinear(string studentID) {
    int index = hash(studentID);
    int loc;
    if (table[index].ID == studentID) {
        cout << "Student with ID: " << studentID << " exists." << endl;
        cout << setw(2) << index << ": " << setw(2) << table[index].key
            << ": " << setw(3) << table[index].ID << ": " << setw(10) << table[index].value << endl;
        return index;
    }
    else {
        for (int i = 1; i < TableSize; i++) {
            loc = (i + index) % TableSize;
            if (table[loc].key == -1) {
                cout << "Student with ID: " << studentID << " NOT exists." << endl;
                return -1;
            }
            if (table[loc].ID == studentID) {
                cout << "Student with ID: " << studentID << " exists." << endl;
                cout << setw(2) << loc << ": " << setw(2) << table[loc].key
                    << ": " << setw(3) << table[loc].ID << ": " << setw(10) << table[loc].value << endl;
                return loc;
            }
        }
    }
    return -1;
}
//------------------- Display Hash Table ------------------------------------
void HTable::display(ostream& out) {
    for (int i = 0; i < TableSize; i++) {
        if (table[i].key == -1 || table[i].key == -2)
            continue;
        out << setw(2) << i << ": " << setw(2) << table[i].key << ": " << setw(3) << table[i].ID << ": "
            << setw(10) << table[i].value << endl;
    }
}
//--------------- Overloading output << operator --------------------------------
ostream& operator<< (ostream& out, HTable aHash) {
    aHash.display(out);
    return out;
}
//------------------- Get Quadratic Location ------------------------------------
int HTable::GetQuadLoc(int Ndx, int& Sign) {
    int loc;
    if (Sign > 0) {
        loc = (Ndx + (Sign * Sign)) % TableSize;
        Sign = Sign * -1;
    }
    else {
        Sign = Sign * -1;
        loc = (Ndx - (Sign * Sign)) % TableSize;
        Sign++;
        if (loc < 0)
            loc = TableSize + loc;
    }
    return loc;
}

//----------------- insert Quadratic probing ------------------------------------
void HTable::insertQuadratic(string studentID, string studentName)
{
    int index = hash(studentID);
    int loc, i = 1;
    Node n(index, studentID, studentName);

    if (table[index].ID == studentID) {
        cout << "Student with ID: " << studentID << " and name: " << studentName << " already exists." << endl;
        return;
    }

    if (table[index].key == -1 || table[index].key == -2) { // No collision
        table[index] = n;
        numberOfElements++;
    }
    else { // Collision
        while (true) {
            loc = GetQuadLoc(index, i);
            if (table[loc].ID == studentID) {
                cout << "Student with ID: " << studentID << " and name: " << studentName << " already exists." << endl;
                return;
            }
            if (table[loc].key == -1 || table[loc].key == -2) { // No collision
                table[loc] = n;
                n.key = loc;
                numberOfElements++;
                return;
            }
            if (abs(i) > TableSize / 2) {
                cout << "Hash Table is full, Can't insert" << endl;
                return;
            }
        }
    }
}

//----------------- remove Quadratic probing ------------------------------------
void HTable::removeQuadratic(string studentID) {
    int index = hash(studentID);
    int loc, i = 1;
    if (table[index].ID == studentID) {
        table[index].key = -2;
        table[index].ID = "";
        table[index].value = "";
        numberOfElements--;
        return;
    }
    else {
        while (true) {
            loc = GetQuadLoc(index, i);
            if (table[loc].key == -1) {
                cout << "Student with ID: " << studentID << " NOT exists." << endl;
                return;
            }
            if (table[loc].ID == studentID) {
                table[loc].key = -2;
                table[loc].ID = "";
                table[loc].value = "";
                numberOfElements--;
                return;
            }
        }
    }
}

//------------ search Quadratic probing ------------------------------------
int HTable::searchQuadratic(string studentID) {
    int index = hash(studentID);
    int loc, i = 0;
    if (table[index].ID == studentID) {
        cout << "Student with ID: " << studentID << " exists." << endl;
        cout << setw(2) << index << ": " << setw(2) << table[index].key
            << ": " << setw(3) << table[index].ID << ": " << setw(10) << table[index].value << endl;

        return index;
    }
    else {
        while (true) {
            loc = GetQuadLoc(index, i);
            if (table[loc].key == -1) {
                cout << "Student with ID: " << studentID << " NOT exists." << endl;
                return -1;
            }
            if (table[loc].ID == studentID) {
                cout << "Student with ID: " << studentID << " exists." << endl;
                cout << setw(2) << loc << ": " << setw(2) << table[loc].key
                    << ": " << setw(3) << table[loc].ID << ": " << setw(10) << table[loc].value << endl;
                return loc;
            }
            if (abs(i) > TableSize / 2) {
                cout << "Item doesn't exists" << endl;
                return -1;
            }
        }
    }
    return -1;
}

//----------------- Get Double Hashing Location ---------------------------------
int HTable::GetDubLoc(string ID, int Val, int Cnt) {
    int sum = 0, h1, h2;
    for (int i = 0; i < ID.length(); i++)
        sum += ID[i];
    h1 = sum % TableSize;
    h2 = Val - (sum % Val);
    return((h1 + (Cnt * h2)) % TableSize);
}
//----------------- insert Double Hashing ------------------------------------
void HTable::insertDouble(string studentID, string studentName)
{
    int index = hash(studentID);
    int loc;
    Node n(index, studentID, studentName);

    if (table[index].ID == studentID) {
        cout << "Student with ID: " << studentID << " and name: " << studentName << " already exists." << endl;
        return;
    }

    if (table[index].key == -1 || table[index].key == -2) { // No collision
        table[index] = n;
        numberOfElements++;
    }
    else { // Collision
        for (int i = 1; i < TableSize; i++) {
            loc = GetDubLoc(studentID, DoubleHashVal, i);
            if (table[loc].ID == studentID) {
                cout << "Student with ID: " << studentID << " and name: " << studentName << " already exists." << endl;
                return;
            }
            if (table[loc].key == -1 || table[loc].key == -2) { // No collision
                table[loc] = n;
                n.key = loc;
                numberOfElements++;
                return;
            }
        }
        cout << "Hash Table is full, Can't insert" << endl;
        return;
    }
}
//----------------- remove Double probing ------------------------------------
void HTable::removeDouble(string studentID) {
    int index = hash(studentID);
    int loc;
    if (table[index].ID == studentID) {
        table[index].key = -2;
        table[index].ID = "";
        table[index].value = "";
        numberOfElements--;
        return;
    }
    else {
        for (int i = 1; i < TableSize; i++) {
            loc = GetDubLoc(studentID, DoubleHashVal, i);
            if (table[loc].key == -1) {
                cout << "Student with ID: " << studentID << " NOT exists." << endl;
                return;
            }
            if (table[loc].ID == studentID) {
                table[loc].key = -2;
                table[loc].ID = "";
                table[loc].value = "";
                numberOfElements--;
                return;
            }
        }
    }
}

//------------ search Double probing ------------------------------------
int HTable::searchDouble(string studentID) {
    int index = hash(studentID);
    int loc;
    if (table[index].ID == studentID) {
        cout << "Student with ID: " << studentID << " exists." << endl;
        cout << setw(2) << index << ": " << setw(2) << table[index].key
            << ": " << setw(3) << table[index].ID << ": " << setw(10) << table[index].value << endl;
        return index;
    }
    else {
        for (int i = 1; i < TableSize; i++) {
            loc = GetDubLoc(studentID, DoubleHashVal, i);
            if (table[loc].key == -1) {
                cout << "Student with ID: " << studentID << " NOT exists." << endl;
                return -1;
            }
            if (table[loc].ID == studentID) {
                cout << "Student with ID: " << studentID << " exists." << endl;
                cout << setw(2) << loc << ": " << setw(2) << table[loc].key
                    << ": " << setw(3) << table[loc].ID << ": " << setw(10) << table[loc].value << endl;
                return loc;
            }
            if (abs(i) > TableSize / 2) {
                cout << "Item doesn't exists" << endl;
                return -1;
            }
        }
        cout << "Item doesn't exists" << endl;
        return -1;
    }
}