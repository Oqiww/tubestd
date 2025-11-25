#ifndef APP_H  
#define APP_H
#include <vector>
#include <iostream>
using namespace std;

// Membuat struct untuk role User
struct User {
    string username;
    string password;
};
// Membuat struct untuk role Admin
struct Admin {
    string username;
    string password;
};

extern vector <Admin> dataAdmin;

void menu();
void menuAdmin(); 
void signUpAdmin();


#endif