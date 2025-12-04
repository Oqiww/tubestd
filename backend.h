#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <string>
#include <iomanip> // Untuk merapikan tabel UI
using namespace std;

// ==========================================
// 1. STRUKTUR DATA LAGU
// ==========================================
struct Lagu {
    int id;
    string judul, penyanyi;
    string durasi; // String durasi display (ex: "03:40")
    int durasiDetik; // Integer untuk simulasi play (ex: 220)
    string genre;
};

typedef struct listLagu *addressLagu;

struct listLagu {
    Lagu info;
    addressLagu next;
    addressLagu prev;
};

struct ListLagu{
    addressLagu first;
    addressLagu last;
};

// ==========================================
// 2. STRUKTUR RELASI: PLAYLIST -> LAGU
// ==========================================
typedef struct elmRelasiLagu *addressRelasiLagu;

struct elmRelasiLagu {
    addressLagu recLagu; 
    addressRelasiLagu next;
    addressRelasiLagu prev;
};

struct ListRelasiLagu {
    addressRelasiLagu first;
    addressRelasiLagu last;
};

// ==========================================
// 3. STRUKTUR DATA PLAYLIST
// ==========================================
struct InfotypePlaylist {
    int id;
    string namaPlaylist;
    string pembuat; 
    bool isFavorite; 
};

typedef struct elmPlaylist *addressPlaylist;

struct elmPlaylist {
    InfotypePlaylist info;
    ListRelasiLagu listLagu; 
    addressPlaylist next;
    addressPlaylist prev;
};

struct ListPlaylist {
    addressPlaylist first;
    addressPlaylist last;
};

// ==========================================
// 4. STRUKTUR RELASI: USER -> PLAYLIST
// ==========================================
typedef struct elmRelasiPlaylist *addressRelasiPlaylist;

struct elmRelasiPlaylist {
    addressPlaylist recPlaylist;
    addressRelasiPlaylist next;
    addressRelasiPlaylist prev;
};

struct ListRelasiPlaylist {
    addressRelasiPlaylist first;
    addressRelasiPlaylist last;
};

// ==========================================
// 5. STRUKTUR DATA USER
// ==========================================
struct User {
    string username;
    string password;
};

typedef struct elmUser *addressUser;

struct elmUser {
    User info;
    ListRelasiPlaylist listPlaylist;
    addressUser next;
};

struct ListUser {
    addressUser first;
};

// ==========================================
// 6. STRUKTUR DATA ADMIN
// ==========================================
struct Admin {
    string username;
    string password;
};

typedef struct elmAdmin *addressAdmin;

struct elmAdmin {
    Admin info;
    addressAdmin next;
};

struct ListAdmin {
    addressAdmin first;  
};


// ==========================================
// PRIMITIF FUNCTIONS
// ==========================================

// LAGU
void createListLagu(ListLagu &L);
addressLagu createElmLagu(Lagu data);
void insertLastLagu(ListLagu &L, addressLagu P);
void showAllLagu(ListLagu L);
addressLagu searchLaguJudul(ListLagu L, string x);
void deleteLaguGlobal(ListLagu &L, ListPlaylist &LP, string judul); 
void editLaguGlobal(ListLagu &L, string judulBaru, string penyanyiBaru, string durasiBaru, string genreBaru, addressLagu P);

// PLAYLIST
void createListPlaylist(ListPlaylist &L);
addressPlaylist createElmPlaylist(InfotypePlaylist data);
void insertLastPlaylist(ListPlaylist &L, addressPlaylist P);
addressPlaylist searchPlaylist(ListPlaylist L, string namaPlaylist);
void showAllPlaylist(ListPlaylist L);

// ADMIN
void createListAdmin(ListAdmin &L);
addressAdmin createElmAdmin(Admin data);
void insertLastAdmin(ListAdmin &L, addressAdmin P);
addressAdmin searchAdmin(ListAdmin L, string username);

// USER
void createListUser(ListUser &L);
addressUser createElmUser(User data);
void insertLastUser(ListUser &L, addressUser P);
addressUser searchUser(ListUser L, string username);

// RELASI & FITUR
void userCreatePlaylist(ListPlaylist &LP, addressUser U, string namaPlaylist, bool isFav);
void addSongToPlaylist(addressUser U, string namaPlaylist, addressLagu P_Lagu);
void removeSongFromPlaylist(addressUser U, string namaPlaylist, string judulLagu);
// Fungsi tampil diperbarui untuk UI
void showPlaylistContent(addressPlaylist P); 
void userFollowPlaylist(addressUser U, addressPlaylist P);

#endif