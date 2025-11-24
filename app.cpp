#include "app.h"

void menu(){
    bool ulang = true;
    while (ulang){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        // Pilihan menu
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << endl;

        // Pilih menu
        int pilihan;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            menuAdmin();
            break;
        case 2:
            //fungsi
            break;
        case 3:
            cout << "Terimakasih telah memakai aplikasi kami" << endl;
            ulang = false;
            break;
        default:
            cout << "Inputan anda salah ulangi lagi!" << endl;
            break;
        }
    }
};

void menuAdmin(){
    bool ulang = true;
    while (true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        cout << "1. Sign up" << endl;
        cout << "2. Login" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        
        switch (pilihan)
        {
        case 1:
            //fungsi
            break;
        case 2:
            //fungsi
            break;
        default:
            cout << "Inputan anda salah ulangi lagi!" << endl;
            break;
        }
    }
};

void signUpAdmin(){
    string nama;
    int umur;
    cout << "ini ros";
    cout << "Ini syauqi";
    cout << "Ini Nada" ;
};
