#ifndef APP_H  
#define APP_H
#include "backend.h"
#include <iostream>
using namespace std;

void menu();
void clearScreen(); // Helper membersihkan layar

void menuAdmin(); 
void signUpAdmin();
addressAdmin loginAdmin();
void homeAdmin(addressAdmin adminLogin);

void menuUser();
void signUpUser();
addressUser loginUser();
void homeUser(addressUser userLogin);
void menuDetailPlaylist(addressUser U, addressPlaylist P);

void musicPlayer(addressPlaylist P, int modeSort);




#endif