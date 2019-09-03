/* Paige Champagne
**Homework 1
**Data strutures and ADT
**Fall 2019
**9/2/19
*/

#include <iostream>
#include <string>   
#include <fstream> 
#include <iomanip>

#define SIZE 10 //contant size

using namespace std;

struct Student //struct for student
{
    string fname;
    string lname;
    int numGrades; //number of grades. VERY IMPORTANT
    int grades[10];
};
/**
 * Function: loadClassList
 * Description:
 *      Reads a file with student data, and loads it into an array of Students.
 * 
 * Params:
 *      Student *classlist  : array of Students
 *      string  filename    : name of file to process
 * 
 * Returns:
 *      int - number of students read in. 
 */
int loadClassList(Student *classList, string fileName);

/**
 * Function: printClassList
 * 
 * Description:
 *      Prints an array of students to student_output.dat
 * 
 * Params:
 * 
 *      Student *classList : array of structs (and the structs are `Students`)
 *      int     classSize  : size of class (returned from `loadClassList` )
 * 
 * Returns:
 * 
 *      void
 */
void printClassList(Student *classList, int classSize);
//Paige Champagne
int main() //main function
{
  Student classList[100]; //array of students
    int classSize = 0;
    int i = 0;

    // Call the loadClassList function to open a file and load an array
    // of `Student` structs.
   classSize = loadClassList(classList, "input_data.txt");
  //prints class list to file
  printClassList(classList, classSize);

   return 0;
}
//Paige Champagne
int loadClassList(Student *classList, string fileName)
{
    ifstream fin;       // get a stream variable
    fin.open("input_data.txt");
    int i = 0;         
//while loop that will read in each name and num grade until end of file is reached
while(!fin.eof()) //reads in the first, last names
{
    fin >> classList[i].fname;

    fin >> classList[i].lname;

    fin >> classList[i].numGrades; //reads num grades so it can have the number of grades to expect
  //reads in each grade for each student
  for(int j =0; j< classList[i].numGrades; j++)
  {
    fin >> classList[i].grades[j];
  }
  
  i++; //increases variable to move to next spot in array
}
  fin.close(); //closes input file
  return i;
}
//Paige Champagne
void printClassList(Student *classList, int classSize)
{
  ofstream outfile; //opens file
  outfile.open ("student_output.dat");
  int num = 1;
  int i = 0;
  int padding = 0;
  outfile << "Paige Champagne\n"
          << "Homework 1\n"
          << "Data strutures and ADT\n"
          << "Fall 2019\n"
          << "9/2/19\n\n";

  //table formatting
  outfile << left << "Students\n";
  outfile << "=================================\n";
  //for loop prints each student's name to file
   for (int i = 0; i < classSize; i++)
   {
     int padding2 = 6;
        outfile << left << num << ". " << classList[i].fname << " " << classList[i].lname << right;
        outfile << right << setw(padding) <<":" << setw(padding2);

       //for loop prints out the grades each student has 
       for(int j =0; j< classList[i].numGrades; j++) 
      {
        outfile << right << classList[i].grades[j] << " ";
       }
       outfile << "\n" ;
      num++;
      padding = padding +4;
      if (i==2)
      padding = 5;
      else if (i == 1)
      padding = 6;
   }
 outfile.close(); //closes output file
 }
 //Paige Champagne