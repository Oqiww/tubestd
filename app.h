#ifndef APP_H  
#define APP_H
#include "backend.h"
#include <iostream>
using namespace std;

void clearScreen();

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
void musicPlayerGlobal(addressLagu startSong);
void menuDetailPlaylist(addressUser U, addressPlaylist P);





#endif