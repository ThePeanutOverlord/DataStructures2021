#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//struct of nodes for the list

struct empdata
{
    string emp_id;
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    empdata *Next;

    empdata()
    {
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }
    empdata(string id, string first, string last, string sex, string mail, double pay)
    {
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

bool substringMatch(string macro, string micro)
{
    return (macro.find(micro) != std::string::npos);
};

class LinkedList
{
    empdata *Head; //creates node called Head that will point to the first node
    empdata *Tail;

public:
    LinkedList()
    {
        Head = NULL; //sets Head to null bc it's not pointing to anything
        Tail = NULL;
    }

    void push(string id, string first, string last, string sex, string mail, double pay)
    {

        empdata *Temp = new empdata(id, first, last, sex, mail, pay); //creates new node called Temp

        if (Head == NULL)
        {                //if Head isn't pointing to anything
            Head = Temp; //assigns temp to be the first node
        }
        else
        {                      //if Head is pointing to something,
            Temp->Next = Head; //makes Temp's next value equal Head?? does it make Head null??
            Head = Temp;       //Head equals temp
        }
    };

    void pop(string id, string first, string last, string sex, string mail, double pay)
    {
        empdata *Temp = Head; //creates new node called Temp
        Head = Temp->Next;
        delete Temp;
    };

    void del(string id)
    {
        empdata *Temp = Head; //creates new node called Temp
        empdata *del;
        string macro, micro;
        cout << "Enter the ID of the employee you wish to delete: ";
        cin >> micro;
        do
        {
            if (substringMatch(macro, micro) == 1)
            {
                del = Temp->Next;
                macro = del->emp_id;
                Temp = Temp->Next;
                delete del;
                cout << "Deleted\n";
            }
            else
            {
                del = Temp->Next;
                macro = del->emp_id;
                Temp = Temp->Next->Next;
            };

        } while (Temp->Next != NULL);

        if (substringMatch(macro, micro) == 0)
        {
            cout << "Not found.\n";
        }
            
    };

    void printid(string id /*,string first,string last,string sex,string mail, double pay*/)
    {
        ofstream fout;
        fout.open("output.dat",std::ios::app);
        empdata *Temp = Head;

        for (int i = 0; i < 30; i++)
        {
            fout << Temp->emp_id << "\n";
            if (Temp->Next)
            {
                Temp = Temp->Next;
            };
        };
              fout.close();
    };
     bool find(string email){
            ofstream fout;
            fout.open("output.dat",std::ios::app);
           
            empdata *Temp = Head;
            empdata *Result = Head;
            bool found = false;
            string macro, micro;
            cout << "Which email address are you looking for? ";
            cin >> micro;

            do
            {

                macro = Temp->email;
                Result = Temp;
                Temp = Temp->Next;
                if (macro.find(micro) != std::string::npos)
                {
                    found = true;
                    fout << found << "\n";
                }
            } while (Temp->Next != NULL);
            return found;   
        };
    
};

    int main()
    {
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

        bool menu = 1;

        while (!fin.eof())
        {

            fin >> empid >> first >> last >> email >> gender >> pay;

            //cout<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

            EmpList.push(empid, first, last, email, gender, pay);
        };

        while (menu == true)
        {
           
            int choice;
            cout << "\nMenu of Operations:\n";
            cout << "    1 - Find Employee\n";
            cout << "    2 - Delete Employee\n";
            cout << "    3 - Push Employee\n";
            cout << "    4 - Pop Employee\n";
            cout << "    5 - Print Employee IDs\n";
            cout << "    6 - Quit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                EmpList.find(email);
                break;
            case 2:
                EmpList.del(empid);
                break;
            case 3:
                EmpList.push(empid, first, last, email, gender, pay);
                cout << "Done\n";
                break;
            case 4:
                EmpList.pop(empid, first, last, email, gender, pay);
                cout << "Done\n";
                break;
            case 5:
                EmpList.printid(empid);
                break;
            case 6:
                cout << "Goodbye\n";
                menu = 0;
                break;
            }
        };
        
        return 0;
    }