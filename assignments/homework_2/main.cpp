/**
 * File: main.cpp
 * Aurhor: Paige Champagne
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/5/19
 * Description:
 *    Created checkResize, Enlarge, and Reduce methods for the 
 *    base code of a array based stack.
 */

#include <iostream>
#include <fstream>

using namespace std;

struct Stack
{

  int *A;   // container of items (could make it a list)
  int Top;  // keep track of top
  int Size; // Arrays need a size

  /**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
  Stack()
  {
    Size = 10;
    A = new int[Size];
    Top = -1;
  }

  /**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
  Stack(int s)
  {
    Size = s;
    A = new int[Size];
    Top = -1;
  }

  /**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
  bool Push(int val)
  {
    if (!Full())
    {
      Top++;
      A[Top] = val;
      return true;
    }
    else
    {
      return false;
    }
  }

  /**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
  int Pop()
  {
    if (!Empty())
    {
      int temp = 0;
      temp = A[Top];
      Top--;
      return temp;
    }
    else
    {
      // should return a value that implies failure, but good enough for now
      cout << "Cannot remove item from empty stack" << endl;
    }
    return 0;
  }

  /**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    void
 * Returns:
 *     void
 */
  void Print(int biggest)
  {
    ofstream outfile; //opens file
    outfile.open ("output.dat");

    outfile << "Paige Champagne\n";
    outfile << "10/5/19\n";
    outfile << "Homework 2\n";
    outfile << "Output file\n\n";

    outfile << "\nFinal size: " << Size << endl;
    outfile << "Biggest size: " << biggest << endl;
    outfile << "Values: ";
    for (int i = Top; i >= 0; i--)
    {
      outfile << A[i] << " ";
    }
    
  }

  /**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
  bool Empty()
  {
    return Top < 0;
  }

  /**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
  bool Full()
  {
    return (Top == Size - 1);
  }

 /**
 * checkResize
 * Description:
 *    determines if stack array needs to grow or shrink
 * Params:
 *    int s (size)
 *    int t (top)
 * Returns:
 *    int sentinal:
 *    1 = enlarge
 *    2 = shrink
 *    0 = none
 */
  int checkResize(int s, int t)
  {
    if ((t + 1) / (float)s >= 0.8)
    {
      return 1;
    }
    else if ((t + 1) / (float)s <= 0.2)
    {
      return 2;
    }
    else
    {
      return 0;
    }
  }

 /**
 * Enlarge
 * Description:
 *    make 1.5x bigger array, copy old, delete old
 * Params:
 *    int s (size)
 *    int t (top)
 * Returns:
 *    none
 */
  void Enlarge(int s, int t)
  {
    Size = s * 1.5;
    int *b = new int[Size];

    for (int i = 0; i <= t; i++)
    {
      b[i] = A[i];
    }

    delete[] A;
    A = b;
  }

 /**
 * Reduce
 * Description:
 *    make .5x smaller array, copy old, delete old
 * Params:
 *    int s (size)
 *    int t (top)
 * Returns:
 *    none
 */
  void Reduce(int s, int t)
  {
    Size = s * 0.5;
    int *b = new int[Size];

    for (int i = 0; i <= t; i++)
    {
      b[i] = A[i];
    }
    delete[] A;
    A = b;
  }
};

/**
 * Main Program
 * 
 */
int main()
{
  ifstream fin; // get a stream variable
  fin.open("input_data.txt");
  char op; //holds operation read in
  int data; //holds int read in
  int size = 10; 
  int biggestSize = 10; //keeps track of biggest size

  Stack S1(size); // Instance of our stack default constructor

  while (!fin.eof()) //cycles through file
  {
    fin >> op;
    fin >> data;
    //decides which operation to carry out based on op
    switch (op)
    {
    case '+':
      S1.Push(data);
      break;
    case '-':
      S1.Pop();
      break;
    }

    //checks each term if it should resize or not
    switch (S1.checkResize(S1.Size, S1.Top))
    {
    case 1:
      S1.Enlarge(S1.Size, S1.Top + 1);
      break;
    case 2:
      S1.Reduce(S1.Size, S1.Top + 1);
      break;
    }
    //updates biggestSize
    if (S1.Size > biggestSize)
    {
      biggestSize = S1.Size;
    }
  } //end of while loop

  //prints final things to outfile
  S1.Print(biggestSize);

  return 0;
}