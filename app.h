#ifndef APP_H  
#define APP_H
#include <iostream>
using namespace std;

// Membuat struct untuk role User
struct User {
    string username;
    string password;
};

typedef struct elmUser *addressUser;
struct elmUser
{
    User info;
    addressUser next;

};

struct ListUser
{
    addressUser first;
};


typedef struct elmAdmin *addressAdmin;
// Membuat struct untuk role Admin
struct Admin {
    string username;
    string password;
};

struct elmAdmin{
    Admin info;
    addressAdmin next;
};

struct ListAdmin{
    addressAdmin first;  
};

void menu();

// Menu untuk admin
void createListAdmin(ListAdmin &L);
addressAdmin createElmAdmin(Admin data);
void insertLastAdmin(ListAdmin &L, addressAdmin P);
addressAdmin searchAdmin(ListAdmin L, string username);
void menuAdmin(); 
void signUpAdmin();
addressAdmin loginAdmin();
void homeAdmin(addressAdmin adminLogin);
void editLagu();


// Menu untuk user
void createListUser(ListUser &L);
addressUser createElmUser(User data);
void insertLastUser(ListUser &L, addressUser P);
addressUser searchUser(ListUser L, string username);
void menuUser();
void signUpUser();
addressUser loginUser();
void homeUser(addressUser userLogin);


#endif