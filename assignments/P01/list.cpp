#include <iostream>
#include <string>   
#include <fstream> 


using namespace std;

//struct of nodes for the list

struct empdata{
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    empdata *Next;

    empdata(){
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }
    empdata(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

/*struct Node{
    empdata data;
    Node* Next = NULL; //creates pointer Next
    Node(empdata a){

        data = a;
        Next = NULL;
    }
}; */

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
    empdata* Head; //creates node called Head that will point to the first node
    empdata* Tail;
public:
    LinkedList(){
        Head = NULL; //sets Head to null bc it's not pointing to anything
        Tail = NULL;
    }
  
  void push(string id,string first,string last,string sex,string mail, double pay){
        
        empdata* Temp = new empdata(id, first, last, sex, mail, pay); //creates new node called Temp

        if(Head == NULL){ //if Head isn't pointing to anything
            Head = Temp; //assigns temp to be the first node
        }else{              //if Head is pointing to something,
            Temp->Next = Head; //makes Temp's next value equal Head?? does it make Head null??
            Head = Temp; //Head equals temp
        }
  };

void pop(string id,string first,string last,string sex,string mail, double pay){
   empdata* Temp = Head;//creates new node called Temp
   Head = Temp->Next;
   delete Temp;
  // cout <<Head->emp_id<<", "<<Head->first_name<<", "<<Head->last_name<<", "
//       <<Head->email<<", "<<Head->gender<<", "<<Head->hourly_pay<<endl;

};
void del(string id){
   empdata* Temp = Head;//creates new node called Temp
   empdata* del;
    string macro, micro;
    cout << "Enter the ID of the employee you wish to delete: ";
    cin >> micro;
  do{
   Head = Temp; 
   cout << Head->emp_id << "\n";
     del = Temp->Next;
     cout << del->emp_id << "\n";
    Temp = Temp->Next->Next;
    cout << Temp->emp_id << "\n";
    macro = del->emp_id;
    if(Temp->Next=NULL){
        cout << "Employee not found\n";
    }
  }while(!macro.find(micro) != std::string::npos);
    cout << "Out of loop\n";
    delete del;
   
};
   



empdata find(string email){
   empdata* Temp = Head;
   empdata* Result = Head;
    string macro, micro;
    cout << "Which email address are you looking for? ";
    cin >> micro;
    
    do{
        
        macro = Temp->email;
        Result = Temp;
        Temp = Temp->Next;
         if (Temp->Next=NULL){
             cout << "Not found\n";
         }
         
    }while(!macro.find(micro) != std::string::npos);
    return *Result;
};

/*bool find(string email){
    empdata* Temp = Head;
   bool result= 0;
    string macro, micro;
    cout << "Which email address are you looking for? ";
    cin >> micro;
    
    do{
        
        macro = Temp->email;
        Temp = Temp->Next;
        if (macro.find(micro) != std::string::npos){
             cout << "Found!\n";
            result = 1;
         }
   }while(Temp->Next!=NULL);

   return result;
   
};*/


 void printid(string id /*,string first,string last,string sex,string mail, double pay*/){
      empdata* Temp = Head;

        for(int i = 0; i < 30; i++){
            cout<<Temp->emp_id<<"\n";
            if(Temp->Next){
             Temp = Temp-> Next;
            };
        };
            
     };
};



int main(){
 
 LinkedList EmpList;

    string empid;
    string first;
    string last;
    string email;
    string gender;
    double pay;

    string line;
    string *tokens;
    ifstream fin("employees.dat");


    while(!fin.eof()){

        fin>>empid>>first>>last>>email>>gender>>pay;

       //cout<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

        EmpList.push(empid,first,last,email,gender,pay);
    };
   //cout << EmpList.find(email).email;
   //EmpList.pop(empid,first,last,email,gender,pay);
    //EmpList.printid(empid);
    EmpList.del(empid);

return 0;
};
