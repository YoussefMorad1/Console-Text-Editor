#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>
#include "header.h"
using namespace std;

fstream file;
string str_of_recovery;
char filename[100];
char new_file_name[100];

// Loading file Function and Getting recovery of it
void load_file(){
    cout << "Please enter the txt-file name you want to deal with:\n";

    // taking the File name from user
    cin >> filename;

    // adding the .txt extension
    strcat(filename, ".txt");

    // trying to open the file in read-only mode (so I can check if it exists) (File-mode can be changed later)
    file.open(filename);


    if(file.fail()){ // checking if a file doesn't exist
        cout << "This is a new file. I created it for you :)\n";

        // creating a file with the name user entered if the file didn't exist (it opens in write mode)
        file.open(filename, ios::out);

        // the recovery string will be empty as it's new file
        str_of_recovery = "";
    }
    else{
        cout << "This File Already Exists\n";

        // holding a copy of the old file in a string, so if we want to recover it or not to overwrite it
        make_recovery_string();
    }

    // closing file temporally, so it's opened in the desired mode for every option
    file.close();
}

void make_recovery_string(){

    string temp_line;
    bool first_line = true;
    while(!file.eof()){
        getline(file, temp_line);
        if(first_line) {
            str_of_recovery += temp_line;
            first_line = false;
        }
        else {
            str_of_recovery += '\n';
            str_of_recovery += temp_line;
        }
    }

}


//_______________________________________________
//_______________________________________________


// Additional functions used repeatedly

string tolower(string str){
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

//_____________________________
string toupper(string str){
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
    return str;
}

//_____________________________
string totitle(string str){
    // taking the string we want to make title as input stream and call it line
    istringstream line(str);

    string temp_word;
    string new_str;
    while(line >> temp_word){ // get word from the line in temp_word

        // make first char Upper and others Lower
        temp_word[0] = toupper(temp_word[0]);
        for(int i = 1; i < temp_word.length(); i++)
            temp_word[i] = tolower(temp_word[i]);

        // add the titled word to new string followed by space
        new_str += temp_word;
        new_str += ' ';
    }

    // return new line that is every word 1st char Upper
    return new_str;
}

//_____________________________
void str_to_file(string str){
    file.close();
    file.open(filename, ios::out);
    file << str;
    file.close();
}


//_______________________________________________
//_______________________________________________


// The Menu Functions
void append(){
    string write;

    file.open(filename,ios::out | ios::app);//file opened //open file for writing
    cout<<"write what you want to add it to the file"<<endl;
    getline(cin,write,'\0');


    if (cin.eof()){
        cin.clear();
        file << write;
        cout<<"\n"<<"Your text has been added to the file successfully"<< endl ;
        file.close();
    }

}


//_____________________________
void display(){
    file.open(filename);//file opened
    string word;
    while(getline(file,word,'\0')){
        file>>word;
        cout<<word;
    }
    cout<<endl;
    file.close();
}
//_____________________________
void empty(){
    file.open(filename,ios::out);
    file.close();
    cout<<"Done"<<endl;
    file.close();
}

//_____________________________
//function to encrypt and decrypt file words
void encrypt_decrypt(int sign){
    string word,write;
    //read from file
    file.open(filename);
    while(getline(file,word,'\0')){

        for(int i=0;i<word.length();i++) {
            if(word[i]==10){
                continue;
            }
            word[i] = word[i] + sign;
        }
        file>>word;

    }
    cout<<endl;
    file.close();

    //write the encrypt and decrypt into file
    file.open(filename,ios::out);
    file<<word;
    file.close();

}

//_____________________________
void merge(){
    fstream file2;
    char filename2[100];
    bool exist = false;
    while (exist == false) {
        cout << "Please enter the txt-file name you want to merge with:\n";
        // taking the File name from user
        cin >> filename2;

        // adding the .txt extension
        strcat(filename2, ".txt");

        // trying to open the file in read-only mode (so I can check if it exists)
        file2.open(filename2);

        if(file2.fail()){ // checking if a file doesn't exist
            cout << "Invalid File Name. Please try again.\n";
        }
        else{
            file.open(filename, ios::app);
            file << file2.rdbuf();
            cout << "Files merged successfully!\n";
            exist = true;
        }
    }
    file.close();
    file2.close();
}

//_____________________________
void count_words(){
    file.open(filename, ios::in);
    char ch;
    int state = 0;
    int word_counter = 0;
    cin.ignore();
    cin.sync();
    while (!file.eof()) {
        file.get(ch);
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            state = 0;
        }
        else if (state == 0) {
            state = 1;
            ++word_counter;
        }
    }
    cout << "Number of words in the file is: " << word_counter << endl;
    file.close();
}

//_____________________________
void count_chars(){
    file.open(filename, ios::in);
    string word;
    int char_counter = 0;
    cin.ignore();
    cin.sync();
    while (!file.eof()) {
        file >> word;
        char_counter += word.length();
    }
    cout << "Number of characters in the file is: " << char_counter << endl;
    file.close();
}

//_____________________________
void count_lines(){
    file.open(filename, ios::in);
    string line;
    int line_counter = 0;
    cin.ignore();
    cin.sync();
    while (!file.eof()) {
        getline(file, line);
        ++line_counter;
    }
    cout << "Number of lines in the file is: " << line_counter << endl;
    file.close();
}

//_____________________________
void search_word(){
    file.open(filename, ios::in);

    cout << "\nEnter the word to search if it exists in the file\n>>";

    // entering the word to search for it
    string word;
    bool exist = false;
    cin.ignore();
    cin.sync();
    getline(cin, word);

    string temp_word;

    while(!file.eof()){ //while didn't reach End Of File
        // putting every word in a string
        file >> temp_word;

        // checking if this word is the word we're looking for
        if(tolower(temp_word) == tolower(word)) {
            exist = true;
            break;
        }
    }
    if(exist == false) {
        cout << "Word was not found in the file!\n";
    }
    else {
        cout << "Word was found in the file!\n";
    }
    file.close();
}

//_____________________________
void word_freq(){
    file.open(filename, ios::in);

    cout << "\nEnter the word to count how many times it exists in the file\n>>";

    // entering the word to count its frequency
    string word;
    cin.ignore();
    cin.sync();
    getline(cin, word);

    string temp_word;
    long long word_counter = 0;

    while(!file.eof()){ //while didn't reach End Of File
        // putting every word in a string
        file >> temp_word;

        // increasing if this word is the word we're looking for
        if(tolower(temp_word) == tolower(word)) {
            word_counter++;
        }

    }

    cout << "The word (" << word << ") exists: " << word_counter << " Times\n";
}

//_____________________________
void make_upper(){
    //open file in read mode to get words from it
    file.open(filename);

    string line, str_of_effect;
    bool first_line = true;
    while(!file.eof()){
        // getting a line from the file and making it UPPER then saving it in a string (str_of_effect)
        getline(file, line);

        if(first_line){
            str_of_effect += toupper(line);
            first_line = false;
        }
        else {
            str_of_effect += '\n';
            str_of_effect += toupper(line);
        }
    }

    // saving the string in the file and closing it
    str_to_file(str_of_effect);
}

//_____________________________
void make_lower(){
    //open file in read mode to get words from it
    file.open(filename);

    string line, str_of_effect;
    bool first_line = true;
    while(!file.eof()){
        // getting a line from the file and making it UPPER then saving it in a string (str_of_effect)
        getline(file, line);

        if(first_line){
            str_of_effect += tolower(line);
            first_line = false;
        }
        else {
            str_of_effect += '\n';
            str_of_effect += tolower(line);
        }
    }

    // saving the string in the file and closing it
    str_to_file(str_of_effect);
}

//_____________________________
void make_title(){
    //open file in read mode to get words from it
    file.open(filename);

    string line, str_of_effect;
    bool first_line = true;
    while(!file.eof()){
        // getting a line from the file and making it UPPER then saving it in a string (str_of_effect)
        getline(file, line);

        if(first_line){
            str_of_effect += totitle(line);
            first_line = false;
        }
        else {
            str_of_effect += '\n';
            str_of_effect += totitle(line);
        }
    }

    // saving the string in the file and closing it
    str_to_file(str_of_effect);
}

//_____________________________
void save_recovery_file(){
    file.open(filename, ios::out);
    str_to_file(str_of_recovery);
    file.close();
}

void save_file_into_new(){
    file.open(filename);
    cout << "Please enter name to save your file with\n>>";

    cin >> new_file_name;

    fstream new_file;
    new_file.open(new_file_name, ios::out);

    string str_of_original_file, temp_line;
    bool first_line = true;

    while(!file.eof()){
        getline(file, temp_line);

        if(first_line) {
            str_of_original_file += temp_line;
            first_line = false;
        }
        else{
            str_of_original_file += '\n';
            str_of_original_file += temp_line;
        }
    }

    new_file << str_of_original_file;
    new_file.close();
}

void which_to_keep_editing(){
    cout << "Which file do you want to keep editing?\n"
            "1. Stay in the existing old file\n2. Move to the new saved file\n";

    string choice;
    cin >> choice;
    while(choice != "1" && choice != "2"){
        cout << "Please choose a valid option!\n>>";
        cin >> choice;
    }

    if(choice == "2"){
        for(int i = 0; i < 100; ++i) {
            filename[i] = new_file_name[i];
        }
    }

}

void main_save(){
    cout << "\n1. Save the file's content again in the same file\n"
            "2. Save the file's content under a different file name\n>>";

    string choice;
    cin >> choice;
    while(choice != "1" && choice != "2"){
        cout << "Please choose a valid option!\n>>";
        cin >> choice;
    }

    if(choice == "1"){
        file.close();
    }
    else if(choice == "2"){
        save_file_into_new();
        save_recovery_file();
        which_to_keep_editing();
    }
}
