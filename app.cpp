#include "app.h"
#include "backend.h"
#include <vector>
vector<Admin> dataAdmin;
vector<User> dataUser;

ListLagu masterLagu;

void menu(){
    createListLagu(masterLagu);
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
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            menuAdmin();
            break;
        case 2:
            menuUser();
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
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;
        
        switch (pilihan)
        {
        case 1:
            signUpAdmin();
            break;
        case 2: {
            int indexAdmin = loginAdmin();
            if (indexAdmin != -1 && indexAdmin != -2){
                homeAdmin();
            }
            break;
        }
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

int loginAdmin(){
    string username, password;

    if (dataAdmin.empty()){
        cout << "Belum ada akun yang terbuat" << endl;
        return -2;
    }

    cout << "Masukkan username: ";
    cin >> username;

    cout << "Masukkan password anda: ";
    cin >> password;

    for (int i = 0; i < dataAdmin.size(); i++){
        if (dataAdmin[i].username == username && dataAdmin[i].password == password){
            cout << "Halo " << dataAdmin[i].username << "!" << endl;
            return i;
        }
    }
    cout << "Username / password salah!" << endl;
    return -1;
};  

void homeAdmin(){
    ListLagu L;
    addressLagu P;
    string x;

    while(true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        cout << "1. Tambah lagu" << endl;
        cout << "2. Edit lagu" << endl;
        cout << "3. Hapus Lagu" << endl;
        cout << "4. Lihat semua lagu" << endl;
        cout << "5. Kembali" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3/4/5): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1: {
            Lagu L;
            cout << "ID Lagu: ";
            cin >> L.id;
            cout << "Judul: ";
            cin >> L.judul;
            cout << "Penyanyi: ";
            cin >> L.penyanyi;
            cout << "Durasi (ex: 03:20): ";
            cin >> L.durasi;
            cout << "Genre: ";
            cin >> L.genre;

            insertLastLagu(masterLagu, createElmLagu(L));
            cout << "Lagu berhasil ditambahkan!\n";
            break;
        }
        case 2:
            editLagu();
        case 3:
            cout << "Masukan judul lagu yang ingin dihapus: ";
            cin >> x;
            deleteLagu(L, P, x);
             break;
        case 4:
            showAllLagu(masterLagu);
            break;
        case 5:
            return;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
};

void editLagu(){
while (true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        cout << "Ingin edit bagian apa?" << endl;
        cout << "1. ID" << endl;
        cout << "2. Judul" << endl;
        cout << "3. Penyanyi" << endl;
        cout << "4. Album" << endl;
        cout << "5. Genre" << endl;
        cout << "6. Durasi" << endl;
        cout << "7. Back to menu" << endl;
        cout << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            
            break;
        case 2: 

             break;
        case 3:
            
             break;
        case 4:

            break;
        case 5:
            
             break;
        case 6:
            
             break;
        case 7:
            return;
        default:
            cout << "Inputan anda salah, ulangi lagi!" << endl;
            break;
        }
    }

}


void menuUser(){
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
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            signUpUser();
            break;
        case 2: {
            int indexUser = loginUser();
            if (indexUser != -1 && indexUser != -2){
                homeUser();
            }
            break;
        }
        case 3:
            return;
        default:
            cout << "Inputan anda salah, ulangi lagi!" << endl;
            break;
        }
    }
}

void signUpUser(){
    string username, password;
    User newUser;

    while (true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|    User Sign Up    |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        bool cek = true;

        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        // Cek username sudah ada
        for (int i = 0; i < dataUser.size(); i++){
            if (dataUser[i].username == username){
                cek = false;
                break;
            }
        }

        if (cek){
            newUser.username = username;
            newUser.password = password;
            dataUser.push_back(newUser);
            cout << "Akun user berhasil dibuat!" << endl;
            break;
        } else {
            cout << "Username sudah digunakan, coba lagi!" << endl;
        }
    }
}

int loginUser(){
    string username, password;

    if (dataUser.empty()){
        cout << "Belum ada akun user yang dibuat" << endl;
        return -2;
    }

    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    for (int i = 0; i < dataUser.size(); i++){
        if (dataUser[i].username == username && dataUser[i].password == password){
            cout << "Halo " << dataUser[i].username << "!" << endl;
            return i;
        }
    }

    cout << "Username / password salah!" << endl;
    return -1;
}

void homeUser(){
    while(true){
        cout << "+--------------------+" << endl;
        cout << "|                    |" << endl;
        cout << "|       Spitipi      |" << endl;
        cout << "|                    |" << endl;
        cout << "+--------------------+" << endl;
        cout << endl;

        showAllLagu(masterLagu);
        cout << "1. Mencari lagu" << endl;
        cout << "2. Back to menu" << endl;
        cout << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1: {
            
            break;
        }
        case 2:
            return;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
};
