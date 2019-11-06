/*
*       This program contains:
*   
*   Struct Book: title, author, genre, series, owned
*
*   Ordered list: push, pop(+search for each variable. start with genre), print, order title
*
*
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("tbr.txt");

struct book{
    string title;
    string author;
    string genre;
    bool series;
    bool owned;

   /* book(){
        title = " ";
        author = " ";
        genre = " ";
        series = 0;
        owned = 0;
    }*/

    book(){
        fin >> title >> author >> genre >> series >> owned;
    }
};

struct Node{
    book *b;
    Node* Next;

    Node(book *B){
        b = B;
        Next = NULL;
    }
};

class liststack{
private:
    Node* Head = NULL;

public:

void push(book* B){ //for now i will push these in order of title
   Node * poop = new Node(B);
   Node*  temp = Head;
   Node* behind = temp;   
   Node*  ahh;
   cout << "0" <<endl;
    if (!Head){
        Head = poop;
        cout << "fuck" <<endl;
    }else {
    while(temp->Next != NULL){
        if(temp->Next->b->owned > poop->b->owned){
         cout << temp->b->title <<endl;
         behind = temp;
        poop->Next = temp->Next;
        behind->Next = poop;
        cout << "1" <<endl;
        } else if(temp->Next->b->owned < poop->b->owned){
            ahh = temp->Next;
            temp->Next = poop;
            poop->Next = ahh;
            cout << temp->b->title <<endl;
             cout << poop->b->title <<endl;
             cout << ahh->b->title <<endl;
            cout << "2" <<endl;
        } 
        temp = temp->Next;
        cout << "3" <<endl;
    }

    }

}

book* pop(string a){ //have main cin a genre and return these
   Node* Temp = Head;
   Node* it = Temp;
   Node* behind = Temp;
   book* hold;

    if(Head){
    while(Temp->Next->b->genre != a){
        behind = Temp;
        Temp = Temp->Next;
     }
    } else{
        return NULL;
    }

    if (Temp->b->genre == a){
            it = Temp;
            Temp = Temp->Next;
            behind->Next = Temp;
            hold = it->b;
            delete it;
            return hold;
        }
}

void print(){
    Node* Temp = Head;

    while(Temp != NULL){
        cout << Temp->b->title << " " << Temp->b->author << " " << Temp->b->genre
             << " " << Temp->b->series << " " << Temp->b->owned <<endl;
        Temp = Temp->Next;
    }
}

};



int main(){
    //ifstream fin("tbr.txt");
    liststack shit;
   // book* abc = new book;

while(!fin.eof()){
   book* abc = new book;
    
    shit.push(abc);
};
   // cout << abc->title << " " << abc->author << " " << abc->genre << " "
     //   << abc->series << " " << abc->owned; 
    shit.print();     
return 0;
}