#include <iostream>
#include <string>   
#include <fstream> 


using namespace std;

//struct of nodes for the list

struct empdata{
    string emp_id, first_name, last_name, gender, email;
    double hourly_pay;
};

struct Node{
    empdata data;
    Node* Next = NULL; //creates pointer Next
};

void menu(){
    int choice;
        cout<<"\nMenu of Operations:\n";
        cout<<"    1 - Find Employee\n";
        cout<<"    2 - Delete Employee\n";
        cout<<"    3 - Quit\n";
        cin >> choice;
    switch(choice)
    {
        case 1: void find(string micro, empdata a);
            break;
       // case 2: void delete();
            break;
        case 3:
            break;
    }
}

class LinkedList{
    Node* Head; //creates node called Head that will point to the first node

public:
    LinkedList(){
        Head = NULL; //sets Head to null bc it's not pointing to anything
    }
  
  void push(){
        Node* Temp = new Node(); //creates new node called Temp

        if(Head == NULL){ //if Head isn't pointing to anything
            Head = Temp; //assigns temp to be the first node
        }else{              //if Head is pointing to something,
            Temp->Next = Head; //makes Temp's next value equal Head?? does it make Head null??
            Head = Temp; //Head equals temp
        }
  }

void pop(empdata x){
}

void find(string micro, empdata a){
   
    ifstream fin;       // get a stream variable
    fin.open("employees.dat");
    string macro;

    while(!fin.eof())
    {
        fin >> macro;
        if (macro.find(micro) != std::string::npos)
            fin >> a.emp_id >> a.first_name >> a.last_name >> a.gender >> a.email;
    }
   
}

 void print(){
        Node* Temp = Head;
        ofstream outfile;
        outfile.open("outfile.txt");
        while(Temp != NULL){ //while temp isn't the end
            outfile << Temp->data; //print value of temp
            if(Temp->Next){ //if next isn't the end
                outfile <<"->"; //print arrow
            }
            Temp = Temp->Next;
        }
    };
};



int main(){
    string search;
    empdata employee;


    void menu();
    void print();


}
