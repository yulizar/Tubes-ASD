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
    string tanggal, status;
    int id_status;
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

void createListAkun (list_akun &);///done
void createListStatus (list_status &);///done
void addAkun (list_akun &, infotype_akun);///done
address_akun findAkun (list_akun , int);///done
void editAkun (list_akun &);///done
void addStatus (address_akun , list_status &);
address_status findStatus (list_status ,string);///done
void viewAkun(list_akun);///done
void viewStatus (list_akun, list_status);///done
int count_akun (list_akun);
int count_status (list_status);
void sort_akun (list_akun &);
void sort_status (list_status &);

void insertFirstStatus (list_status &,address_status);///done
void insertNextStatus (list_status &, address_status, address_status);///done
void insertLastStatus (list_status &, address_status);///done
address_status deleteLastStatus (list_status &);
address_status deleteFirstStatus (list_status &);
address_status deleteNextStatus (list_status &);
void deleteStatus (list_status &);


void insertFirstAkun (list_akun &, address_akun);///done
void insertNextAkun  (list_akun &, address_akun,address_akun);///done
void insertLastAkun  (list_akun &, address_akun);///done
address_akun deleteFirstAkun (list_akun &);///done
address_akun deleteNextAkun (list_akun &, int);///done
address_akun deleteLastAkun (list_akun &);///done
void deleteAkun (list_akun &);///done
#endif //HEAD_H_INCLUDED
