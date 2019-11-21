///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Assignment:       Program_03
// Date:             14 November 2019
// Description:
//       This program reads in unecessarily long numbers from an imput file
//       and makes them into a doubly linked list of ints with operations for
//       addition, subtraction, and multiplication.
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
    BigNum* Add(BigNum, BigNum);
    BigNum* Sub(BigNum, BigNum);
    BigNum* Mul(BigNum, BigNum);
    bool Empty();
};

/**
 * Public Default Constructor
 */
BigNum::BigNum() {
    Head = Tail = NULL;
    Count = 0;
}
/**
 * string constructor
 * 
 *  takes string read in from main and puts in list while
 *  converting to int
 * @Params:
 * 
 *     string number (long number from file)
 
 */
BigNum::BigNum(string number) {
    Head = Tail = NULL;
    Count = 0;
    int digit=0;

  for(int i=0;i<number.size();i++){
    digit = number[i]-48;
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

    Node *Temp = new Node(data);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Tail->Next = Temp;
        Temp->Prev = Tail;
        Tail = Temp;
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
 * Public Empty
 * 
 *  checks if empty
 * 
 * @Params:
 * 
 *     none
 * 
 * @Returns:
 * 
 *     bool
 */
bool BigNum::Empty(){
  return ((!Head) && (!Tail));
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
        Temp = Temp->Prev;
    }
    cout << endl;
}
/**
 * Public Outfile
 * 
 *  Prints the BigNum to an outfile
 * 
 * @Params:
 * 
 *     Void
 * 
 * @Returns:
 * 
 *     void
 */
void BigNum::Outfile(){
    Node *Temp = Head;
    fout << "Answer:\n\n";
    while (Temp) {
        fout << Temp->data;
        Temp = Temp->Next;
    }
    fout << endl << endl;
}
/**
 * Public Add
 * 
 *  adds two BigNums together and returns the result as a 
 *  new BigNum pointer
 * @Params:
 * 
 *     BigNum x (top number), BigNum y (bottom number)
 * 
 * @Returns:
 * 
 *     Bignum* Result
 */
BigNum* BigNum::Add(BigNum x, BigNum y){
    BigNum* xx = new BigNum(x);   
    BigNum* yy = new BigNum(y);
    BigNum* Result = new BigNum();

    Node* Temp1 = xx->Tail;
    Node* Temp2 = yy->Tail;

    int carry=0;
    int sum=0;

        while(!xx->Empty() && !yy->Empty()){ //how to go through both until the end? Count????

          sum = Temp1->data + Temp2->data + carry;
          carry = sum / 10;
          sum = sum % 10;
          Result->InsertFront(sum);
          Temp1 = Temp1->Prev;
          Temp2 = Temp2->Prev;
          xx->Delete();
          yy->Delete();
        }
        while(!xx->Empty()){
            sum = Temp1->data;
            Result->InsertFront(sum);
            Temp1 = Temp1->Prev;
            xx->Delete();
        }
        while(!yy->Empty()){
            sum = Temp2->data;
            Result->InsertFront(sum);  
            Temp2 = Temp2->Prev;  
            yy->Delete();       
        }
        // handle carry + rest of nums
        return Result;
}
/**
 * Public Sub
 * 
 *  subtracts the bottom BigNum from the top and returns
 *  answer as a new BigNum*
 * @Params:
 * 
 *     BigNum x (top number), BigNum y (bottom number)
 * 
 * @Returns:
 * 
 *     Bignum* Result
 */
BigNum* BigNum::Sub(BigNum x, BigNum y){
    BigNum* xx = new BigNum(x);   
    BigNum* yy = new BigNum(y);
    BigNum* Result = new BigNum();

    Node* Temp1 = xx->Tail;
    Node* Temp2 = yy->Tail;


    int sub=0;

        while(!xx->Empty() && !yy->Empty()){ //how to go through both until the end? Count???
         if(Temp2->data > Temp1->data){
             Temp1->Prev->data -= 1;
          Temp1->data = Temp1->data + 10;  
         }
          sub = Temp1->data - Temp2->data;
          Result->InsertFront(sub);
          Temp1 = Temp1->Prev;
          Temp2 = Temp2->Prev;
          xx->Delete();
          yy->Delete();
        }
        while(!xx->Empty()){
            sub = Temp1->data;
            Result->InsertFront(sub);
            Temp1 = Temp1->Prev;
            xx->Delete();
        }
        return Result;
}
/**
 * Public Mul
 * 
 *  multiplies two BigNums together and returns the result as a 
 *  new BigNum pointer
 * @Params:
 * 
 *     BigNum x (top number), BigNum y (bottom number)
 * 
 * @Returns:
 * 
 *     Bignum* Result
 */
BigNum* BigNum::Mul(BigNum x, BigNum y){
     
    BigNum* yy = new BigNum(y);
    BigNum* Result = new BigNum();
//my attempt at something that would hold the prod for each row and then add   
    //BigNum* add = new BigNum();  //obviously it didn't work
   // Node* hold = add->Tail;
    Node* Temp2 = yy->Tail;
    
    int carry=0;
    int prod=0;
        while(!yy->Empty()){ //how to go through both until the end? Count????
        BigNum* xx = new BigNum(x); 
          Node* Temp1 = xx->Tail; 
            while(!xx->Empty()){
            prod = Temp2->data * Temp1->data + carry;
            carry = prod / 10;
            prod = prod % 10;
            Temp1 = Temp1->Prev;
           // hold->data += prod; //I left all the hold stuff in here because
           // hold = hold->Prev;  //either I was close, or I should just change
            xx->Delete();         //my major back to mass comm
          /*  if(xx->Empty()){
                hold->data += carry;
            }*/
            }
           // hold = add->Tail;
        Result->InsertFront(prod);
          Temp2 = Temp2->Prev;
          yy->Delete();
        }
       
       /* while(!add->Empty()){
        Result->InsertFront(hold->data);
        hold = hold->Prev;
        add->Delete();
        }   */
        return Result;
}
/**
 * Main
 * 
 *  hey, it's ya boi, main, it has some variables, like the BigNums,
 *  and the loop that I use to traverse the file
 *  
 */
int main(){
fout << "Paige Champagne\n";
fout << "Program 3\n";
fout << "Arbitrary Precision Math\n\n";

ifstream fin ("input_data.txt");
int count;
char op;
string n1;
string n2;

fin >>count;

for(int i = 1; i <= count; i++){  
fin >>op>>n1>>n2;
BigNum* r;
BigNum p(n1);
BigNum q(n2);
fout << "Operation " << i << ": ";
switch(op){
    case '+':
        fout << "Addition\n";
        r = p.Add(p, q);
        r->Outfile();
        break;
    case '-':
        fout << "Subtraction\n";
        r = p.Sub(p, q);
        r->Outfile();
        break;
    case '*':
        fout << "Multiplication\n";
        r = p.Mul(p, q);
        r->Outfile();
        break;
}

}
return 0;
}