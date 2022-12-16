# Console-Text-Editor-App

Made by: [***Youssef Morad***](https://github.com/YoussefMorad1) -
[***Nour Wael***](https://github.com/nourelshaer) -
[***Nour Tarek***](https://github.com/NourTarek201) 


Requested by: *Dr. Mohammed El-Ramly* in Structured Programming course (Assingment 4)

## Program Overview 

* **This is a simple Text Editor app written in C++**

* **The purpose of the project is to practice dealing with files in C++**

### Detailed Explanation 

1. The user enters the name of the file he wants to deal with

2. The program will test if such a file exists or not. 
   1. If it does, it will display a message: "This File Already
   Exists" and it will open it for read and write.
   2. If it does not exist, it will create a file with the given name and will 
   print a message: "This is a new file. I created it for you"

3. After that the **Following Menu** will be displayed. 
The user chooses an option to apply and after executing it, the
program re-displays the menu till Exit is chosen.

![image](https://user-images.githubusercontent.com/102534922/167369493-3444aff2-cf5b-4f56-b2db-6ba8093dda05.png "list_of_options")

## Options Explanation

| **The Option**                                              | **Option Explanation**                                                                                                                                                                                                                           |
|-------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **1- Adding Content**                                       | _Functionality will open the file for writing in append mode (which means that the original content of the file is not lost) <br/> And will allow the user to type in text that is stored in the file, until he presses EOF character (Ctrl+z)._ |
| **2- Display content**                                      | *Functionality displays the current file content to the user in Console.*                                                                                                                                                                        |
| **3- Empty the file**                                       | _Clears the file and erases its content and returns to the main menu._                                                                                                                                                                           |
| **4- Encrypt the file content**                             | _Re-write the file content but shifted one ASCII character, i.e., each character will be replaced by the character following it in the ASCII table._                                                                                             |
| **5- Decrypting the file content**                          | _The opposite of the previous option, i.e., it is re-writing (decrypting) the original content from the encrypted file._                                                                                                                         |
| **6- Merge another file**                                   | _Functionality will take from the user the name of another file. If this file does not exist, it will display a message “Invalid File Name”. If the file exists, the program will add the given file to the end of the current file_             |
| **7- Count the number of words**                            | _Functionality prints the number of words in the file. A word is any sequence of characters not separated by white spaces (space, tab, new line, etc.)_                                                                                          |
| **8- Count the number of characters**                       | _Functionality prints the number of characters in the file._                                                                                                                                                                                     |
| **9- Count the number of lines**                           | Functionality prints the number of lines in the file. | 
| **10- Search for a word in the file**                      | _Functionality will take a word from the user and print either: “Word was not found in the file” or “Word was found in the file" The search is case insensitive. So, the word “Ali”, “ali” and “aLI” are the same._                              |
| **11- Count the number of times a word exists in the file** | _takes from the user a word and prints the number of times the word exists in the file as a separate word_                                                                                                                                       |
| **12- Turn the content to upper case**                      | _Functionality will re-write the file all in upper case_               |                                                                                  
| **13- Turn the content to lower case**                      | _Functionality will re-write the file all in lower case_                    |
| **14- Turn file content to first caps**                     | _Functionality will re-write the file all in lower case and except the first letter of each word will be capital_ |
| **15- Save**                                                | _Allows saving the file content again in the same file or under a different name._                                                                                                                                                               |
| **16- Exit**                                                | _Terminates the program_                                                                                                                                                                                                                         |


