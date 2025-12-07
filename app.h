#ifndef APP_H  
#define APP_H
#include <iostream>
using namespace std;

void menu();

void menuAdmin(); 
void signUpAdmin();
addressAdmin loginAdmin();
void homeAdmin(addressAdmin adminLogin);

void menuUser();
void signUpUser();
addressUser loginUser();
void homeUser(addressUser userLogin);

void musicPlayer(addressPlaylist P, int modeSort);




#endif