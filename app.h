#ifndef APP_H  
#define APP_H

#include "backend.h"
#include <vector>
#include <thread> // Untuk sleep
#include <chrono> // Untuk waktu

// Fungsi Utama
void menu();
void clearScreen(); // Helper membersihkan layar

// ADMIN
void menuAdmin(); 
void signUpAdmin();
addressAdmin loginAdmin();
void homeAdmin(addressAdmin adminLogin);

// USER
void menuUser();
void signUpUser();
addressUser loginUser();
void homeUser(addressUser userLogin);
void menuDetailPlaylist(addressUser U, addressPlaylist P);

// MUSIC PLAYER
void musicPlayer(addressPlaylist P, int modeSort);

#endif