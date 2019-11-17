#include <iostream>

using namespace std;

char shiftLetter(char letter, int shift){
    int intVal=0;

    intVal = (int)letter - 65;  // Turn it into an integer number between 0-25
    intVal += shift % 26;       // Shift the letter, using mod to wrap back around
    letter = intVal + 65;       // Turn integer back into an ascii upper case letter
    
    return letter;
}

class CaesarCipher{
    private:

    public:
    string Encrypt(string); // encrypts a string given a specific shift value
    string Decrypt(string); // decrypts a string given a specific shift value
    string UpperCase(string); // a method that uppercases a string ( there are built in methods, but we will write our own)
    void SetShift(); // sets the shift amount for your class (default should be 13)
    string ReadCipherText(); // reads an encrypted file into a string
    void WriteCipherText(); // writes an encrypted message to a file
    string ReadPlainText(); // reads a plain text file into a string
    void WritePlainText(); // writes a plain text string to a file
};

int main(int argc , char** argv){
    cout<<shiftLetter('A',13)<<endl;
}