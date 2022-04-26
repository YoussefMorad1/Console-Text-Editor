#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>

using namespace std;

void load_file();

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

void save();

fstream file;

int main() {
    cout << "Welcome User!\n";

    load_file();

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
            save();
        else if(option == "16")
            return 0;
    }
}

void load_file(){
    cout << "Please enter the txt-file name you want to deal with:\n";

    // taking the File name from user
    char filename[100];
    cin >> filename;

    // adding the .txt extension
    strcat(filename, ".txt");

    // trying to open the file in read-only mode (so I can check if it exists) (File-mode can be changed later)
    file.open(filename);

    if(file.fail()){ // checking if a file doesn't exist
        cout << "This is a new file. I created it for you :)\n";

        // creating a file with the name user entered if the file didn't exist (it opens in write mode)
        file.open(filename, ios::out);
    }
    else{
        cout << "This File Already Exists\n";
    }

}

void append(){}

void display(){}

void empty(){}

void encrypt(){}

void decrypt(){}

void merge(){}

void count_words(){}

void count_chars(){}

void count_lines(){}

void search_word(){}

void word_freq(){}

void make_upper(){}

void make_lower(){}

void make_title(){}

void save(){}
