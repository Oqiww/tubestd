#include "app.h"
#include "backend.h"
#include <thread>
#include <chrono>
using namespace std;

// Variabel Global
ListAdmin dataAdmin;
ListUser dataUser;
ListLagu masterLagu;
ListPlaylist masterPlaylist;

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
};

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
    Lagu l8 = {8, "We Don't Talk Enough", "Hindia", "04:11", 5, "Indie"};
    Lagu l9 = {9, "Tabola Bale", "Silet Open Up", "04:35", 5, "Hipdut"};
    Lagu l10 = {10, "Kali Kedua", "Raisa", "03:51", 5, "Pop"};
    Lagu l11 = {11, "Tujuh Belas", "Tulus", "04:13", 5, "Pop"};
    Lagu l12 = {12, "Hari bersamanya", "Sheila On 7", "04:26", 5, "Pop"};
    Lagu l13 = {13, "ILYSB", "LANY", "03:38", 5, "Pop"};
    Lagu l14 = {14, "Taruh", "Nadin Amizah", "04:29", 5, "Pop"};
    Lagu l15 = {15, "Sorai", "Nadin Amizah", "04:05", 5, "Pop"};

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

    // User 1
    User u1_data = {"rosandi", "1234"};
    addressUser u1 = createElmUser(u1_data);
    insertLastUser(dataUser, u1);
    userCreatePlaylist(masterPlaylist, u1, "Liked Songs", true);

    // User 2
    User u2_data = {"nada", "1234"};
    addressUser u2 = createElmUser(u2_data);
    insertLastUser(dataUser, u2);
    userCreatePlaylist(masterPlaylist, u2, "Liked Songs", true);

    // User 3
    User u3_data = {"syauqi", "1234"};
    addressUser u3 = createElmUser(u3_data);
    insertLastUser(dataUser, u3);
    userCreatePlaylist(masterPlaylist, u3, "Liked Songs", true);
    userCreatePlaylist(masterPlaylist, u3, "Chill Vibes", false);

    bool ulang = true;
    while (ulang){

        cout <<  "+=====================+" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "|       SPOTIKUY      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+=====================+" << endl;

        cout << "[1] Admin" << endl;
        cout << "[2] User" << endl;
        cout << "[3] Keluar" << endl;
        cout << "------------------------" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;

         if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
        }

        switch (pilihan)
        {
        case 1:
            clearScreen();
            menuAdmin();
            break;
        case 2:
            clearScreen();
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
    clearScreen();
};

// Menu admin
void menuAdmin(){
    while (true){

        cout <<  "+=====================+" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "|       SPOTIKUY      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+=====================+" << endl;

        cout << "[1] Sign up" << endl;
        cout << "[2] Login" << endl;
        cout << "[3] Kembali ke menu" << endl;
        cout << "-----------------------" << endl;


        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;

        if (pilihan != 1 && pilihan != 2 && pilihan != 3) {
        cout << "Input tidak valid!" << endl;
        }

        switch (pilihan)
        {
        case 1:
            signUpAdmin();
            break;
        case 2:
        {
            addressAdmin adm = loginAdmin();
            if (adm) {
                homeAdmin(adm);
            }
        }
            break;
        case 3:
            clearScreen();
            return;
        default:
            cout << "Inputan anda salah ulangi lagi!" << endl;
            break;
        }
    }
};

// Prosedur untuk sign up admin
void signUpAdmin(){
    string username, password;
    Admin data;
    while (true){

        bool cek = true;
        cout << endl;
        cout << "Masukkan username anda: ";
        cin >> username;

        if (searchAdmin(dataAdmin, username)) {
            cout << "Username telah dipakai!\n";
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

// fungsi untuk login admin
addressAdmin loginAdmin(){
    string username, password;

    if (dataAdmin.first == nullptr){
        cout << "Belum ada akun Admin yang terdaftar.\n";
        return nullptr;
    }
    clearScreen();
    cout << "\n--- Login Admin ---" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    addressAdmin P = searchAdmin(dataAdmin, username);

    if (P != nullptr && P->info.password == password) {
        cout << endl;
        cout << "Halo " << P->info.username << "!" << endl;
        return P;
    } else {
        cout << "Username atau Password salah!" << endl;
        return nullptr;
    }
};

// menu admin
void homeAdmin(addressAdmin adminLogin){
    string cariJudul;
    while(true){
        cout << endl;
        cout <<  "+=====================+" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "|       SPOTIKUY      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+=====================+" << endl;
        cout << "\n--- Dashboard Admin (" << adminLogin->info.username << ") ---" << endl;
        cout << endl;

        cout << "[1] Tambah lagu" << endl;
        cout << "[2] Edit lagu" << endl;
        cout << "[3] Hapus Lagu" << endl;
        cout << "[4] Lihat semua lagu" << endl;
        cout << "[5] Kembali" << endl;
        cout << "------------------------" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3/4/5): ";
        cin >> pilihan;

        switch (pilihan){
        case 1: {
            clearScreen();
            Lagu L;
            cout << "ID Lagu: ";
            cin >> L.id;
            cin.ignore(); 
            cout << "Judul: ";
            getline(cin, L.judul);
            cout << "Penyanyi: ";
            getline(cin, L.penyanyi);
            cout << "Durasi (ex: 03:20): ";
            cin >> L.durasi;
            L.durasiDetik = 5;
            cout << "Genre: ";
            cin >> L.genre;

            insertLastLagu(masterLagu, createElmLagu(L));
            cout << "Lagu berhasil ditambahkan!" << endl;
            break;
        }
        case 2:{
            clearScreen();
            showAllLagu(masterLagu);
            cout << "Masukan judul lagu yang mau diedit: ";
            cin.ignore();
            getline(cin, cariJudul);
            addressLagu P = searchLaguJudul(masterLagu, cariJudul);

            if (P){
                cout << "--- Data Baru ---" << endl;
                string judulBaru, penyanyiBaru, durasaiBaru, genreBaru;
                cout << "Judul Baru: ";
                getline(cin, judulBaru);
                cout << "Penyanyi Baru: ";
                getline(cin, penyanyiBaru);
                cout << "Durasi Baru: ";
                cin >> durasaiBaru;
                cout << "Genre Baru: ";
                cin >> genreBaru;
                editLaguGlobal(judulBaru, penyanyiBaru, durasaiBaru, genreBaru, P);
                break;
            } else {
                cout << "Lagu tidak ditemukan!" << endl;
            }
            break;
        }
        case 3:
            clearScreen();
            showAllLagu(masterLagu);
            cout << "Masukan judul lagu yang ingin dihapus: ";
            cin.ignore();
            getline(cin, cariJudul);
            deleteLaguGlobal(masterLagu, masterPlaylist, cariJudul);
            break;
        case 4:
            clearScreen();
            showAllLagu(masterLagu);
            break;
        case 5:
            clearScreen();
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }

};

// menu user
void menuUser(){
    while (true){
        cout <<  "+=====================+" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "|       SPOTIKUY      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+=====================+" << endl;
        cout << endl;


        cout << "[1] Sign up" << endl;
        cout << "[2] Login" << endl;
        cout << "[3] Kembali ke menu" << endl;
        cout << "-----------------------" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;

         if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
        }

        switch (pilihan){
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
    clearScreen();
}


// prosedur untuk sign up user
void signUpUser(){
    string username, password;
    User newUser;

    while (true){
        cout <<  "+=====================+" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "|       SPOTIKUY      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+=====================+" << endl;
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
            addressUser baru = createElmUser(newUser);

            insertLastUser(dataUser, baru);
            userCreatePlaylist(masterPlaylist, baru, "Liked Songs", true);
            cout << "Akun User berhasil dibuat!" << endl;
            break;
        }
    }
}

// fungsi untuk login user
addressUser loginUser(){
    string username, password;

    if (dataUser.first == nullptr){
        cout << "Belum ada akun User yang dibuat." << endl;
        return nullptr;
    }

    clearScreen();
    cout << "\n--- Login User ---" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    addressUser P = searchUser(dataUser, username);

    if (P != nullptr && P->info.password == password){
        cout << endl;
        cout << "Halo " << P->info.username << "!" << endl;
        return P;
    } else {
        cout << "Username atau password salah!" << endl;
        return nullptr;
    }
}

// prosedur untuk mencari lagu yang diinginkan user
void menuSearchResult(addressUser U, addressLagu L) {
    string namaP;
    while(true) {
        cout << "\n--- Lagu Ditemukan: " << L->info.judul << " - " << L->info.penyanyi << " ---" << endl;
        cout << "[1] Play Lagu (Auto-next Genre)" << endl;
        cout << "[2] Tambahkan ke Liked Songs" << endl;
        cout << "[3] Tambahkan ke Playlist Lain" << endl;
        cout << "[4] Kembali" << endl;
        cout << "----------------------------------" << endl;
        int pilih;
        cout << "Masukkan pilihan anda (1/2/3/4): ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
        }


        switch (pilih)
        {
        case 1:
            // Memainkan lagu yang genrenya mirip
            musicPlayerGlobal(L);
            break;
        case 2:
            // Menambahkan lagu ke favorite
            addSongToPlaylist(U, "Liked Songs", L);
            break;
        case 3:{
            // Menambahkan lagu ke playlist
            cout << "\n[ Daftar Playlist Anda ]\n";
            addressRelasiPlaylist R = U->listPlaylist.first;
            while (R != nullptr) {
                cout << "- " << R->recPlaylist->info.namaPlaylist << endl;
                R = R->next;
            }
            cout << "Masukkan nama playlist tujuan: ";
            cin.ignore();
            getline(cin, namaP);
            addSongToPlaylist(U, namaP, L);
            break;
            }
        case 4:
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    }
}

// Menu home user
void homeUser(addressUser userLogin){
    string namaP;
    while(true){
        cout <<  "+=====================+" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "|       SPOTIKUY      |" << endl;
        cout <<  "|                     |" << endl;
        cout <<  "+=====================+" << endl;

        cout << "\n----- YOUR LIBRARY -----\n";
        addressRelasiPlaylist R = userLogin->listPlaylist.first;
        if (R == nullptr){
            cout << "(Library Kosong)" << endl;
        }
        int i = 1;
       while (R != nullptr) {
            cout << i++ << ". " << R->recPlaylist->info.namaPlaylist;
            cout << " (";

            if (R->recPlaylist->info.pembuat == userLogin->info.username) {
                cout << "Owner";
            } else {
                cout << "Followed";
            }
            cout << ")" << endl;
            R = R->next;
        }

        cout << "-------------------------------" << endl;
        cout << "[1] Lihat Playlist (Play/Edit)" << endl;
        cout << "[2] Lihat Semua Lagu Global" << endl;
        cout << "[3] Buat Playlist Baru" << endl;
        cout << "[4] Cari & Ikuti Playlist" << endl;
        cout << "[5] Cari Lagu (Play/Add)" << endl; 
        cout << "[6] Keluar" << endl;
        cout << "-------------------------------" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3/4/5/6): ";
        cin >> pilihan;

         if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
        }

        switch (pilihan)
        {
        case 1: {
            clearScreen();
            cout << "Nama Playlist: ";
            cin.ignore();
            getline(cin, namaP);
            addressPlaylist target = nullptr;
            addressRelasiPlaylist RP = userLogin->listPlaylist.first;
            while (RP) {
                if (RP->recPlaylist->info.namaPlaylist == namaP) {
                    target = RP->recPlaylist;
                    break;
                }
                RP = RP->next;
            }

            if (target) {
                menuDetailPlaylist(userLogin, target);
            } else {
                cout << "Playlist tidak ditemukan di library Anda." << endl;
            }
            break;
        }
        case 2:
            clearScreen();
            showAllLagu(masterLagu);
            cout << "\n(Tekan Enter untuk kembali)" << endl;
            cin.ignore();
            cin.get();
            break;

        case 3:{
            cout << "Nama Playlist Baru: " << endl;
            cin.ignore();
            getline(cin, namaP);
            userCreatePlaylist(masterPlaylist, userLogin, namaP, false);
            break;
        }
        case 4:{
            clearScreen();
            showAllPlaylist(masterPlaylist);
            cout << "Masukkan nama playlist yang ingin di follow: ";
            cin.ignore();
            getline(cin, namaP);
            addressPlaylist P = searchPlaylist(masterPlaylist, namaP);
            if (P) {
                if (P->info.pembuat == userLogin->info.username) {
                    cout << "Anda tidak dapat follow playlist sendiri :)" << endl;
                } else {
                    bool alreadyFollowed = false;
                    addressRelasiPlaylist cek = userLogin->listPlaylist.first;
                    while (cek) {
                        if (cek->recPlaylist == P) {
                            alreadyFollowed = true;
                            break;
                        }
                        cek = cek->next;
                    }
                    if (!alreadyFollowed) {
                        userFollowPlaylist(userLogin, P);
                        cout << "Berhasil follow playlist " << namaP << "!" << endl;
                    } else {
                        cout << "Anda sudah follow playlist ini." << endl;
                    }
                }
            } else {
                cout << "Playlist tidak ditemukan!" << endl;
            }
            break;
        }
        case 5: {
            // FITUR SEARCH & ACTION
            clearScreen();
            string judulCari;
            cout << "Masukkan Judul Lagu: ";
            cin.ignore();
            getline(cin, judulCari);
            addressLagu hasil = searchLaguJudul(masterLagu, judulCari);
            if (hasil) {
                menuSearchResult(userLogin, hasil);
            } else {
                cout << "Lagu tidak ditemukan." << endl;
            }
            break;
        }
        case 6:
            clearScreen();
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    clearScreen();
};

// Memutar lagu global dengan genre yang mirip
void musicPlayerGlobal(addressLagu startSong) {
    if (startSong == nullptr) {
        return;
    }

    addressLagu currentSong = startSong;
    string genreMode = startSong->info.genre;

    cout << "\n[ SMART AUTOPLAY STARTED: GENRE " << genreMode << " ]" << endl;

    while (currentSong != nullptr) {
        // Play
        for (int i = 1; i <= currentSong->info.durasiDetik; i++) {
            clearScreen();
            cout << "========================================" << endl;
            cout << "      GLOBAL PLAY (Genre: " << genreMode << ")      " << endl;
            cout << "========================================" << endl;
            cout << "Title  : " << currentSong->info.judul << endl;
            cout << "Artist : " << currentSong->info.penyanyi << endl;
            cout << "Time   : " << i << "s / " << currentSong->info.durasiDetik << "s " << endl;
            cout << "========================================" << endl;
            cout << "[Playing...] " << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }

        bool controlLoop = true;
        while(controlLoop) {
            cout << "========================================" << endl;
            cout << "      SONG FINISHED: " << currentSong->info.judul << endl;
            cout << "========================================" << endl;
            cout << "[n] Next Song (Same Genre)" << endl;
            cout << "[p] Previous Song (Same Genre)" << endl;
            cout << "[s] Stop / Exit Player" << endl;
            cout << "Pilihan: ";

            char pilih;
            cout << "Masukkan pilihan anda (n/p/s): ";
            cin >> pilih;

            if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
            }


            switch (pilih)
            {
            case 'n': {
            // Cari next song dengan genre sama
                addressLagu nextSong = getNextLaguByGenre(currentSong, genreMode);
                if (nextSong) {
                    currentSong = nextSong;
                }else{
                    cout << "Tidak ada lagu lain dengan genre ini." << endl;
                }
                controlLoop = false;
                break;
            }
            case 'p':{
            // Cari prev song dengan genre sama
                addressLagu prevSong = getPrevLaguByGenre(currentSong, genreMode);
                if (prevSong) {
                    currentSong = prevSong;
                }else{
                    cout << "Tidak ada lagu lain dengan genre ini." << endl;
                }
                controlLoop = false;
                break;
            }
            case 's':
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }
    }
}

void musicPlayer(addressPlaylist P, int modeSort) {
    if (P->listLagu.first == nullptr) {
        cout << "Playlist kosong! Tambahkan lagu terlebih dahulu." << endl;
        return;
    }

    addressRelasiLagu currentSong;
    if (modeSort == 1) {
        currentSong = P->listLagu.first; // Terlama (Queue)
    }else {
        currentSong = P->listLagu.last; // Terbaru (Stack)
    }
    while (currentSong != nullptr) {
        for (int i = 1; i <= currentSong->recLagu->info.durasiDetik; i++) {
            clearScreen();
            cout << "========================================" << endl;
            cout << "       NOW PLAYING (" << P->info.namaPlaylist << ")      " << endl;
            cout << "========================================" << endl;
            cout << "Title  : " << currentSong->recLagu->info.judul << endl;
            cout << "Artist : " << currentSong->recLagu->info.penyanyi << endl;
            cout << "Time   : " << i << "s / " << currentSong->recLagu->info.durasiDetik << "s " << endl;
            cout << "========================================" << endl;
            cout << "[Playing...] " << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }

        bool controlLoop = true;
        while(controlLoop) {
            clearScreen();
            cout << "========================================" << endl;
            cout << "       SONG FINISHED: " << currentSong->recLagu->info.judul << endl;
            cout << "========================================" << endl;
            cout << "[n] Next Song" << endl;
            cout << "[p] Previous Song" << endl;
            cout << "[s] Stop / Exit Player" << endl;
            cout << "----------------------------------------: " << endl;

            char pilih;
            cout << "Masukkan pilihan anda (n/p/s): ";
            cin >> pilih;

             if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
            }

            switch (pilih)
            {
            case 's':
                return;
            case 'n': {
                if (modeSort == 1) {
                    currentSong = currentSong->next;
                }else{
                     currentSong = currentSong->prev;
                }

                // Jika lagu habis akan memutar otomatis dari genre yang sama
                if (currentSong == nullptr) {
                    cout << "\n[INFO] Playlist Selesai. Melanjutkan Smart Autoplay berdasarkan Genre..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));

                    // Panggil Global Player mulai dari lagu terakhir (cari genre sama)
                    // Kita cari nextnya dari lagu terakhir yang diputar
                    // Karena currentRelasi sudah null, kita butuh pointer ke lagu terakhir
                    addressLagu lastSongPlayed;
                    if(modeSort == 1) {
                        lastSongPlayed = P->listLagu.last->recLagu;
                    }else{
                        lastSongPlayed = P->listLagu.first->recLagu;
                    }

                    // Cari lagu selanjutnya di global dengan genre sama
                    addressLagu nextGlobal = getNextLaguByGenre(lastSongPlayed, lastSongPlayed->info.genre);
                    if(nextGlobal) {
                        musicPlayerGlobal(nextGlobal);
                    }else{
                        cout << "Tidak ada lagu sejenis di database global." << endl;
                    }

                    return;
                }
                controlLoop = false;
                break;
            }
            case 'p': {
                if (modeSort == 1) {
                    currentSong = currentSong->prev;
                }else{
                    currentSong = currentSong->next;
                }
                if (currentSong == nullptr) {
                    cout << "Awal Playlist." << endl;

                    if (modeSort == 1) {
                        currentSong = P->listLagu.first;
                    }else{
                        currentSong = P->listLagu.last;
                    }
                }
                controlLoop = false;
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }
    }
};

// Prosedur detail playlist
void menuDetailPlaylist(addressUser U, addressPlaylist P) {
    bool isOwner = (P->info.pembuat == U->info.username);
    while (true){
        cout << "PLAYLIST: " << P->info.namaPlaylist << endl;
        cout << endl;
        showPlaylistContent(P);

        cout << "[1] Play (Urutan Masuk: Terlama -> Terbaru)" << endl;
        cout << "[2] Play (Urutan Masuk: Terbaru -> Terlama)" << endl;
        cout << "[3] Tambah Lagu" << endl;
        cout << "[4] Hapus Lagu" << endl;
        cout << "[5] Keluar" << endl;
        cout << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1/2/3/4/5): ";
        cin >> pilihan;

         if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // buang input salah
        }

        switch (pilihan)
        {
        case 1:
            musicPlayer(P, 1);
            break;
        case 2:
            musicPlayer(P, 2);
            break;
        case 3: {
            if (isOwner) {
                showAllLagu(masterLagu);
                string judul;
                cout << "Masukkan Judul Lagu (Cek Global dulu): ";
                cin.ignore();
                getline(cin, judul);
                addressLagu L = searchLaguJudul(masterLagu, judul);
                if (L) {
                    addSongToPlaylist(U, P->info.namaPlaylist, L);
                } else {
                    cout << "Lagu tidak ditemukan." << endl;
                }
            }else {
                cout << "Akses ditolak. Hanya pemilik playlist yang dapat menambah lagu." << endl ;
            }
        }
            break;
        case 4: {
            if (isOwner) {
                string judul; cout << "Hapus Judul: ";
                cin.ignore();
                getline(cin, judul);
                removeSongFromPlaylist(U, P->info.namaPlaylist, judul);
                break;
            }else{
                cout << "Akses ditolak. Hanya pemilik playlist yang dapat menghapus lagu." << endl ;
            }
        }
        case 5:
            clearScreen();
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    }
    clearScreen();
}
