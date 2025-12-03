#include "app.h"
#include "backend.h"
#include <iostream>
using namespace std;

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


void deleteLagu(ListLagu &L, addressLagu P, string x){
    addressLagu Prec, q;
    q = searchLagu(L,x);
    if (q){
        if (q == L.first && q == L.last){
            L.first = nullptr;
            L.last = nullptr;
        } else if (q == L.first){
            q = L.first;
            L.first = q->next;
            q->next = nullptr;
            L.first->prev = nullptr;
        }else if (q == L.last){
            q = L.last;
            L.last = L.last->prev;
            q->prev = nullptr;
            L.last->next = nullptr;
        }else{
            Prec = q->prev;
            q = Prec->next;
            Prec->next = q->next;
            q->next->prev = Prec;
            q->next = nullptr;
            q->prev = nullptr;

        }
    }else{
        cout << "Lagu yang ingin anda hapus tidak ada di Spitipi" << endl;
    }

}