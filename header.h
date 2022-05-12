#ifndef TEXTEDITOR_HEADER_H
#define TEXTEDITOR_HEADER_H
#include <string>

// Loading file Function
void load_file();
void make_recovery_string();

// Additional functions used repeatedly
std::string tolower(std::string str);
std::string toupper(std::string str);
std::string totitle(std::string str);
void str_to_file(std::string str);

// The Menu Functions
void append();

void display();

void empty();

void encrypt_decrypt(int sign);

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
void which_to_keep_editing();
#endif //TEXTEDITOR_HEADER_H