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