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

struct Node{
    char *digit;
    Node *Next;
    Node *Prev;

    Node(char *d){
        digit = d;
        Next = NULL;
        Prev = NULL;
    }
};

class Num{
    private:
        Node *First;
       // Node *Last;
    public:
    Num(){
        First = NULL;
        //Last = NULL;
    }
   void pushnum(string* a){ //@ end call method to sub 48
       int count = 0;
       char *b;
       Node *Temp = First;
       cout <<"fuuuuuuuuuuuuuuuck";
        do{
            b = a[count];
            Node* newt = new Node(b);
            cout << newt->digit << " ";
            Temp = newt;
            Temp->Prev = Temp;
            Temp = Temp->Next;
            cout << "Previous: " << Temp->Prev->digit << " ";
            cout << "Current: " << Temp->digit << " ";

           count++;
        }while(count < 100);
   }
    

};

/*string convert(string a){
    int count = 0;
    while(a[count] != ){
        a[count]+= 48;
        count++;
    }
    return a;
}*/

int main(){
ifstream fin ("input_data.txt");
int count;
char op;
string* n1;
string* n2;
Num poop;

 fin >> count;
/*
 for(int i = 0; i < count; i++){
    fin << op;
    fin << n1;
    fin << n2;
    //push num1 and num2 here
    switch(op){
        case '+':
            //
            break;
    }
 }*/

 fin >> op;
 istream& getline (istream&  is, string& n1); //maybe use getline?????????
 cout << n1 <<endl;
poop.pushnum(n1);
return 0;
}