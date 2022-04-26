#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>

using namespace std;

void load_file();
void counting_words();

string tolower(string str);

fstream file;

int main(){
    load_file();
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

string tolower(string str){
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

void counting_words(){
    int ct = 0;
    while(!file.eof()){
        string s;
        file >> s;
        ct++;
    }
    cout << ct - 1;
}


