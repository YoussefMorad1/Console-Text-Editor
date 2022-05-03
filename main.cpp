#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

// Loading file Function
void load_file();
void make_recovery_string();

// Additional functions used repeatedly
string tolower(string str);
string toupper(string str);
string totitle(string str);
void str_to_file(string str);

// The Menu Functions
void append();

void display();

void empty();

void encrypt();

void decrypt();

void merge();

void count_words();

void count_chars();

void count_lines();

void search_word();

void word_freq();

void make_upper();

void make_lower();

void make_title();

void main_save();
void save_recovery_file();
void save_file_into_new();

fstream file;
string str_of_recovery;
char filename[100];

int main() {
    cout << "Welcome User!\n";

    load_file();

    cout << '\n';
    while(true){
        cout << "1. Add new text to the end of the file\n"
                "2. Display the content of the file\n"
                "3. Empty the file\n"
                "4. Encrypt the file content\n"
                "5. Decrypt the file content\n"
                "6. Merge another file\n"
                "7. Count the number of words in the file.\n"
                "8. Count the number of characters in the file\n"
                "9. Count the number of lines in the file\n"
                "10. Search for a word in the file\n"
                "11. Count the number of times a word exists in the file\n"
                "12. Turn the file content to upper case.\n"
                "13. Turn the file content to lower case.\n"
                "14. Turn file content to 1st caps (1st char of each word is capital)\n"
                "15. Save\n"
                "16. Exit\n>>";

        string option;
        cin >> option;

        regex valid_option("([1-9]|[1-9][0-6])");
        while(!regex_match(option, valid_option)){
            cout << "Please enter a valid option from the list\n>>";
            cin >> option;
        }

        if(option == "1")
            append();
        else if(option == "2")
            display();
        else if(option == "3")
            empty();
        else if(option == "4")
            encrypt();
        else if(option == "5")
            decrypt();
        else if(option == "6")
            merge();
        else if(option == "7")
            count_words();
        else if(option == "8")
            count_chars();
        else if(option == "9")
            count_lines();
        else if(option == "10")
            search_word();
        else if(option == "11")
            word_freq();
        else if(option == "12")
            make_upper();
        else if(option == "13")
            make_lower();
        else if(option == "14")
            make_title();
        else if(option == "15")
            main_save();
        else if(option == "16"){
            return 0;
        }

        cout << "\n_______________________________________________\n\n";
    }
}




// Loading file Function and Getting recovery of it
void load_file(){
    cout << "Please enter the txt-file name you want to deal with:\n";

    // taking the File name from user
    cin >> filename;

    // adding the .txt extension
    strcat(filename, ".txt");

    // trying to open the file in read-only mode (so I can check if it exists) (File-mode can be changed later)
    file.open(filename);

    // holding a copy of the old file in a string, so if we want to recover it or not to overwrite it
        make_recovery_string();

    if(file.fail()){ // checking if a file doesn't exist
        cout << "This is a new file. I created it for you :)\n";

        // creating a file with the name user entered if the file didn't exist (it opens in write mode)
        file.open(filename, ios::out);
    }
    else{
        cout << "This File Already Exists\n";
    }

    // closing file temporally, so it's opened in the desired mood for every option
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

void append(){}

//_____________________________
void display(){}

//_____________________________
void empty(){}

//_____________________________
void encrypt(){}

//_____________________________
void decrypt(){}

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
    string word;
    int word_counter = 0;
    cin.ignore();
    cin.sync();
    while (!file.eof()) {
        file >> word;
        ++word_counter;
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
    char word[100];
    int line_counter = 0;
    cin.ignore();
    cin.sync();
    while (!file.eof()) {
        ++line_counter;
        file.getline(word, 100); // use \n as a delimiter
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

    char new_file_name[100];
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

void main_save(){
    cout << "\n1. Save the file's content again in the same file\n2. Save the file's content under a different file name\n>>";

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
    }
}
