/* Paige Champagne
**Program 1
**Data strutures and ADT
**Fall 2019
**9/17/19
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/**
 * Struct: empdata
 * Description:
 *      struct of employee data read from file to be used in class
 *      Linkedlist
 * 
 * Params:
 *      none
 * 
 * Constructors:
 *   empdata() : initializes variables
 *     
 *   empdata(string id, string first, string last,
 *       string sex, string mail, double pay) :
 *      initializes variables in the nodes
 *
 */
struct empdata
{
    string emp_id;
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    empdata *Next;   //creates node Next which will be used 
//to connect Head and Temp nodes
//contstructor that initializes each of the variables in the struct,
// passes in nothing and returns nothing 
    empdata()
    {
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
        Next = NULL;
    }//Paige Champagne

//constructor within empdata that makes them parts of 
//the nodes of empdata in the linkedList
    empdata(string id, string first, string last, 
            string sex, string mail, double pay)
    {
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};
//Paige Champagne

/**
 * Function: substringMatch
 * Description:
 *      determines if a string entered by the user is contained within a string
 *      in the data set
 * 
 * Params:
 *      string macro : string from data
 *      string micro : string user entered
 * 
 * Returns:
 *      bool - t if micro is substring of macro, f if not
 */
bool substringMatch(string macro, string micro)
{
    return (macro.find(micro) != std::string::npos);
}
/**
 * Class: LinkedList
 * Description:
 *      forms a linked list of the struct empdata
 * 
 * Variables:
 *      empdata *Head (private)  : first node in list 
 * 
 * Constructors:
 *LinkedList  :  initilizes Head to equal NULL
 *void push   :  pushes the node down to make room for a new one
 *void pop    :  deletes a node from the front of the list
 *void del    :  deleteas a node selected by the user from the list
 *void printid:  prints the first 30 employee ids from the list to the outfile
 *bool find   :  searches the list for results to the user's search and prints
 *               a 1 for every instance to the outfile as well as returns a bool
 *               t or f if it is present
 */
class LinkedList
{
    empdata *Head; //creates node called Head that will point to the first node
//Paige Champagne
public:
    LinkedList()
    {
        Head = NULL; //sets Head to null bc it's not pointing to anything
    }
/**
 * Constructor: void push
 * Description:
 *      pushes the node down to make room for a new one
 * 
 * Params:
 *  string id, string first, string last, string sex, string mail, double pay:
 *      the parts of the empdata struct that make up each node in the list
 * 
 * Returns:
 *      nothing--void
 */
    void push(string id, string first, string last, 
                string sex, string mail, double pay)
    {
        //creates new node called Temp
        empdata *Temp = new empdata(id, first, last, sex, mail, pay); 

        if (Head == NULL)
        {                //if Head isn't pointing to anything
            Head = Temp; //assigns temp to be the first node
        }
        else
        {                      //if Head is pointing to something,
            Temp->Next = Head; //make it = to Temp->Next
            Head = Temp;       //Head equals temp
        }
    }
/**
 * Constructor: void pop
 * Description:
 *      deletes a node from the front of the list
 * 
 * Params:
 *  string id, string first, string last, string sex, string mail, double pay:
 *      the parts of the empdata struct that make up each node in the list
 * 
 * Returns:
 *      nothing--void
 */
    void pop(string id, string first, string last, 
             string sex, string mail, double pay)
    {
       if(Head != NULL){
           empdata *Temp = Head; //creates new node called Temp
        Head = Temp->Next; //Makes the next node the new first
        delete Temp; //self-explanatory
       } else if(Head == NULL){
           cout << "Head is empty. Fill the array\n";
       }
        
    } //Paige Champagne
/**
 * Constructor: void del
 * Description:
 *      deleteas a node selected by the user from the list
 * 
 * Params:
 *      string id   :   only variable to work with for now
 * 
 * Returns:
 *      nothing--void
 */
    void del(string id)
    {
        empdata *Temp = Head; //creates new node called Temp
        empdata *del; //creates node to be deleted
        empdata *hold = Temp->Next;
        string macro, micro;
        cout << "Enter the ID of the employee you wish to delete: ";
        cin >> micro; //user choice

            while(Temp->Next->Next != NULL){//until the end of the list is reached
           
            if (substringMatch(macro, micro) == 1) //checks if they match
            {
                del = Temp->Next; //moves along in the list
                hold = Temp;
                Temp = Temp->Next->Next;
                macro = del->emp_id;
              if(del == NULL){
                   cout << "Not found\n";
               }else{
                delete del;
                cout << "Deleted\n";                   
               }
            }
            else
            {
                del = Temp->Next; //moves along in the list
                hold = Temp;
                Temp = Temp->Next->Next;
                macro = del->emp_id;
            }
        }   
} //Paige Champagne
/**
 * Constructor: void printid
 * Description:
 *      prints the first 30 employee ids from the list to the outfile
 * 
 * Params:
 *      string id:only variable to work with for now/needed to print ids
 * 
 * Returns:
 *      nothing--void
 */
    void printid(string id)
    {
        ofstream fout;      //open file
        fout.open("output.dat",std::ios::app); //makes it start @ end
        empdata *Temp = Head; //establish temporary node to work with

//runs 30 times, prints 1st 30 consecutive ids from the list
        for (int i = 0; i < 30; i++) 
        {
            fout << Temp->emp_id << "\n";
            if (Temp->Next)
            {
                Temp = Temp->Next;
            };
        };
              fout.close();
    } //Paige Champagne
/**
 * Constructor: bool find
 * Description:
 *      searches the list for results to the user's search and prints
 *      a 1 for every instance to the outfile as well as returns a bool
 *      t or f if it is present
 * 
 * Params:
 *    string email:only variable to work with for now. searches through emails
 * 
 * Returns:
 *      bool true or false if select data is found in list
 * 
 * Outputs to file: a 1 or 0 for every instance of search in data
 */
     bool find(string email){
            ofstream fout; //open file
            fout.open("output.dat",std::ios::app); //make it start at end
           
            empdata *Temp = Head; //makes temporary node to work with
            empdata *Result = Head; 
            bool found = false; //variable that holds result of search
            string macro, micro; //strings for sub string matching
            cout << "Which email address are you looking for? ";
            cin >> micro;

            while(Temp->Next != NULL)
            {

                macro = Temp->email; //gets data to check
                Result = Temp; //holds data
                Temp = Temp->Next; //moves on
                //connects to function substring find
                if (macro.find(micro) != std::string::npos) 
                {
                    found = true;
                    fout << found << "\n"; //outfile 1 if found
                }
            }
            return found;   //return if search was found or not
        };
    
}; //Paige Champagne

/**
 *Function: int main
 * Description:
 *     holds variables for linked list, struct. 
 *     Reads in data from input file and calls push to fill linked list.
 *     functions as menu for user to decide what actions to take with the data
 *
 * 
 */
    int main()
    {
        LinkedList EmpList; //list
        //empdata variables
        string empid;
        string first;
        string last;
        string email;
        string gender;
        double pay;

        ifstream fin("employees.dat"); //infile to read in data

        bool menu = 1; //menu control loop variable

        while (!fin.eof()) //while loop that reads data into list until 
        {                   //end of file is reached 
            fin >> empid >> first >> last >> email >> gender >> pay;

            EmpList.push(empid, first, last, email, gender, pay);
        };
        //menu that repeats until bool is set to 0 by choice 6
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
            switch (choice) //switch statement for menu
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
    } //Paige Champagne