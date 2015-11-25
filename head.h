#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info_akun(P) P->info
#define info_status(P) P->info


struct infotype_akun {
    string id_akun,nama,tgl_lahir,username,password;
};

struct infotype_status {
    string id_status, tanggal, status;
};
typedef struct elmakun *address_akun;
typedef struct elmstatus *address_status;

struct elmstatus {
    infotype_status info_status;
    address_status next;
    address_status prev;
};

struct list_status {
    address_status first;
    address_status last;
};

struct elmakun {
    infotype_akun info_akun;
    address_akun next;
    address_akun prev;
    list_status lstatus;
};

struct list_akun {
    address_akun first;
};

void addAkun (list_akun &A);
address_akun alokasi_akun (infotype_akun x);
void findAkun (list_akun A);
void editAkun (list_akun &A);
void addStatus (list_akun &A, list_status &S);
void findStatus (list_akun A, list_status L);
address_status deleteStatus (list_akun &A, list_status S);
void viewStatus (list_akun A, list_status S);
address_akun deleteAkun (list_akun &A);
int count_akun (list_akun A);
int count_status (list_akun A,list_status S);
void sort_akun (list_akun &A);
void sort_status (list_status &S);
void insertFirstAkun (list_akun &A, address_akun P);
void insertFirstStatus (list_status &S);
void deletefirst_akun(list_akun &A,address_akun P);
void deleteLast_status(list_status &S,address_status *P);
#endif // HEAD_H_INCLUDED
