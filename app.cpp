#include "app.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Variabel Global
ListAdmin dataAdmin;
ListUser dataUser;
ListLagu masterLagu;
ListPlaylist masterPlaylist;

// Helper function agar layar bersih
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void menu(){
    createListLagu(masterLagu);
    createListPlaylist(masterPlaylist);
    createListAdmin(dataAdmin);
    createListUser(dataUser);

    // DUMMY DATA LAGU
    Lagu l1 = {1, "Hati-Hati di Jalan", "Tulus", "03:45", 5, "Pop"}; 
    Lagu l2 = {2, "Komang", "Raim Laode", "03:20", 5, "Ballad"};
    Lagu l3 = {3, "Sial", "Mahalini", "04:10", 5, "Pop"};
    insertLastLagu(masterLagu, createElmLagu(l1));
    insertLastLagu(masterLagu, createElmLagu(l2));
    insertLastLagu(masterLagu, createElmLagu(l3));

    while (true){
        clearScreen();
        cout << "========================================\n";
        cout << "        WELCOME TO SPITIPI MUSIC        \n";
        cout << "========================================\n";
        cout << "[1] Masuk sebagai Admin\n";
        cout << "[2] Masuk sebagai User\n";
        cout << "[3] Exit\n";
        cout << "========================================\n";
        cout << "Pilihan >> ";
        
        int pilihan; cin >> pilihan;
        switch (pilihan) {
            case 1: menuAdmin(); break;
            case 2: menuUser(); break;
            case 3: cout << "Terimakasih!\n"; return;
            default: break;
        }
    }
}

// ================= ADMIN =================
void menuAdmin(){
    while (true){
        clearScreen();
        cout << "=== LOGIN ADMIN ===\n";
        cout << "[1] Sign Up\n[2] Login\n[3] Back\nPilihan >> ";
        int pilihan; cin >> pilihan;
        
        if (pilihan == 3) return;
        if (pilihan == 1) signUpAdmin();
        else if (pilihan == 2) {
            addressAdmin adm = loginAdmin();
            if (adm) homeAdmin(adm);
        }
    }
}

void signUpAdmin(){
    string u, p;
    cout << "Username: "; cin >> u;
    if (searchAdmin(dataAdmin, u)) { cout << "Username ada!\n"; system("pause"); return; }
    cout << "Password: "; cin >> p;
    Admin data = {u, p};
    insertLastAdmin(dataAdmin, createElmAdmin(data));
    cout << "Sukses!\n"; system("pause");
}

addressAdmin loginAdmin(){
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    addressAdmin P = searchAdmin(dataAdmin, u);
    if (P && P->info.password == p) return P;
    cout << "Gagal!\n"; system("pause"); return nullptr;
}

void homeAdmin(addressAdmin adminLogin){
    while(true){
        clearScreen();
        cout << "--- DASHBOARD ADMIN (" << adminLogin->info.username << ") ---\n";
        cout << "[1] Tambah Lagu Global\n";
        cout << "[2] Edit Lagu Global\n";
        cout << "[3] Hapus Lagu Global\n";
        cout << "[4] Lihat Semua Lagu\n";
        cout << "[5] Logout\n";
        cout << "Pilihan >> ";
        int pil; cin >> pil;
        
        if (pil == 5) return;
        
        if (pil == 1) { // TAMBAH LAGU
            Lagu L; L.id = rand();
            cout << "Judul: "; cin.ignore(); getline(cin, L.judul);
            cout << "Penyanyi: "; getline(cin, L.penyanyi);
            cout << "Durasi Teks (ex: 03:00): "; cin >> L.durasi;
            L.durasiDetik = 5; // Default simulasi 5 detik
            cout << "Genre: "; cin >> L.genre;
            insertLastLagu(masterLagu, createElmLagu(L));
            cout << "Berhasil!\n"; system("pause");

        } else if (pil == 2) { // EDIT LAGU GLOBAL
            string judulCari;
            cout << "Masukkan Judul Lagu yg mau diedit: "; cin.ignore(); getline(cin, judulCari);
            addressLagu P = searchLaguJudul(masterLagu, judulCari);
            
            if (P) {
                cout << "--- Data Baru ---\n";
                string j, pen, dur, gen;
                cout << "Judul Baru: "; getline(cin, j);
                cout << "Penyanyi Baru: "; getline(cin, pen);
                cout << "Durasi Baru: "; cin >> dur;
                cout << "Genre Baru: "; cin >> gen;
                editLaguGlobal(masterLagu, j, pen, dur, gen, P);
                system("pause");
            } else {
                cout << "Lagu tidak ditemukan!\n"; system("pause");
            }

        } else if (pil == 3) { // HAPUS LAGU GLOBAL
            string judulCari;
            cout << "Masukkan Judul Lagu yg mau dihapus: "; cin.ignore(); getline(cin, judulCari);
            deleteLaguGlobal(masterLagu, masterPlaylist, judulCari);
            system("pause");

        } else if (pil == 4) { // LIHAT SEMUA
            clearScreen();
            showAllLagu(masterLagu);
            system("pause");
        } 
    }
}

// ================= USER =================
void menuUser(){
    while (true){
        clearScreen();
        cout << "=== LOGIN USER ===\n";
        cout << "[1] Sign Up\n[2] Login\n[3] Back\nPilihan >> ";
        int pilihan; cin >> pilihan;
        if (pilihan == 3) return;
        if (pilihan == 1) signUpUser();
        else if (pilihan == 2) {
            addressUser u = loginUser();
            if (u) homeUser(u);
        }
    }
}

void signUpUser(){
    string u, p;
    cout << "Username: "; cin >> u;
    if (searchUser(dataUser, u)) { cout << "Username ada!\n"; system("pause"); return; }
    cout << "Password: "; cin >> p;
    User data = {u, p};
    addressUser newUser = createElmUser(data);
    insertLastUser(dataUser, newUser);
    userCreatePlaylist(masterPlaylist, newUser, "Liked Songs", true);
    cout << "Sukses! Silakan Login.\n"; system("pause");
}

addressUser loginUser(){
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    addressUser P = searchUser(dataUser, u);
    if (P && P->info.password == p) return P;
    cout << "Gagal!\n"; system("pause"); return nullptr;
}

void homeUser(addressUser userLogin){
    while(true){
        clearScreen();
        cout << "Hi, " << userLogin->info.username << "!\n";
        
        // TAMPILKAN SEMUA PLAYLIST USER
        cout << "\n[ YOUR LIBRARY ]\n";
        addressRelasiPlaylist R = userLogin->listPlaylist.first;
        if (R == nullptr) cout << "(Library Kosong)\n";
        int i = 1;
        while (R != nullptr) {
            cout << i++ << ". " << R->recPlaylist->info.namaPlaylist;
            if (R->recPlaylist->info.isFavorite) cout << " [♥]";
            cout << " (" << (R->recPlaylist->info.pembuat == userLogin->info.username ? "Owner" : "Followed") << ")\n";
            R = R->next;
        }
        cout << "--------------------------------\n";
        cout << "[1] Buka Playlist (Play/Edit)\n";
        cout << "[2] Buat Playlist Baru\n";
        cout << "[3] Cari & Follow Playlist\n";
        cout << "[4] Lihat Semua Lagu Global\n";
        cout << "[5] Logout\n";
        cout << "Pilihan >> ";
        
        int pil; cin >> pil;
        if (pil == 5) return;

        if (pil == 1) { // BUKA PLAYLIST
            string namaP; cout << "Nama Playlist: "; cin.ignore(); getline(cin, namaP);
            addressPlaylist target = nullptr;
            addressRelasiPlaylist RP = userLogin->listPlaylist.first;
            while (RP) {
                if (RP->recPlaylist->info.namaPlaylist == namaP) { target = RP->recPlaylist; break; }
                RP = RP->next;
            }
            if (target) menuDetailPlaylist(userLogin, target);
            else { cout << "Playlist tidak ditemukan di library Anda.\n"; system("pause"); }

        } else if (pil == 2) { // BUAT PLAYLIST
            string namaP; cout << "Nama Playlist Baru: "; cin.ignore(); getline(cin, namaP);
            userCreatePlaylist(masterPlaylist, userLogin, namaP, false);
            system("pause");

        } else if (pil == 3) { // CARI & FOLLOW PLAYLIST (YANG HILANG TADI)
            clearScreen();
            showAllPlaylist(masterPlaylist);
            string namaP; 
            cout << "Masukkan Nama Playlist yang mau difollow: "; cin.ignore(); getline(cin, namaP);
            
            addressPlaylist P = searchPlaylist(masterPlaylist, namaP);
            if (P) {
                // Cek apakah punya sendiri
                if (P->info.pembuat == userLogin->info.username) {
                    cout << "Itu playlist buatan Anda sendiri.\n";
                } else {
                    // Cek apakah sudah difollow (opsional, tapi biar rapi)
                    bool alreadyFollow = false;
                    addressRelasiPlaylist cek = userLogin->listPlaylist.first;
                    while(cek){
                        if(cek->recPlaylist == P) { alreadyFollow = true; break; }
                        cek = cek->next;
                    }

                    if (!alreadyFollow) {
                        userFollowPlaylist(userLogin, P);
                        cout << "Berhasil follow playlist " << namaP << "!\n";
                    } else {
                        cout << "Anda sudah follow playlist ini.\n";
                    }
                }
            } else {
                cout << "Playlist tidak ditemukan.\n";
            }
            system("pause");

        } else if (pil == 4) { // LIHAT LAGU
            clearScreen();
            showAllLagu(masterLagu);
            cout << "\n(Tekan Enter kembali)"; system("pause");
        }
    }
}

// ================= PLAYER LOGIC =================
void musicPlayer(addressPlaylist P, int modeSort) {
    if (P->listLagu.first == nullptr) {
        cout << "Playlist kosong! Tambahkan lagu dulu.\n";
        system("pause");
        return;
    }

    addressRelasiLagu currentSong;
    if (modeSort == 1) currentSong = P->listLagu.first; // Terlama (Queue)
    else currentSong = P->listLagu.last; // Terbaru (Stack)

    while (currentSong != nullptr) {
        // SIMULASI PLAYING
        for (int i = 1; i <= currentSong->recLagu->info.durasiDetik; i++) {
            clearScreen();
            cout << "========================================\n";
            cout << "       NOW PLAYING (" << P->info.namaPlaylist << ")      \n";
            cout << "========================================\n";
            cout << "Title  : " << currentSong->recLagu->info.judul << "\n";
            cout << "Artist : " << currentSong->recLagu->info.penyanyi << "\n";
            cout << "Time   : " << i << "s / " << currentSong->recLagu->info.durasiDetik << "s \n";
            cout << "========================================\n";
            cout << "[Playing...] \n";
            this_thread::sleep_for(chrono::seconds(1));
        }

        bool controlLoop = true;
        while(controlLoop) {
            clearScreen();
            cout << "========================================\n";
            cout << "       SONG FINISHED: " << currentSong->recLagu->info.judul << "\n";
            cout << "========================================\n";
            cout << "[n] Next Song\n";
            cout << "[p] Previous Song\n";
            cout << "[s] Stop / Exit Player\n";
            cout << "Command >> ";
            char cmd; cin >> cmd;

            if (cmd == 's') { return; } 
            else if (cmd == 'n') {
                if (modeSort == 1) currentSong = currentSong->next; 
                else currentSong = currentSong->prev; 
                if (currentSong == nullptr) { cout << "End of Playlist.\n"; system("pause"); return; }
                controlLoop = false; 
            }
            else if (cmd == 'p') {
                if (modeSort == 1) currentSong = currentSong->prev;
                else currentSong = currentSong->next;
                if (currentSong == nullptr) { cout << "Start of Playlist.\n"; system("pause"); return; }
                controlLoop = false;
            }
        }
    }
}


void menuDetailPlaylist(addressUser U, addressPlaylist P) {
    bool isOwner = (P->info.pembuat == U->info.username);
    while (true) {
        clearScreen();
        cout << "PLAYLIST: " << P->info.namaPlaylist << "\n";
        showPlaylistContent(P);
        cout << "\n[1] Play (Urutan Masuk: Terlama -> Terbaru)\n";
        cout << "[2] Play (Urutan Masuk: Terbaru -> Terlama)\n";
        if (isOwner) {
            cout << "[3] Add Song\n[4] Remove Song\n";
        }
        cout << "[0] Back\n>> ";
        int pil; cin >> pil;

        if (pil == 0) return;
        if (pil == 1) musicPlayer(P, 1);
        else if (pil == 2) musicPlayer(P, 2);
        else if (isOwner && pil == 3) {
            string judul; 
            cout << "Masukkan Judul Lagu (Cek Global dulu): "; cin.ignore(); getline(cin, judul);
            addressLagu L = searchLaguJudul(masterLagu, judul);
            if (L) addSongToPlaylist(U, P->info.namaPlaylist, L);
            else cout << "Lagu tidak ditemukan.\n";
            system("pause");
        }
        else if (isOwner && pil == 4) {
            string judul; cout << "Hapus Judul: "; cin.ignore(); getline(cin, judul);
            removeSongFromPlaylist(U, P->info.namaPlaylist, judul);
            system("pause");
        }
    }
}