///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Assignment:       Program_05
// Date:             10 December 2019
// Description:
//       opponent.h file of Blackjack game:
//            contains opponent class
//      
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "TermGame.h"
using namespace std;
//using namespace TermGame;
//using namespace TermPrint;
namespace TG = TermGame;
namespace TP = TermPrint;
/**
 * class: Hand
 * 
 * a doubley linked list representing an opponent hand
 *
 * @variables:
 * Node *Head; // Head of list pointer
 * Node *Tail; // Tail of list pointer
 *  int Count;  
 * 
 * @Methods:
 *        Hand();               // Constructor
 *
 *       ~Hand(); // Destructor
 *      int Size(); //size of list
 *      void Insertop(Card*); //pushes card onto list
 *      void Printop(); //print hand
 *      int Scoreop //calculates score
 *     void PrintBack() //prints blank
 *      void drawop
 *     
 */
class Opponent{
  private:
    Node *Head; // Head of list pointer
    Node *Tail; // Tail of list pointer
    int Count;  // Count of items in list

  public:
  /**
 * Public Default Constructor
 */
Opponent() {
    Head = Tail = NULL;
    Count = 0;
}

/**
 * Public Destructor
 */
~Opponent() {
    Node *temp = Head;

    while (temp) {
        temp = temp->Next;
        delete Head;
        Head = temp;
    }
}
/**
 * Public PrintBack
 * 
 * prints blank opponent cards
 *
 * @Params:
 * 
 *     none
 * 
 * @Returns:
 * 
 *     void
 */
  void PrintBack(){
   cout << "Opponent Hand: \n";
   string y;
    y = "";
   // y += c;
    y += "┌────┐\n";
    //y +=c;
    y += "│";
    y +="   ";
   
    y += " │\n";
   // y+=c;
    y += "│  ";
    y += "  │\n";
    //y +=c;
    y += "└────┘\n";
    string han = TermPrint::fuse(y, y);
    cout << han <<endl;
    if(Count == 3){
    TermPrint::fuse(y, han);
    cout << han <<endl;
    }
    /*for(int i = 0; i < Count; i++){
      TermPrint::print(y, 8, 2, false);
    }*/

  }

/**
 * Public Printop
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
void Printop() {
    Node *Temp = Head;
    cout << "Opponent Hand: \n";
    for(int i = 0; i < Count; i++){
         Temp->C->PrintCard();
        Temp = Temp->Next;
    }
    cout << endl;
}

/**
 * Public Insertop
 * 
 * Adds item to tail of list by calling private method with a node.
 * 
 * @Params:
 * 
 *     card* C : item to be placed in list
 * 
 * @Returns:
 * 
 *     void
 */
void Insertop(Card* C) {
    Node *Temp = new Node(C);

    if (!Head) {
        Head = Temp;
        Tail = Temp;
    } else {
        Tail->Next = Temp;
        Temp->Prev = Tail;
        Tail = Temp;
        Temp->Next = Head;
        Head->Prev = Temp;
        //cout << TermPrint::fuse(Temp->C->Format(), Temp->Prev->C->Format()); //ha ha this also isn't working love that for me
    }
    Count++;
}
/**
 * Public drawop
 * 
 * randomly determines to draw another card
 *
 * @Params:
 * 
 *     deck
 * 
 * @Returns:
 * 
 *     void
 */
void drawop(Deck h){
  bool doit = rand() % 2 + 0;
  if(doit == true){
    Insertop(h.Pop());
     Node *Temp = Head;
  for(int i = 0; i < Count; i++){
     if(Temp->C->sval == "A"){
       Temp->C = new Card(11);
     }
     Temp = Temp->Next;
  }
  } 
}
/**
 * Public opScore
 * 
 * calculates opponent Score
 *
 * @Params:
 * 
 *     none
 * 
 * @Returns:
 * 
 *     int sum
 */
int opScore(){
  int sum = 0;
  Node *temp = Head;
  for(int i = 0; i < Count; i++){
      sum += temp->C->FaceValue();
      temp = temp->Next;
  }
  return sum;
  }
};