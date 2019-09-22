//Paige Champagne
//Take home test 1
//Data Structures Fall 2019

/******************************7******************************/

int sumArrays(int a[], int b[], int c[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += a[i] + b[i] + c[i];
    }
    return sum;
}

/******************************2******************************/

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

/******************************3******************************/

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

/******************************4******************************/

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

/******************************5******************************/

Stats(){
    sum = 0;
    min = 0;
    max = 0;
    avg = 0.0; 
   } 


/******************************6******************************/

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


/******************************7******************************/

int initIntArray(int size){
   int *array = new int(size);

    for (int i = 0; i < num; i++){
        array[i] = 0;
    } 
    return *array;
}