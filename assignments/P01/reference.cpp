#include <iostream>
#include <string>   
#include <fstream> 

using namespace std;

//struct of nodes for the list
struct nums{
    int num1, num2, num3;
};

struct Node{
    int Value;
    Node* Next; //creates pointer Next
    Node(nums x){
        Value = x;
        Next = NULL;
    }
};

//class containing 
class LinkedList{
private:
    Node* Head; //creats pointer Head

public:
    LinkedList(){
        Head = NULL; //sets first value to null
    }


    void push(nums x){
        Node* Temp = new Node(x); //creates new node

        if(Head == NULL){ //
            Head = Temp;
        }else{
            Temp->Next = Head;
            Head = Temp;
        }
        
    }

    


    void print(nums x){
        Node* Temp = Head;

        while(Temp != NULL){ //while temp isn't the end
            cout<<Temp->Value; //print value of temp
            if(Temp->Next){ //if next isn't the end
                cout<<"->"; //print arrow
            }
            Temp = Temp->Next;
        }
    }
};

int main(){
    Node* A = new Node(8);
    Node* B = new Node(5);
    Node* C = new Node(7);
    Node* D = new Node(33);

    A->Next = B;
    B->Next = C;
    C->Next = D;

    Node* Temp = A;

    while(Temp != NULL){
        cout<<Temp->Value<<endl;
        Temp = Temp->Next;
    }

    LinkedList test;

    for(int i=0;i<8;i++){
        test.push(i);
    }

    for(int i=0;i<8;i++){
    }
    L.print();


    return 0;
}