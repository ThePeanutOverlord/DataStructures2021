///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Assignment:       Program_05
// Date:             10 December 2019
// Description:
//       player.h file of Blackjack game:
//            contains player class
//      
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "TermGame.h"
//using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;
/**
 * class: Hand
 * 
 * a doubley linked list representing a player hand
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
 *      void Insert(Card*); //pushes card onto list
 *      void Print(); //print hand
 *      void Select();//select card method
 *      void Draw(Deck);//draw card method
 *      void ChangeA() //changes ace value
 *      int Score //calculates score
 *     
 */
class Hand {
protected:
    Node *Head; // Head of list pointer
    Node *Tail; // Tail of list pointer
    int Count;  // Count of items in list

public:
    Hand();               // Constructor

    ~Hand(); // Destructor
    int Size();
    void Insert(Card*);
    void Print();
    void RevPrint(); //don't need one of these prints probably
    void Select();//select card method
        //if ace have switch value bit
    void Draw(Deck);//draw card method
    void ChangeA();
    int Score();
};
/**
 * Public Score
 * 
 * calculates player Score
 *
 * @Params:
 * 
 *     none
 * 
 * @Returns:
 * 
 *     int sum
 */
int Hand::Score(){
  int sum = 0;
  Node *temp = Head;
  for(int i = 0; i < Count; i++){
      sum += temp->C->FaceValue();
      temp = temp->Next;
  }
  return sum;
  }
/**
 * Public Default Constructor
 */
Hand::Hand() {
    Head = Tail = NULL;
    Count = 0;
}

/**
 * Public Destructor
 */
Hand::~Hand() {
    Node *temp = Head;

    while (temp) {
        temp = temp->Next;
        delete Head;
        Head = temp;
    }
}


/**
 * Public Insert
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
void Hand::Insert(Card* C) {
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
 * Public Draw
 * 
 * Draws a new card from the deck and pushes it into the list
 * 
 * @Params:
 * 
 *     deck
 * 
 * @Returns:
 * 
 *     void
 */
void Hand::Draw(Deck h){ //this function isn't working even though it's basically the same thing I did in main 
//and I don't know why and I wasted too much time on it so I just gave up
  Card *g = new Card();
  g = h.Pop();
  Insert(g);
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
void Hand::Print() {
    Node *Temp = Head;
    cout << "Your hand: \n";
    for(int i = 0; i < Count; i++){
         Temp->C->PrintCard();
        Temp = Temp->Next;
    }
    cout << endl;
}
/**
 * Public ChangeA
 * 
 * changes the value of an ace to 11
 * 
 * @Params:
 * 
 *     none
 * 
 * @Returns:
 * 
 *     void
 */
void Hand::ChangeA(){
  Node *Temp = Head;
  for(int i = 0; i < Count; i++){
     if(Temp->C->sval == "A"){
       Temp->C = new Card(11);
     }
     Temp = Temp->Next;
  }
 
}

/**
 * Public Select
 * 
 * allows player to cycle through hand
 * 
 * @Params:
 * 
 *     none
 * 
 * @Returns:
 * 
 *     void
 */
void Hand::Select(){
  Node* select = Head;
  bool esc = 1;
  char key;
  while(esc){
    select->C->c = 6;
    Print();
    if(TermGame::getarrow() == "ARROW_UP"){
      select = select->Next;
     // cout << "ARROW_UP\n";
      if(select->Prev->C->suit == "♥" || select->Prev->C->suit == "♦"){
       select->Prev->C->c = 2;
       }else if(select->Prev->C->suit == "♣"|| select->Prev->C->suit == "♠"){
         select->Prev->C->c = 1;
        }
    }else if(TermGame::getarrow() == "ARROW_DOWN"){
      select = select->Prev;
     // cout << "ARROW_DOWN\n";
      if(select->Next->C->suit == "♥" || select->Next->C->suit == "♦"){
       select->Prev->C->c = 2;
       }else if(select->Next->C->suit == "♣"|| select->Next->C->suit == "♠"){
         select->Prev->C->c = 1;
        }
      }
  }
  
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
int Hand::Size(){
    return Count;
}

