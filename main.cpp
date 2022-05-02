#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
using namespace std;
int choice;
void display();
void append();
void encrypt_decrypt(int sign);
void empty();
void menu(){
    cout<<"Hello user :)\nPlease choose from the following:\n1)Add text to file\n2)Display file content\n3)Empty the file\n4)Encrypt file content\n5)Decrypt file content\n0)Exit"<<endl;
    cin>>choice;
    cin.ignore();
}
char fileName[50];
ifstream file;
ofstream myfile;
int main() {

    cout<<"Please enter the file name "<<endl;
    cin.getline(fileName,50);
    menu();
    while (true) {
        switch (choice) {
            case 0:
                return false;
            case 1:
                append();
                menu();
                continue;
            case 2:
                display();
                menu();
                continue;
            case 3:
                empty();
                menu();
                continue;
            case 4:
                encrypt_decrypt(1);
                menu();
                continue;
            case 5:
                encrypt_decrypt(-1);
                menu();
                continue;
            default:
                cout << "Enter a correct choice..try again" << endl;
                menu();
                continue;

        }
    }

}

//------------------------------------------------------------------------

//function to add words to file
//myfile
void append(){
    string write;

    myfile.open(fileName,ios::out | ios::app);//file opened //open file for writing
    cout<<"write what you want to add it to the file"<<endl;
    getline(cin,write,'\0');
    while (true){

       if (cin.eof()){
           cin.clear();
           break;
       }
       else{
            myfile << write;
            cout<<"\n"<<"Your text has been added to the file successfully"<< endl ;
            break;
        }
    }
    }

//-----------------------------------------------------------------------------------

//function to display file words
//file
void display(){
    file.open(fileName);//file opened
    char word[50];
    file>>word;
    cout<<word<<" ";
    while(file.good()){

        file>>word;
        cout<<word<<" ";
    }
    cout<<endl;
}

//----------------------------------------------------------------------

//function to encrypt file words
void encrypt_decrypt(int sign){

    //begin encrypt
    file.open(fileName);//file opened
    string word;
    char sp;
    file>>word; //get first value from doc
    while(file.good()){

        for(int i=0;i<word.length();i++) {
            word[i] = word[i] + sign;
            sp=32+sign;
        }
        cout<<word<<sp;
        file>>word;

    }
    for(int i=0;i<word.length();i++) {
        word[i] = word[i] + sign;}
    cout<<word;
    cout<<endl;
    }

//------------------------------------------------------------------------------

void empty(){
    myfile.open(fileName,ios::out);
    myfile.close();
    cout<<"Done"<<endl;








}