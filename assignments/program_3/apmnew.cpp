///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Assignment:       Program_03
// Date:             14 November 2019
// Description:
//       This file is an implementation of a doubly linked list of integers.
// 
//       Feel free to use and alter or destroy. Do what you like with this code.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

 ofstream fout ("output.num");

struct Node {
    int data;
    Node *Next;
    Node *Prev;

    Node(int d) {
        data = d;
        Next = NULL;
        Prev = NULL;
    }
};

class BigNum {
private:
    Node *Head;               // Head of list pointer
    Node *Tail;               // Tail of list pointer
    int Count;                // Count of items in list
    void _DeleteTail();
public:
    BigNum();                   // Constructor
    BigNum(string); 
    BigNum(const BigNum &);     // Copy Constructor
    ~BigNum();                  // Destructor
    int Size();
    void InsertFront(int);      
    void InsertBack(int);       
    void Print();
    void RevPrint();
    void Delete();
    void Outfile();
};

/**
 * Public Default Constructor
 */
BigNum::BigNum() {
    Head = Tail = NULL;
    Count = 0;
}

BigNum::BigNum(string number) {
    Head = Tail = NULL;
    Count = 0;
    int digit=0;

  for(int i=0;i<number.size();i++){
    digit = number[i]-48;
   // cout << digit;
       InsertBack(digit);
       Count++;
  }

}

/**
 * Public Copy Constructor 
 *      constructs a new list with values from another list. 
 */
BigNum::BigNum(const BigNum &list){
    Head = Tail = NULL; // Initialize pointers like always
    Count = 0;

    // Point to "Other" lists head. Even though its private we
    // can access it beacuase we are in a class of the same type.
    Node* Other = list.Head;

    // Travers the other list
    while(Other){
        // Insert values into new nodes in this list.
        InsertBack(Other->data);
        Other = Other->Next;
    }
}

/**
 * Public Destructor
 */
BigNum::~BigNum() {
    Node *temp = Head;

    while (temp) {
        temp = temp->Next;
        delete Head;
        Head = temp;
    }
}

/**
 * Public InsertFront
 * 
 * Adds item to head of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     int data : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::InsertFront(int data) {
  
  for(int count2 = Count; count2 > 0; count2--){
    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Head->Prev = Temp;
        Temp->Next = Head;
        Head = Temp;
    }
  }
}

/**
 * Public InsertBack
 * 
 * Adds item to tail of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     int data : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::InsertBack(int data) {
  //for(int count2 = Count; count2 > 0; count2--){
      for(int i = 0; i < 10; i++){
    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Tail->Next = Temp;
        Temp->Prev = Tail;
        Tail = Temp;
    }
    cout << "inserted ";
    }
}

/**
 * Public Print
 * 
 * Prints list to stdout from head to tail
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::Print() {
    Node *Temp = Head;

    while (Temp) {
        cout << Temp->data;
        if (Temp->Next) {
           // cout << "->";
        }
        Temp = Temp->Next;
    }
    cout << endl;
}

/**
 * Private _DeleteTail
 * 
 * Deletes last node in list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::_DeleteTail() {
    
    if(Tail){
        Node *Temp = Tail;
        if(Tail == Head){
            Tail = Head = NULL;
            delete Temp;
        }else{
            
            Tail = Tail->Prev;
            Tail->Next = NULL;
            delete Temp;
        }
        Count--;
    }
}

/**
 * Public Delete
 * 
 * Deletes last node in list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::Delete() {
    _DeleteTail();
}

/**
 * Public Size
 * 
 * Returns size of list
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     int
 */
int BigNum::Size(){
    return Count;
}


/**
 * Public RevPrint
 * 
 *  Prints list to stdout in reverse (tail to head)
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::RevPrint() {
    Node *Temp = Tail;

    while (Temp) {
        cout << Temp->data;
        if (Temp->Prev) {
            cout << "->";
        }
        Temp = Temp->Prev;
    }
    cout << endl;
}

void BigNum::Outfile(){
    Node *Temp = Head;

    while (Temp) {
        fout << Temp->data;
        if (Temp->Next) {
           // cout << "->";
        }
        Temp = Temp->Next;
    }
    fout << endl;
}

int main(){
fout << "Paige Champagne\n";
fout << "Program 3\n";
fout << "Arbitrary Precision Math\n\n";
BigNum r;
ifstream fin ("input_data.txt");
int count;
char op;
string n1;
string n2;

fin >>count;

//for(int i = 0; i < count; i++){

//BigNum q;   
fin >>op>>n1>>n2;
BigNum p(n1);
//p.InsertBack(n1);
p.Print();
//cout << n1 <<endl<<endl;

//p.Outfile();

//q.InsertBack(n2);
//q.Print();
//q.Outfile();
//cout << n2 <<endl<<endl;
//}

return 0;
}