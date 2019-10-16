/**
 * Homework 04
 * 
 * List based queue 
 * 
 * Author: Paige Champagne
 * Date: Oct 14th 2019
 */
#include <iostream>
#include <fstream>
#include "ListQueue.hpp"

using namespace std;


int main() {
  ifstream fin("animals.txt");  // input file of animal info
  ListQueue LQ;                 // Queue instance 
  Animal *A;
  while(!fin.eof()){
    A = new Animal();
      fin >> A->name >> A->weight >> A->scary;  // load animal with file data
     LQ.Push(A);  
  }
 


  LQ.Print();                     // print queue to see where values are

  LQ.Pop();

  LQ.Print();

}