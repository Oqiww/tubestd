#include "app.h"
#include "backend.h"
#include <iostream>
using namespace std;

// =======================
// IMPLEMENTASI Playlist (MLL)
// =======================
addressPlaylist createElmPlaylist(addressLagu L){
    addressPlaylist P = new elmPlaylist;
    P->lagu = L;
    P->next = nullptr;
    return P;
}

void addToPlaylist(addressUser U, addressLagu L) {
    if (!U || !L) return;

    addressPlaylist P = createElmPlaylist(L);

    if (U->info.firstPlaylist == nullptr) {
        U->info.firstPlaylist = P;
    } else {
        addressPlaylist Q = U->info.firstPlaylist;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }

    cout << "Lagu berhasil ditambahkan ke playlist " << U->info.username << endl;
}

void showPlaylist(addressUser U) {
    if (!U) {
        cout << "User tidak valid\n";
        return;
    }

    if (U->info.firstPlaylist == nullptr) {
        cout << "Playlist kosong\n";
        return;
    }

    addressPlaylist P = U->info.firstPlaylist;
    cout << "\n=== PLAYLIST " << U->info.username << " ===\n";
    while (P != nullptr) {
        cout << "- " << P->lagu->info.judul
             << " (" << P->lagu->info.penyanyi << ")\n";
        P = P->next;
    }
}

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
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
};

void showAllLagu(ListLagu L){
    cout << "\n===== DAFTAR LAGU =====\n";
    addressLagu P = L.first;

    if (P == nullptr) {
        cout << "List lagu kosong!\n";
        return;
    }

    while (P != nullptr) {
        cout << "ID      : " << P->info.id << endl;
        cout << "Judul   : " << P->info.judul << endl;
        cout << "Penyanyi: " << P->info.penyanyi << endl;
        cout << "Durasi  : " << P->info.durasi << " detik" << endl;
        cout << "Genre   : " << P->info.genre << endl;
        cout << "------------------------\n";
        P = P->next;
    }
};
addressLagu searchLaguJudul(ListLagu L, string x){
    addressLagu P;
    P = L.first;
    while (P != nullptr){
        if (P->info.judul == x){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
addressLagu searchLaguID(ListLagu L, int x){
    addressLagu P;
    P = L.first;
    while (P != nullptr){
        if (P->info.id == x){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}


void deleteLagu(ListLagu &L, string x){
    addressLagu Prec, q;
    q = searchLaguJudul(L, x);
    if (q){
        if (q == L.first && q == L.last){
            L.first = nullptr;
            L.last = nullptr;
        } else if (q == L.first){
            L.first = q->next;
            q->next = nullptr;
            L.first->prev = nullptr;
        }else if (q == L.last){
            L.last = L.last->prev;
            q->prev = nullptr;
            L.last->next = nullptr;
        }else{
            Prec = q->prev;
            Prec->next = q->next;
            q->next->prev = Prec;
            q->next = nullptr;
            q->prev = nullptr;

        }
        cout << "Lagu berhasil dihapus." << endl;
    }else{
        cout << "Lagu yang ingin anda hapus tidak ada di Spitipi" << endl;
    }

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
    P->info.firstPlaylist = nullptr;
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