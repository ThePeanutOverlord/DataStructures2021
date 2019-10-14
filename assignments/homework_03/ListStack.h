/**
 * ListStack.h
 * 
 * List stack definition file. This stack hold animal types. The definition
 * and implementation for Animal is here too.
 * 
 * Author: Paige Champagne
 * Date: Oct 14th 2019
 */
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Animal Type
 */
struct Animal {
    string name;
    double weight;
    double scary;

    // Default constructor
    Animal() {
        name = "";
        weight = 0.0;
        scary = 99.0;
    }
    /**
    *second constructor
    *pulls values from file and initilizes them in the Animal in the List
    *
    *params are the animal's name, weight, and scary score
    */
    Animal(string a, double b, double c){
      ifstream fin("animals.txt");  // input file of animal info
      fin >> name >> weight >> scary;  // load animal with file data
    }

};

// Overload "<<" operator for animals
ostream &operator<<(ostream &, const Animal *);

/**
 * Node type.
 * 
 * We seperate Animal from Node so we can return an "Animal"
 * when we pop the stack, and don't have to return a "node"
 */
struct Node {
    Animal *A;
    Node *Next;

    // Needs a default constructor

    Node(Animal *a) {
        A = a;
        Next = NULL;
    }
};

/**
 * ListStack
 * 
 * List based stack implementation
 * 
 */
class ListStack {
private:
    Node *Top;

public:
    ListStack();          // constructor
    void Push(Animal *);  // stack gets Animals
    Animal *Pop();        // Pop returns top animal
    void Print();         // print stack for debugging
};