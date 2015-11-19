#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

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
    list_status lstatus;
};

struct list_akun {
    address_akun first;
};

void addAkun (list_akun &);
void findAkun (list_akun );
void editAkun (list_akun &);
void addStatus (list_akun &, list_status &);
void findStatus (list_akun , list_status);
address deleteStatus (list_akun &, list_status);
void viewStatus (list_akun, list_status);
address deleteAkun (list_akun &);
int count_akun (list_akun);
int count_status (list_akun,list_status);
void sort_akun (list_akun &);
void sort_status (list_status &);
void insertFirstStatus (list_status &);
void insertFirst
#endif //HEAD_H_INCLUDED
