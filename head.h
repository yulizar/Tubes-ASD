#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct infotype_akun {
    string nama,tgl_lahir,username,password;
    int id_akun;
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

void menu_1(list_akun &);
void menu_2(list_akun &, list_status &);

void createListAkun (list_akun &);
void createListStatus (list_status &);
void addAkun (list_akun &, infotype_akun);
void findAkun (list_akun );
void editAkun (list_akun &);
void addStatus (list_akun &, list_status &);
void findStatus (list_status ,string);
void viewStatus (list_akun, list_status);
int count_akun (list_akun);
int count_status (list_akun,list_status);
void sort_akun (list_akun &);
void sort_status (list_status &);

void insertFirstStatus (list_status &);
void insertNextStatus (list_status &);
void insertLastStatus (list_status &);
address_status deleteLastStatus (list_status &);
address_status deleteFirstStatus (list_status &);
address_status deleteNextStatus (list_status &, infotype_status);
address_status deleteStatus (list_akun &, list_status);


void insertFirstAkun (list_akun &, address_akun);
void insertNextAkun  (list_akun &, address_akun, infotype_akun);
void insertLastAkun  (list_akun &, address_akun);
address_akun deleteFirstAkun (list_akun &);
address_akun deleteNextAkun (list_akun &, infotype_akun);
address_akun deleteLastAkun (list_akun &);
address_akun deleteAkun (list_akun &);
#endif //HEAD_H_INCLUDED
