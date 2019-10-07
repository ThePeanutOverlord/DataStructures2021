/**
 * File: main.cpp
 * Aurhor: Paige Champagne
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/5/19
 * Description:
 *    Main driver of an Array based implementation of a stack.
 */

#include <iostream>
#include <fstream> 

using namespace std;


struct Stack{

    int *A;         // container of items (could make it a list)
    int Top;        // keep track of top
    int Size;       // Arrays need a size
  
/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
Stack(){
  Size = 10;
  A = new int [Size];
  Top = -1;
}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
Stack(int s){
  Size = s;
  A = new int [Size];
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
bool Push(int val){
  if(!Full()){
    Top++;
    A[Top] = val;
    return true;
  }else{
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
int Pop(){
  if(!Empty()){
    int temp = 0;   
    temp = A[Top];
    Top--;
    return temp;
  }else{
    // should return a value that implies failuer, but good enough for now
    cout<<"Cannot remove item from empty stack"<<endl;
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
void Print(){
  for(int i = Top;i>=0 ; i--){
    cout<<A[i]<<endl;
  }
   //cout << "Top:" << Top <<endl;
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
bool Empty(){
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
bool Full(){
  return (Top == Size - 1);
}

int checkResize(int s, int t){

if ((float)t/s >= 0.8){
  cout << "  1" <<endl;
    return 1;
}
else if ((float)t/s <= 0.2){
  cout << "  2" <<endl;
    return 2;
}
else{
  cout << "  hjdk" <<endl;
    return 0;
}
}

Stack Enlarge(int &s, int t){
   s = s*1.5;
   int *b = new int [s];

   for(int i = 0; i < t; i++){
       b[i] = A[i];
   }
   cout << s <<endl;
    delete A;
    return *b;
}

Stack Reduce(int s, int t){
 s = s*0.5;
   int *b = new int [s];

   for(int i = 0; i < t; i++){
       b[i] = A[i];
   }
  cout << s <<endl;
    delete A;
    return *b;
}
};


/**
 * Main Program
 * 
 */
int main() {
ifstream fin;       // get a stream variable
fin.open("input_data.txt");
char op;
int data;
int size = 10;

  Stack S1(size); // Instance of our stack default constructor

while (!fin.eof()){
    fin >> op;
    fin >> data;
    switch(op){
    case '+':
      S1.Push(data);
      break;
    case '-':
      S1.Pop();
      break;
    }
  S1.Print();
 // S1.checkResize(Stack)
    switch(S1.checkResize(S1.Size, S1.Top)){
      case 1:
       S1 = S1.Enlarge(S1.Size, S1.Top);
        break;
      case 2:
       S1 = S1.Reduce(S1.Size, S1.Top);
        break;
    }
  //cout << size <<endl;
}
  
  return 0;
}