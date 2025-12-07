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
    Lagu l1 = {1, "Hati-Hati di Jalan", "Tulus", "03:45", 5, "Pop"}; 
    Lagu l2 = {2, "Komang", "Raim Laode", "03:20", 5, "Ballad"};
    Lagu l3 = {3, "Sial", "Mahalini", "04:10", 5, "Pop"};
    Lagu l4 = {4, "Secukupnya", "Hindia", "04:05", 5, "Indie"};
    Lagu l5 = {5, "Evaluasi", "Hindia", "04:20", 5, "Indie"};
    Lagu l6 = {6, "Membasuh", "Hindia", "05:01", 5, "Indie"};
    Lagu l7 = {7, "Dehidrasi", "Hindia", "03:52", 5, "Indie"};
    Lagu l8 = {8, "We Don't Talk Enought", "Hindia", "04:11", 5, "Indie"};
    Lagu l9 = {9, "Tabola Bale", "Silet Open Up", "04:35", 5, "Hipdut"};
    Lagu l10 = {10, "Kali Kedua", "Raisa", "03:51", 5, "Pop"};
    Lagu l11 = {11, "Serba Salah", "Raisa", "04:13", 5, "Pop"};
    Lagu l12 = {12, "Bahasa Kalbu", "Raisa", "04:26", 5, "Pop"};
    Lagu l13 = {13, "Usai", "Tiara Andini", "03:38", 5, "Pop"};
    Lagu l14 = {14, "Janji Setia", "Tiara Andini", "04:29", 5, "Pop"};
    Lagu l15 = {15, "Cukup", "Ziva Magnolya", "04:05", 5, "Pop"};

    insertLastLagu(masterLagu, createElmLagu(l1));
    insertLastLagu(masterLagu, createElmLagu(l2));
    insertLastLagu(masterLagu, createElmLagu(l3));
    insertLastLagu(masterLagu, createElmLagu(l4));
    insertLastLagu(masterLagu, createElmLagu(l5));
    insertLastLagu(masterLagu, createElmLagu(l6));
    insertLastLagu(masterLagu, createElmLagu(l7));
    insertLastLagu(masterLagu, createElmLagu(l8));
    insertLastLagu(masterLagu, createElmLagu(l9));
    insertLastLagu(masterLagu, createElmLagu(l10));
    insertLastLagu(masterLagu, createElmLagu(l11));
    insertLastLagu(masterLagu, createElmLagu(l12));
    insertLastLagu(masterLagu, createElmLagu(l13));
    insertLastLagu(masterLagu, createElmLagu(l14));
    insertLastLagu(masterLagu, createElmLagu(l15));

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