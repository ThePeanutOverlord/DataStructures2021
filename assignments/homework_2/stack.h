/**
 * File: stack.h
 * Aurhor: Paige Champagne
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/5/19
 * Description:
 *    Definition of our stack class.
 */

class Stack{
  private:
    int *A;         // container of items (could make it a list)
    int Top;        // keep track of top
    int Size;       // Arrays need a size
  public:
    
    Stack();        // Default constructor
    
    Stack(int size);     // overloaded constructor
    bool Push(int a); // Push value onto stack
    int Pop();      // Remove item from top of stack
    void Print();   // Help inspect values
    bool Empty();   // Is stack empty
    bool Full();    // is stack full
    int checkResize(int *a, int size, int t);
    int Enlarge(int *a, int s, int t);
    int Reduce(int *a, int s, int t);

};