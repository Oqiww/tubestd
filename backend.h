#ifndef BACKEND_H
#define BACKEND_H
#include <iostream>
using namespace std;

// Pointerk ke listLagu
typedef struct listLagu *addressLagu;

// Struct untuk menyimpan lagu
struct Lagu {
    int id;
    string judul, penyanyi;
    string durasi;
    string genre;
};

struct listLagu {
    Lagu info;
    addressLagu next;
    addressLagu prev;
};

struct ListLagu{
    addressLagu first;
    addressLagu last;
};

void createListLagu(ListLagu &L);
addressLagu createElmLagu(Lagu data);
void insertLastLagu(ListLagu &L, addressLagu P);
void showAllLagu(ListLagu L);
addressLagu searchLaguJudul(ListLagu L, string x);
addressLagu searchLaguID(ListLagu L, int x);
void deleteLagu(ListLagu &L, string x);


#endif
