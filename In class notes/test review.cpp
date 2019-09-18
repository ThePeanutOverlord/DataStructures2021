#include <iostream>

using namespace std;

//recieves 2 id arrays, sums values in both and returns it. Call function sumArrays

/*int sumArrays(int a[], int *b, int size) //data type is important bc the prgm needs it to determine what to overload
 {      int sum = 0;
 
    for(int i = 0; i<size; i++) {
        sum += a[size];
        sum+= b[size];
    }
        cout << sum << endl;                      //remember * (or pointers) are the same thing as arrays basically
    return sum;
 }       */                        
//bool function finds a key in a 2d array and returns a 1 if present, 0 if not
/*bool findkey(int a[10][10], int size, int key){
    bool exists = false;
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            if( a[i][j]==key){
                return true; //but having this here and putting return at the bottom is wasteful so 
                
            }
        }
    }
    return false;
}*/
//write function that finds min max and avg of given array and returns calculated values in struct
/*struct Stats1{ //constructor doesn't initialize variables
  int min;
  int max;   
  double avg;
};

Stats aggregatevals(double a[], int size){ 
    Stats s;
    int sum = 0;
    s.min = a[0];//remember you can just set min to the first value in the array //but also INT_MAX/INT_MIN are the max/min
    s.max = a[0];
    s.avg = 0.0; //since avg is double it would be better to put .0

    for( int i = 0; i< size; i++){
        if (a[i] < s.min){
            s.min = a[i];
        }
        if (a[i] > s.max){
            s.max = a[i];
        }
        sum += a[i];
    }
    s.avg = (double)sum/size; //be aware of doubles and make sure if you're dividing to use the right stuff
}*/

struct Stats2{ //write constructor of the same name to initialize variables
  int min;
  int max;   
  double avg;

  Stats2(){
    min = INT_MAX;
    max = INT_MIN; 
    avg = 0.0;
  }
};

//function that makes a new array of given size
int* intIntArray(int size){
    int * a = new int(size); //new operator allocates memory to global data so this wouldn't be a local variable
    return a;
}

void intIntArray2(int size, int *&a){
    a = new int[size];
}



int main()
{
int array1[] = {0, 0, 2, 0, 0, 2, 0, 0};
int array2[] = {0, 3, 0, 0, 0, 0, 3, 0};
int num = 0;
//int sum = sumArrays(array1, array2, 8);

//cout << "Sum of arrays: " << sum;
//cout << findkey();
//ask user to enter a number and then create an array that's the size of that number
cout << "Enter a number \n";
cin >> num;
int *array3 = new int(num); //creates and initializes array

}