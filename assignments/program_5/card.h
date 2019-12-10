///////////////////////////////////////////////////////////////////////////////
//
// Author:           Paige Champagne
// Assignment:       Program_05
// Date:             10 December 2019
// Description:
//       card.h file of Blackjack game:
//            contains card class
//      
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "TermGame.h"
using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;

class Card{
private:
  int ival;      // card value 0 - 52
  int fval;      // face value 1 - 13
 


  string format;
  //PrintableCard pcard;

public:
 string sval;   // string card value 
  string suit;   // heart, club, etc.
  int c;        //color
  /**
 * card
 * Purpose:
 *     constructs the object
 * Params:
 *     void
 * Returns:
 *     void
 */
  Card(){
    ival = 0;
    fval = 1;
    suit = "♥";
    sval = "A";
    c = 2;
  }

    string HEART = "♥";
    string SPADE = "♠";
    string CLUB = "♣";
    string DIAMOND = "♦";
    /**
 * card
 * Purpose:
 *     constructs the object with an integer value
 * Params:
 *     int i
 * Returns:
 *     void
 */
  Card(int i){
    ival = i;
    fval = i % 13; 
    suit = Symbol();
    sval = StringValue();
    //pcard.EditCard(suit, sval);
  if (suit == HEART || suit == DIAMOND){
     c = 2;
  }else if(suit == CLUB|| suit == SPADE){
     c = 1;
  }
    format = Format();
  }
/**
 * symbol
 * Purpose:
 *     determines the suit of the card
 * Params:
 *     void
 * Returns:
 *     string suit
 */
  string Symbol(){
    string HEART = "♥";
    string SPADE = "♠";
    string CLUB = "♣";
    string DIAMOND = "♦";
    int suit = ival / 13;
    switch(suit){
      case 0: return HEART;
      case 1: return SPADE;
      case 2: return CLUB;
      case 3: return DIAMOND;
    }
    return "";
  }
/**
 * stringvalue
 * Purpose:
 *     determines face value
 * Params:
 *     void
 * Returns:
 *     string fval
 */
  string StringValue(){
    switch(fval+1){
      case 1: return "A"; 
      case 2: return "2";
      case 3: return "3";
      case 4: return "4";
      case 5: return "5";
      case 6: return "6";
      case 7: return "7";
      case 8: return "8";
      case 9: return "9";
      case 10: return "10";
      case 11: return "J";
      case 12: return "Q";
      case 13: return "K";
    }

    return "?";
  }
/**
 * facevalue
 * Purpose:
 *     get fval
 * Params:
 *     void
 * Returns:
 *     int fval
 */
  int FaceValue(){
    return fval;
  }
/**
 * printvalue
 * Purpose:
 *     combines sval and suit
 * Params:
 *     void
 * Returns:
 *     string
 */
  string PrintValue(){
    return sval+":"+suit;
  }
/**
 * printcard
 * Purpose:
 *     prints card
 * Params:
 *     void
 * Returns:
 *     void
 */
  void PrintCard(){
    TermPrint::print(format, c, 8, false);
  }
/**
 * format
 * Purpose:
 *     formats card
 * Params:
 *     none
 * Returns:
 *     string
 */
  string Format(){
    format = "";
    format += c;
    format += "┌────┐\n";
    format +=c;
    format += "│";
     if(sval != "10"){
      format +=" ";
    }
    format += sval;
    format += suit;
   
    format += " │\n";
    format+=c;
    format += "│  ";
    format += "  │\n";
    format +=c;
    format += "└────┘\n";
    return format;
  }
};