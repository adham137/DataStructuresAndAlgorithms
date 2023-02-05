/*-- HashTable.h --------------------------------------------------------------

 This header file defines a HashTable data type.
 Basic operations:
 constructor:  Constructs an empty list
 hash:        Checks if a list is empty
 insertLinear:          Modifies a table by adding a value using linear probing
 eraseLinear:           Modifies a list by removing a value using linear probing
 searchLinear:		    checks if the value is present in the table using linear probing
 insertQuadratic:       Modifies a table by adding a value using quadratic probing
 eraseQuadratic:        Modifies a list by removing a value using quadratic probing
 searchQuadratic:       checks if the value is present in the table using quadratic probing
 insertDouble:          Modifies a table by adding a value using double hashing
 eraseLDouble:          Modifies a list by removing a value using double hashing
 searchDouble:          checks if the value is present in the table using double hashing
 display:			    Displays all the table elements
 --------------------------------------------------------------------------*/
#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

const int TableSize = 11;
const int DoubleHashVal = 7;
class HTable
{
private:

    class Node {
        //------ Node DATA MEMBERS
    public:
        int key;
        string ID; // Student ID
        string value; // Student name


        //------ Node OPERATIONS
        //-- Explicit-value constructor

        Node(int K = -1, string id = "", string val = "") {
            key = K; ID = id; value = val;
        }
    };//--- end of Node class
    //------ DATA MEMBERS
    int numberOfElements;
    Node table[TableSize];


    int hash(string key);
    /*--------------------------------------------------------------------
     Hashing Function
     produce an index to insert in
     --------------------------------------------------------------------*/

public:
    HTable();
    /*--------------------------------------------------------------------
     Default constructor: builds an empty table object.
     --------------------------------------------------------------------*/

    // Linear Probing
    void insertLinear(string studentID, string studentName);
    /*--------------------------------------------------------------------
     linear insertion: inserts value according to hash function produced
                       index , in case of a collision it probes for an 
                       empty index linearly (ex. i , i+1 , i+2 .... etc.).

     precondition:     index provided by hash function is avalible
     postcondition:    index is marked is unavalible
     --------------------------------------------------------------------*/

    void removeLinear(string studentID);
    /*--------------------------------------------------------------------
     linear deletion:  deletes value according to hash function produced
                       index , in case value in table doesn't match with
                       provided value it probes for the value linearly
                       
     precondition:     index provided by hash function is unavalible
     postcondition:    index is marked is avalible
     --------------------------------------------------------------------*/

    int searchLinear(string studentID);
    /*--------------------------------------------------------------------
     searches for the value using linear probing and returns it's index
     --------------------------------------------------------------------*/


    // Quadratic Probing
    int GetQuadLoc(int Ndx, int& Sign);
    /*--------------------------------------------------------------------
     produces an index using quadratic probing
     --------------------------------------------------------------------*/

    void insertQuadratic(string studentID, string studentName);
    /*--------------------------------------------------------------------
     Quadratic insertion: inserts value according to hash function produced
                       index , in case of a collision it probes for an
                       empty index quadraticly
                       (ex. i , i+1^2 , i-1^2 ,i+2^2 .... etc.).

     precondition:     index provided by hash function is avalible
     postcondition:    index is marked is unavalible
     --------------------------------------------------------------------*/

    void removeQuadratic(string studentID);
    /*--------------------------------------------------------------------
     Quadratic deletion:  deletes value according to hash function produced
                       index , in case value in table doesn't match with
                       provided value it probes for the value quadraticly

     precondition:     index provided by hash function is unavalible
     postcondition:    index is marked is avalible
     --------------------------------------------------------------------*/

    int searchQuadratic(string studentID);
    /*--------------------------------------------------------------------
     searches for the value using quadratic probing and returns it's index
     --------------------------------------------------------------------*/


    // Double Hashing
    int GetDubLoc(string ID, int Val, int Cnt);
    /*--------------------------------------------------------------------
     produces an index using two quadratic functions
     --------------------------------------------------------------------*/

    void insertDouble(string studentID, string studentName);
    /*--------------------------------------------------------------------
     Double Hashing insertion: inserts value according to hash function produced
                               index , in case of a collision it probes for an
                               empty index using values of original hash function 
                               (i) and othe hash function (k)
                               (ex. i , i+k , i+2k .... etc.).

     precondition:     index provided by hash function is avalible
     postcondition:    index is marked is unavalible
     --------------------------------------------------------------------*/

    void removeDouble(string studentID);
    /*--------------------------------------------------------------------
     Double Hashing deletion:  deletes value according to hash function produced
                               index , in case value in table doesn't match with
                               provided value it probes for the value using a 
                               second hash function

     precondition:     index provided by hash function is unavalible
     postcondition:    index is marked is avalible
     --------------------------------------------------------------------*/

    int searchDouble(string studentID);
    /*--------------------------------------------------------------------
     searches for the value using double and returns it's index
     --------------------------------------------------------------------*/

    void display(ostream& out);
    /*--------------------------------------------------------------------
     display contents of the table's array
     --------------------------------------------------------------------*/

};
ostream& operator<< (ostream& out, HTable aHash);
#endif