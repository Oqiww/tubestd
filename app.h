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

// Untuk menyimpan data admin
extern vector <Admin> dataAdmin;

// Untuk menyimpan data user
extern vector<User> dataUser;

void menu();

// Menu untuk admin
void menuAdmin(); 
void signUpAdmin();
int loginAdmin();
void homeAdmin();

// Menu untuk user
void menuUser();
void signUpUser();
int loginUser();


#endif