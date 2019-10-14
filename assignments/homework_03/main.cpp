/**
 * Homework 3
 * 
 * List based Stack that holds an animal type
 * 
 * Author: Paige Champagne
 * Date: Oct 14th 2019
 */
#include "ListStack.h"    // include our stack definition
#include <fstream>        
#include <iostream>

using namespace std;

int main() {
    ifstream fin("animals.txt");  // input file of animal info                   
    Animal *a = new Animal();     // animal pointer used to hold popped animals
    ListStack LS;                 // List based stack object

        a = new Animal(a->name, a->weight, a->scary); //initializes it with a new constructor that reads in the data from the file      
        LS.Push(a);                               // push animal onto the stack
    
    LS.Print();             // Print the stack
}