//Paige Champagne

/**1)**

- Write a function that receives 3, 1D arrays.
- They are all the same size.
- It sums up the values in all arrays and returns that value.
- Call your function `sumArrays`*/

int sumArrays(int a[], int b[], int c[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += a[i] + b[i] + c[i];
    }
    return sum;
}

/**2)**

- Write a function that will average integer values in a 2D array.
- Assume the 2D array has the same width and height.
- Name your function `avg2D`
- Remember averaging integers does not always result in an integer.*/

int avg2D(int a[][], int size){
    int sum, count = 0;
    double avg = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            sum += a[i][j];
            count++;
        }
    }
    avg = sum/count;
    return avg;
}

/**3)**

Write a function that would print out the following pattern:

| Parameter of 4 | Parameter of 6                   |
| :------------- | :------------------------------- |
| x              | x                                |
| xx             | xx                               |
| xxxx           | xxxx                             |
| xxxxxxxx  //8  | xxxxxxxx                         |
|                | xxxxxxxxxxxxxxxx                 |
|                | xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | */

void pattern(){
    int param = 6;
    int interval = 1;
    int i = 0;
    for (int i = 0; i < param; i++)
    {
        if (i > 0)
        {
            interval = interval * 2;
            for(int j = 0; j < interval; j++)
            {
                cout << "X";
            }
        }
         else if(i == 0) 
        {
             cout << "X";
        }
        cout <<endl;
    }
}

/**4)**

```c++
struct Stats{
   int min;
   int max;
   double avg;
   int sum;  
};
```

- Write a function that calculates all the values in the Stats struct when given an array of integers.
- Return your values in an instance of the struct.  
- Name your function `aggregateVals`*/

Stats aggregatevals(double a[], int size){ 
    Stats x;
    int sum = 0;
    x.min = a[0];
    x.max = a[0];
    x.avg = 0.0; 

    for( int i = 0; i < 10; i++){
        sum += a[i];
        if (a[i] < x.min){
            x.min = a[i];
        }
        if (a[i] > x.max){
            x.max = a[i];
        }
    }
    x.avg = (double)sum/size;
    return x;
}

/**5)**

- Write a constructor for the `Stats` struct to initialize its data members with correct values. 
- Pay attention to data types.*/

Stats(){
    sum = 0;
    min = 0;
    max = 0;
    avg = 0.0; 
   } 


/**6)** 

- Write a function that computes the standard deviation for a 1D array of integers.
- Call your function `calcStdDev`.
- Standard Deviation:
    1. Work out the Mean (the simple average of the numbers)
    2. Then for each number: subtract the Mean and square the result
    3. Then work out the mean of those squared differences.
    4. Take the square root of that and we are done!*/

    float calcStdDev(int a[], int size){
    float sum = 0.0;
    float mean = 0.0;
    float sub[s];
    float sumsq = 0.0;
    float stddev = 0.0;

    for(int i = 0; i < size; i++){
        sum += a[i];
    }
    mean = sum/s;
    for (int i = 0; i < size; i++){
        sub[i] = (a[i] - mean) * (a[i] - mean);
    }

    for(int i = 0; i < size; i++){
        sumsq += sub[i];
        
    }
    stddev = sqrt(sumsq/size);
    return stddev;
}


/**7)**

- Write a function that will dynamically allocated memory of a given size for an integer array.
- Then it will return that new array initialized with zeros.
- Call it `initIntArray`*/

int initIntArray(int size){
   int *array = new int(size);

    for (int i = 0; i < num; i++){
        array[i] = 0;
    } 
    return *array;
}