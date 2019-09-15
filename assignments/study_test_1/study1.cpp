#include <iostream>
#include <string>   
#include <fstream> 
#include <cstdlib>

using namespace std; 

struct Stats{
  int min = 0;
  int max = 0;
  double avg = 0;
};

void fillarray (int a[]);
//int sum (int a[]);
void printarraystats (int a[], Stats b);
void calculate (int a[], Stats b);



int main(){
  int array[10];
Stats array1;
 array1.min = 0;
 array1.max = 0;
 array1.avg = 0;
    fillarray(array);

    //calculate(array, array1);

    void printarraystats (int a[], Stats b);

    return 0;
}

void fillarray(int a[])
{

    for (int i = 0; i < 10; i++)
    {
        a[i] = (rand() % 100);
    }
}

void calculate (int a[], Stats b)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (b.min > a[i])
            b.min = a[i];
        else if (b.max < a[i])
            b.max = a[i];
    
    sum += a[i];
    count++;
    }
    
    b.avg = sum/count;
}


void printarraystats(int a[], Stats b)
{
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "Min: " << b.min << "\n";
    cout << "Max: " << b.max << "\n";
    cout << "Avg: " << b.avg << "\n";
}