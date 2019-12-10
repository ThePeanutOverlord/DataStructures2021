///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Assignment:       Program_05
// Date:             10 December 2019
// Description:
//       deck.h file of Blackjack game:
//            contains deck class
//      
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
//#include "card.h"
//#include "deck.h"
#include "TermGame.h"
using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;

struct Node{
    Card *C;
    Node *Next;
    Node *Prev;

    /*Node(){
      C = *Card(0);
      Next = NULL;
      Prev = NULL;
    }*/

    Node(Card *c) {
        C = c;
        Next = NULL;
        Prev = NULL;
    }
};

class Deck {
private:
    Node *Top;

public:
/**
 * Deck
 * Purpose:
 *     constructs the object
 * Params:
 *     void
 * Returns:
 *     void
 */
Deck() {
    Top = NULL;
}

/**
 * LoadDeck
 * Purpose:
 *     fills the list with shuffled cards
 * Params:
 *     none
 * Returns:
 *     void
 */
void LoadDeck() {
    srand (time(NULL));
  for(int i = 0; i < 52; i++){
      Card *C = new Card(rand() % 52 + 0);
    // allocate new memory
    Node *anode = new Node(C);        // Allocate new memory

    // check if list is empty
    if (!Top) {
        Top = anode;                  // If empty stack just point to new node
    } else {
        anode->Next = Top;            // Link new node by point its next to old top
        Top = anode;                  // Now update top to point to the new node
    }
  }
}

/**
 * Pop
 * Purpose:
 *     Removes an item from top of stack
 * Params:
 *     void
 * Returns:
 *     Card* : top Card
 */
Card* Pop() { //gonna need a constructor in opponent and player that uses this
    if (!Top) {
        return NULL;        // Return NULL for empty stack
    } else {
        Node *Temp = Top;   // Point to top with temp pointer

        Card *c = Top->C; // Pull Card out of top (to return)

        Top = Top->Next;    // Move top of stack 

        delete Temp;        // Delete old top node

        return c;           // Return our Card
    }
}


/**
 * Print
 * Purpose:
 *     Print for debugging purposes
 * Params:
 *     void
 * Returns:
 *     void
 */
void Print() {
    Node *Temp = Top;

    while (Temp != NULL) {
        Temp->C->PrintCard();
        Temp = Temp->Next; 
    }
}
};