///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Assignment:       Program_05
// Date:             10 December 2019
// Description:
//       blackjack.cpp: Main file of blackjack game
//        This program uses TermGame.h to create a visual game of  blackjack with the classes:
//      Card, Deck, Player, Opponent
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "card.h"
#include "deck.h"
#include "opponent.h"
#include "player.h"
#include "TermGame.h"
using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;

int main(){
  bool fold = 0;
  Deck h;
  h.LoadDeck();
  Hand a;
  Opponent e;
//draw initial cards
 a.Insert(h.Pop());
 a.Insert(h.Pop());
 e.Insertop(h.Pop());
 e.Insertop(h.Pop());
 e.PrintBack();
 a.Print();

 
  while(!fold){
    cout << "Press [D] to draw card, [S] to select, and [A] to change the value of an ace, and [F] to fold.\n";
    char i = TermGame::getch();
    switch(i){
      case 'd':
      a.Insert(h.Pop());
       a.Print();
       break;
      case'f':
        fold = 1;
        break;
      case 's':
        a.Select();
        break;
      case 'a':
        a.ChangeA();
        a.Print();
        break;
    }
    e.drawop(h);
    e.PrintBack();
  if(e.opScore() > 21){ //if opponent score goes over 21
    fold = true;
    cout <<"You win!\n";
    e.Printop();
  }else if(a.Score() > 21){ //if player score goes over 21
    fold = true;
    cout <<"You lose!\n";
    e.Printop();
    a.Print();
  }
  }
  if(21 - e.opScore() < 21 - a.Score()){ //if op score is closer to 21
    cout <<"You lose!\n";
    e.Printop();
    a.Print();
  }else if(21 - e.opScore() > 21 - a.Score()){ //if your score is closer to 21
    cout <<"You win!\n";
    e.Printop();
    a.Print();
  }


return 0;
}