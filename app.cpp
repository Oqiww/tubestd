#include "app.h"
#include "backend.h"

// Variabel Global
ListAdmin dataAdmin;
ListUser dataUser;
ListLagu masterLagu;
ListPlaylist masterPlaylist;


void menu(){
    createListLagu(masterLagu);
    createListPlaylist(masterPlaylist);
    createListAdmin(dataAdmin);
    createListUser(dataUser);

    //data dummy


    bool ulang = true;
    while (ulang){
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
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
        //perbaiki tampilan
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
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
            addressAdmin adm = loginAdmin();
            if (adm) homeAdmin(adm);
            }
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
    Admin data;
    while (true){
        //perbaiki tampilan
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
        cout << endl;


        bool cek = true;
        cout << "Masukkan username anda: ";
        cin >> username;

        if (searchAdmin(dataAdmin, username)) {
            cout << "Username ada!\n";
        }else{
            cout << "Password: "; 
            cin >> password;
            data.username = username;
            data.password = password;
            insertLastAdmin(dataAdmin, createElmAdmin(data));
            cout << "Akun Admin berhasil dibuat!" << endl;
            break;
        }
    }     
};

addressAdmin loginAdmin(){
    string username, password;

    if (dataAdmin.first == nullptr){
        cout << "Belum ada akun Admin yang terdaftar.\n";
        return nullptr;
    }

    // tampilan perbaiki
    cout << "\n--- Login Admin ---" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    addressAdmin P = searchAdmin(dataAdmin, username);
    
    if (P != nullptr && P->info.password == password) {
        cout << "Halo " << P->info.username << "!" << endl;
        return P;
    } else {
        cout << "Username atau Password salah!" << endl;
        return nullptr;
    }
};  

void homeAdmin(addressAdmin adminLogin){
    string cariJudul;
    while(true){
        // perbaiki tampilan
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
        cout << "\n--- Dashboard Admin (" << adminLogin->info.username << ") ---" << endl;
        cout << endl;

        cout << "1. Tambah lagu" << endl;
        cout << "2. Edit lagu" << endl;
        cout << "3. Hapus Lagu" << endl;
        cout << "4. Lihat semua lagu" << endl;
        cout << "5. Kembali" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3/4/5): ";
        cin >> pilihan;

        switch (pilihan){
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
            L.durasiDetik = 5;
            cout << "Genre: ";
            cin >> L.genre;

            insertLastLagu(masterLagu, createElmLagu(L));
            cout << "Lagu berhasil ditambahkan!" << endl;
            break;
        }
        case 2:
            cout << "Masukan judul lagu yang mau diedit: ";
            cin >> cariJudul;
            addressLagu P = searchLaguJudul(masterLagu, cariJudul);
            
            if (P){
                cout << "--- Data Baru ---\n";
                string judulBaru, penyanyiBaru, durasaiBaru, genreBaru;
                cout << "Judul Baru: ";
                cin >> judulBaru;
                cout << "Penyanyi Baru: "; 
                cin >> penyanyiBaru;
                cout << "Durasi Baru: "; 
                cin >> durasaiBaru;
                cout << "Genre Baru: "; 
                cin >> genreBaru;
                editLaguGlobal(masterLagu, judulBaru, penyanyiBaru, durasaiBaru, genreBaru, P);
                break;
            } else {
                cout << "Lagu tidak ditemukan!" << endl;
            }
            break;
        case 3:
            cout << "Masukan judul lagu yang ingin dihapus: ";
            cin >> cariJudul;
            deleteLaguGlobal(masterLagu, masterPlaylist, cariJudul);
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


void menuUser(){
    while (true){
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
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
            addressUser loggedInUser = loginUser();
            if (loggedInUser != nullptr){
                homeUser(loggedInUser);
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
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
        cout << endl;


        bool cek = true;

        cout << "Masukkan username: ";
        cin >> username;

        if (searchUser(dataUser, username) != nullptr) {
            cout << "Username sudah digunakan, coba lagi!" << endl;
        } else {
            cout << "Masukkan password: ";
            cin >> password;

            newUser.username = username;
            newUser.password = password;
            
            // Insert pakai SLL Insert
            insertLastUser(dataUser, createElmUser(newUser));
            cout << "Akun User berhasil dibuat!" << endl;
            break;
        }
    }
}

addressUser loginUser(){
    string username, password;

    if (dataUser.first == nullptr){
        cout << "Belum ada akun User yang dibuat." << endl;
        return nullptr;
    }

    cout << "\n--- Login User ---" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    addressUser P = searchUser(dataUser, username);

    if (P != nullptr && P->info.password == password){
        cout << "Halo " << P->info.username << "!" << endl;
        return P;
    } else {
        cout << "Username atau password salah!" << endl;
        return nullptr;
    }
}

void homeUser(addressUser userLogin){
    while(true){
        cout <<  "+====================+" << endl;
        cout <<  "|                     |" << endl;
        cout << "|       𝕤𝕡𝕠𝕥𝕚𝕜𝕦𝕪♬      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+====================+" << endl;
        cout << endl;


        cout << "\n--- Home User (" << userLogin->info.username << ") ---" << endl;
        showAllLagu(masterLagu);
        cout << "1. Mencari lagu" << endl;
        cout << "2. Tambah ke playlist" << endl;
        cout << "3. Lihat playlist" << endl;
        cout << "4. Back to menu" << endl;
        cout << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3/4): ";
        cin >> pilihan;
        string cari;

        switch (pilihan)
        {
        case 1: {
            cout << "Masukkan judul lagu: ";
            cin >> cari;
            addressLagu hasil = searchLaguJudul(masterLagu, cari);
            if (hasil) {
                cout << "Ditemukan: " << hasil->info.judul << " - " << hasil->info.penyanyi << endl;
            } else {
                cout << "Lagu tidak ditemukan." << endl;
            }
            break;
        }
        case 2:{
            string judul;
            cout << "Judul lagu: ";
            cin >> judul;

            addressLagu L = searchLaguJudul(masterLagu, judul);

            if (L != nullptr){
                addToPlaylist(userLogin, L);
            } else {
                cout << "Lagu tidak ditemukan!" << endl;
            }
            break;
        }
        case 3:{
            showPlaylist(userLogin);
            break;
        }

        case 4:
            return;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
};