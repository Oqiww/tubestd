#include "app.h"
#include "backend.h"
#include <iostream>
using namespace std;

// =======================
// IMPLEMENTASI Playlist (MLL)
// =======================
void createListPlaylist(ListPlaylist &L){
    L.first = nullptr;
    L.last = nullptr;
}

addressPlaylist createElmPlaylist(InfotypePlaylist data){
    addressPlaylist P = new elmPlaylist;
    P->info = data;
    P->listLagu.first = nullptr;
    P->listLagu.last = nullptr;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void insertLastPlaylist(ListPlaylist &L, addressPlaylist P){
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

addressPlaylist searchPlaylist(ListPlaylist L, string namaPlaylist){
    addressPlaylist P = L.first;
    while(P != nullptr){
        if (P->info.namaPlaylist == namaPlaylist){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllPlaylist(ListPlaylist L) {
    cout << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "|           PUBLIC PLAYLISTS             |" << endl;
    cout << "+----------------------------------------+" << endl;
    addressPlaylist P = L.first;
    if (P == nullptr) { 
        cout << "| (Kosong)                               |" << endl; 
    }
    while (P != nullptr) {
        if (!P->info.isFavorite) {
            cout << "| " << left << setw(20) << P->info.namaPlaylist << " (" << setw(10) << P->info.pembuat << ") |" << endl;
        }
        P = P->next;
    }
    cout << "+----------------------------------------+" << endl;
}

//FITUR
void userCreatePlaylist(ListPlaylist &LP, addressUser U, string namaPlaylist, bool isFav) {
    InfotypePlaylist dataP; 
    dataP.id = rand(); 
    dataP.namaPlaylist = namaPlaylist; 
    dataP.pembuat = U->info.username; 
    dataP.isFavorite = isFav;
    addressPlaylist newP = createElmPlaylist(dataP);
    insertLastPlaylist(LP, newP);
    userFollowPlaylist(U, newP);
    if(!isFav) {
        cout << ">> Playlist '" << namaPlaylist << "' berhasil dibuat." << endl;
    }
}

void userFollowPlaylist(addressUser U, addressPlaylist P) {
    addressRelasiPlaylist R = new elmRelasiPlaylist; 
    R->recPlaylist = P; 
    R->next = nullptr; 
    R->prev = nullptr;
    if (U->listPlaylist.first == nullptr) { 
        U->listPlaylist.first = R; 
        U->listPlaylist.last = R;
    }
    else { 
        U->listPlaylist.last->next = R; 
        R->prev = U->listPlaylist.last; 
        U->listPlaylist.last = R;
    }
}

void addSongToPlaylist(addressUser U, string namaPlaylist, addressLagu P_Lagu) {
    addressRelasiPlaylist R_Play = U->listPlaylist.first;
    addressPlaylist targetP = nullptr;
    while (R_Play != nullptr) {
        if (R_Play->recPlaylist->info.namaPlaylist == namaPlaylist) { 
            targetP = R_Play->recPlaylist; 
            break; 
        }
        R_Play = R_Play->next;
    }
    if (targetP == nullptr) {
        cout << "Playlist tidak ditemukan." << endl; 
        return;
    }
    if (targetP->info.pembuat != U->info.username) {
        cout << "Anda bukan pemilik playlist ini." << endl; 
        return;
    }

    addressRelasiLagu newRL = new elmRelasiLagu; 
    newRL->recLagu = P_Lagu; 
    newRL->next = nullptr; 
    newRL->prev = nullptr;
    if (targetP->listLagu.first == nullptr) {
        targetP->listLagu.first = newRL; 
        targetP->listLagu.last = newRL;
    }
    else {
        targetP->listLagu.last->next = newRL; 
        newRL->prev = targetP->listLagu.last; 
        targetP->listLagu.last = newRL;
    }
    cout << ">> Lagu berhasil ditambahkan." << endl;
}

void removeSongFromPlaylist(addressUser U, string namaPlaylist, string judulLagu) {
    addressRelasiPlaylist R_Play = U->listPlaylist.first;
    addressPlaylist targetP = nullptr;
    while (R_Play != nullptr) {
        if (R_Play->recPlaylist->info.namaPlaylist == namaPlaylist) {
            targetP = R_Play->recPlaylist; 
            break;
        }
        R_Play = R_Play->next;
    }
    if (!targetP || targetP->info.pembuat != U->info.username) {
        cout << "Akses ditolak." << endl; 
        return;
    }

    addressRelasiLagu R_Song = targetP->listLagu.first;
    while (R_Song != nullptr) {
        if (R_Song->recLagu->info.judul == judulLagu) {
            if (R_Song == targetP->listLagu.first && R_Song == targetP->listLagu.last) {
                targetP->listLagu.first = nullptr; 
                targetP->listLagu.last = nullptr;
            } else if (R_Song == targetP->listLagu.first) {
                targetP->listLagu.first = R_Song->next; 
                targetP->listLagu.first->prev = nullptr;
            } else if (R_Song == targetP->listLagu.last) {
                targetP->listLagu.last = R_Song->prev; 
                targetP->listLagu.last->next = nullptr;
            } else {
                R_Song->prev->next = R_Song->next; 
                R_Song->next->prev = R_Song->prev;
            }
            delete R_Song;
            cout << ">> Lagu dihapus dari playlist." << endl; 
            return;
        }
        R_Song = R_Song->next;
    }
    cout << ">> Lagu tidak ada di playlist." << endl;
}

void showPlaylistContent(addressPlaylist P) {
    if (P == nullptr) {
        return;
    }
    cout << "+----------------------------------------+" << endl;
    cout << "| Playlist: " << left << setw(27) << P->info.namaPlaylist << "|" << endl;
    cout << "+----------------------------------------+" << endl;
    addressRelasiLagu R = P->listLagu.first;
    if (R == nullptr) {
        cout << "| (Kosong)                               |" << endl;
    }
    int i = 1;
    while (R != nullptr) {
        cout << "| " << i++ << ". " << left << setw(20) << R->recLagu->info.judul << " (" << R->recLagu->info.durasi << ")    |" << endl;
        R = R->next;
    }
    cout << "+----------------------------------------+" << endl;
}

// Lagu
void createListLagu(ListLagu &L){
    L.first = nullptr;
    L.last = nullptr;
};
addressLagu createElmLagu(Lagu data){
    addressLagu P = new listLagu;
    P->info = data;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
};
void insertLastLagu(ListLagu &L, addressLagu P){
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
        P->next = P;
        P->prev = P;
    } else {
        P->prev = L.last;
        P->next = L.first;
        L.last->next = P;
        L.first->prev = P;
        L.last = P;
    }
};

void showAllLagu(ListLagu L){
    cout << "\n===== DAFTAR LAGU =====\n";
    addressLagu P = L.first;

    if (P == nullptr) {
        cout << "List lagu kosong!" << endl;
        return;
    }

    do {
        cout << "ID      : " << P->info.id << endl;
        cout << "Judul   : " << P->info.judul << endl;
        cout << "Penyanyi: " << P->info.penyanyi << endl;
        cout << "Durasi  : " << P->info.durasi << " detik" << endl;
        cout << "Genre   : " << P->info.genre << endl;
        cout << "------------------------\n";
        P = P->next;
    } while (P != L.first);
};

addressLagu searchLaguJudul(ListLagu L, string x){
    if (L.first == nullptr) {
        return nullptr;
    }
    
    addressLagu P = L.first;
    do {
        if (P->info.judul == x){
            return P;
        }
        P = P->next;
    } while (P != L.first);
    
    return nullptr;
}


void deleteLaguGlobal(ListLagu &L, ListPlaylist &LP, string judul){
    addressLagu P = searchLaguJudul(L, judul);
    if (P == nullptr) {
        cout << "Lagu tidak ditemukan" << endl;
        return;
    }

    // Hapus referensi dari playlist
    addressPlaylist P_Play = LP.first;
    while (P_Play != nullptr) {
        addressRelasiLagu R = P_Play->listLagu.first;
        while (R != nullptr) {
            addressRelasiLagu nextR = R->next;
            if (R->recLagu == P) {
                if (R == P_Play->listLagu.first && R == P_Play->listLagu.last) {
                    P_Play->listLagu.first = nullptr; 
                    P_Play->listLagu.last = nullptr;
                } else if (R == P_Play->listLagu.first) {
                    P_Play->listLagu.first = R->next; 
                    P_Play->listLagu.first->prev = nullptr;
                } else if (R == P_Play->listLagu.last) {
                    P_Play->listLagu.last = R->prev; 
                    P_Play->listLagu.last->next = nullptr;
                } else {
                    R->prev->next = R->next; 
                    R->next->prev = R->prev;
                }
                delete R;
            }
            R = nextR;
        }
        P_Play = P_Play->next;
    }
    // Hapus Lagu Global
    if (P == L.first && P == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        addressLagu Prec = P->prev;
        addressLagu NextNode = P->next;
        
        Prec->next = NextNode;
        NextNode->prev = Prec;

        if (P == L.first) {
            L.first = NextNode;
        }
        if (P == L.last) {
            L.last = Prec;
        }
    }
    delete P;
    cout << "Lagu berhasil dihapus total.\n";
}

void editLaguGlobal(string judulBaru, string penyanyiBaru, string durasiBaru, string genreBaru, addressLagu P) {
    if (P != nullptr) {
        P->info.judul = judulBaru; 
        P->info.penyanyi = penyanyiBaru;
        P->info.durasi = durasiBaru; 
        P->info.genre = genreBaru;
        cout << "Lagu berhasil diupdate!" << endl;
    }
}

addressLagu getNextLaguByGenre(addressLagu current, string genre) {
    if (current == nullptr) {
        return nullptr;
    }
    addressLagu P = current->next;
    // Cari ke depan sampai ketemu genre sama atau kembali ke diri sendiri
    while (P != current) {
        if (P->info.genre == genre) {
            return P;
        }
        P = P->next;
    }
    return nullptr; // Tidak ada lagu lain dengan genre sama
}

addressLagu getPrevLaguByGenre(addressLagu current, string genre) {
    if (current == nullptr) return nullptr;
    addressLagu P = current->prev;
    while (P != current) {
        if (P->info.genre == genre) {
            return P;
        }
        P = P->prev;
    }
    return nullptr;
}

// =======================
// IMPLEMENTASI ADMIN (SLL)
// =======================
void createListAdmin(ListAdmin &L) {
    L.first = nullptr;
}

addressAdmin createElmAdmin(Admin data) {
    addressAdmin P = new elmAdmin;
    P->info = data;
    P->next = nullptr;
    return P;
}

void insertLastAdmin(ListAdmin &L, addressAdmin P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        addressAdmin last = L.first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = P;
    }
}

addressAdmin searchAdmin(ListAdmin L, string username) {
    addressAdmin P = L.first;
    while (P != nullptr) {
        if (P->info.username == username) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// =======================
// IMPLEMENTASI USER (SLL)
// =======================
void createListUser(ListUser &L) {
    L.first = nullptr;
}

addressUser createElmUser(User data) {
    addressUser P = new elmUser;
    P->info = data;
    P->listPlaylist.first = nullptr;
    P->listPlaylist.last = nullptr;
    P->next = nullptr;
    return P;
}

void insertLastUser(ListUser &L, addressUser P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        addressUser last = L.first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = P;
    }
}

addressUser searchUser(ListUser L, string username) {
    addressUser P = L.first;
    while (P != nullptr) {
        if (P->info.username == username) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}