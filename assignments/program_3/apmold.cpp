///////////////////////////////////////////////////////////////////////////////
//
// Author:           PAIGE CHAMPAGNE
// Assignment:       Program_03
// Date:             14 November 2019
// Title:            Program 3 - Arbitrary Precision Math
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            apm.cpp,  
//                   input_data.txt 
//                   output.num
// Description:
//       This program reads in a very large number as a string and uses a 
//       doubly linked list to add, subtract, and multiply the numbers
//       as per the file instructions.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
/**
 * Node
 * 
 * Description:
 *      makes up the doubly linked list
 * 
 * Params:
 *      char d: character from string in file
 *      Node* a: node for arithmetic
 *
 */
struct Node{
    int digit;
    Node *Next;
    Node *Prev;

    Node(char d){
        digit = d - 48;
        Next = NULL;
        Prev = NULL;
    }
   Node(Node* a){
        digit = a->digit;
        Next = a->Next;
        Prev = a->Prev;
    }
    Node(int g){
        digit = g;
        Next = NULL;
        Prev = NULL;
    }
};
/**
 * Num
 * 
 * Description:
 *      class for the doubly linked list
 * 
 * Params:
 *      made up of Nodes
 * Contains:
 *      constructor, pushnums, add, sub, mul, printresult
 *
 */
class Num{
    private:
        Node* First;
        Node* Last;
        int count;
    public:
    Node* F = First;
    Node* L = Last;
    Num(){
        First = NULL;
        Last = NULL;
        count = 0;
    }
 /**
 * pushnum
 * 
 * Description:
 *      pushes digits onto the list
 * 
 * Params:
 *      string val1 : A string representation of an integer number.
 * 
 * Returns:
 *      void
 */
   void pushnum(string a){ //@ end call method to sub 48
        do{
       Node *Temp = new Node(a[count]);          
       if(!First){
        First = Temp;
        Last = Temp;
        Last->Prev = First;
        Last->Next = First;
        First->Prev = Last;
        First->Next = Last;
       } else{
        Temp->Prev = First;
        Temp->Next = Last;
        First->Next = Temp;
        Last->Prev = Temp;
        Last = Temp;
         }
           count++;
        }while(a[count] != 0);
   }
   /**
 * pushnum
 * 
 * Description:
 *      pushes digits onto the list
 * 
 * Params:
 *      integer a: int form of digits in a node
 * 
 * Returns:
 *      void
 */
   void pushnum(int a){ //@ end call method to sub 48
        do{
       Node *Temp = new Node(a);           
       if(!First){
        First = Temp;
        Last = Temp;
        Last->Prev = First;
        Last->Next = First;
        First->Prev = Last;
        First->Next = Last;
       } else{
        Temp->Prev = First;
        Temp->Next = Last;
        First->Next = Temp;
        Last->Prev = Temp;
        Last = Temp;
         }
           count++;
        }while(a != 0);
   }
 /**
 * Add
 * 
 * Description:
 *      Adds to doubly linked lists together.
 * 
 * Params:
 *      Node* b: supposedly points at n2 from main
 * 
 * Returns:
 *      Node* result: a list with addition results
 */  
    Node* Add(Node* b){
    Node* Temp = new Node(Last->digit);
    Num c;
    int i = 0;
        while(Temp != First){
           i = Temp->digit + b->digit;
           while(i > 9){
             Temp = Temp->Prev;  
            i= Temp->digit += i%9;
           };
            c.pushnum(i);            
        }
    Node* result = c.First;
    return result;
    };
/**
 * Sub
 * 
 * Description:
 *       subtracts one doubly linked list from another.
 * 
 * Params:
 *      Node* b: supposedly points at n2 from main
 * 
 * Returns:
 *      Node* : a list with subtraction results
 */
    Node* Sub(Node* b){
        Node* Temp = new Node(Last->digit);
    Num c;
    int i = 0;
        while(Temp != First){
           i = Temp->digit - b->digit;
           while(i > 9){
             Temp = Temp->Prev;  
            i= Temp->digit += i%9;
           };
            c.pushnum(i);            
        }
    Node* result = c.First;
    return result;
    }
 /**
 * Mul
 * 
 * Description:
 *      multiplies two doubly linked lists together.
 * 
 * Params:
 *      Node* b: supposedly points at n2 from main
 * 
 * Returns:
 *      Node* : a list with multiplication results
 */
    Node* Mul(Node* b){
     Node* Temp = new Node(Last->digit);
    Num c;
    int i = 0;
        while(Temp != First){
           i = Temp->digit * b->digit;
           while(i > 9){
             Temp = Temp->Prev;  
            i= Temp->digit += i%9;
           };
            c.pushnum(i);            
        }
    Node* result = c.First;
    return result;
    }
/**
 * PrintResult
 * 
 * Description:
 *      prints results of arithmetic to outfile output.num
 * 
 * Params:
 *     Node* answer: supposedly points at n2 from main
 * 
 * Returns:
 *      Node* : a list with addition results
 */
    void PrintResult(Node* answer){
        ofstream fout ("output.num");
         Node *temp = First;

        while (temp != Last)
        {   
            fout << temp->digit;
            temp = temp->Prev;
        }
        fout << temp->digit <<endl;
    }


 /**
 * Swap
 * 
 * Description:
 *      Adds to doubly linked lists together.
 * 
 * Params:
 *      string val1 : A string representation of an integer number.
 *      string val2 : A string representation of an integer number.
 * 
 * Returns:
 *      Node* : a list with addition results
 */
    void Print()
    {   
        Node *temp = First;

        while (temp != Last)
        {   
            cout << temp->digit;
            temp = temp->Prev;
        }
        cout << temp->digit <<endl;
        cout <<endl<<endl;
    }

};


/**
 * main
 * 
 * Description:
 *      main function
 * 
 * Params:
 * 
 * Returns:
 *      0
 */
int main(){
Num p;
Num q;
Num r;
ifstream fin ("input_data.txt");
int count;
char op;
string n1;
string n2;


 fin >> count;

 for(int i = 0; i < count; i++){
    fin >> op;
    fin >> n1;
    fin >> n2;
    p.pushnum(n1);
    //p.Print();    
    q.pushnum(n2);
    //q.Print();    
    Node* x = new Node(q.F);
    switch(op){
        case '+':{
            p.PrintResult(p.Add(x));
           break;
        }
        case '-':{
            p.PrintResult(p.Sub(x));
            break;
        }
        case '*':{
            p.PrintResult(p.Mul(x));
            break;
        }
           
    
    }
 };

return 0;
}