#include "app.h"
#include <vector>
vector<Admin> dataAdmin;

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
    while (true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        cout << "1. Sign up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Back to menu" << endl;
        cout << endl;

        int pilihan;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        
        switch (pilihan)
        {
        case 1:
            signUpAdmin();
            break;
        case 2:
            //fungsi
            break;
        case 3:
            return;
        default:
            cout << "Inputan anda salah ulangi lagi!" << endl;
            break;
        }
    }
};

void signUpAdmin(){
    string username, password;
    Admin roleadmin;
    while (true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        bool cek = true;
        cout << "Masukkan username anda: ";
        cin >> username;

        cout << "Masukkan password anda: ";
        cin >> password;

        roleadmin.username = username;
        roleadmin.password = password;
        if (dataAdmin.size() == 0){
            dataAdmin.push_back(roleadmin);
            cout << "Akun berhasil dibuat!" << endl;
            break;
        } else {
            for (int i = 0; i < dataAdmin.size(); i++){
                if (username == dataAdmin[i].username){
                    cek = false;
                    break;
                }
            }
            if (cek){
                dataAdmin.push_back(roleadmin);
                cout << "Akun berhasil dibuat!" << endl;
                break;
            } else {
                cout << "Maaf username sudah terpakai silahkan coba yang lain!" << endl;
            }
        }
    }
};
