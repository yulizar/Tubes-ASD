#include "head.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

// Bagian menu
void menu_1(list_akun &Akun){
    infotype_akun detail_akun;

    detail_akun.id_akun=1;
    cout<<"Masukkan nama anda       : ";cin>>detail_akun.nama;
    cout<<"Masukkan tgl lahir anda  : ";cin>>detail_akun.tgl_lahir;
    cout<<"Masukkan usernam anda    : ";cin>>detail_akun.username;
    cout<<"Masukkan password anda   : ";cin>>detail_akun.password;
    addAkun(Akun, detail_akun);
}

void menu_2(list_akun &Akun, list_status &Status){
    string uname, pass;
    address_akun pointer = Akun.first;
    bool berhasil = false;
    int menu_akun = 0;


    cout<<"Masukkan username anda : ";cin>>uname;
    cout<<"Masukkan password anda : ";cin>>pass;
    while (pointer != NULL){
        if (uname == pointer->info_akun.username && pass== pointer->info_akun.password){
            cout<<"Berhasil Log In"<<endl;
            berhasil = true;
            break;
        }
        pointer = pointer->next;
    }
    if (berhasil == false ){
        cout<<"Akun tidak terdaftar/ username salah"<<endl;
    }
    getch();
    while (berhasil){
        cout<<"============ Menu Akun ============"<<endl
            <<"1. Tulis Status"<<endl
            <<"2. view All Status "<<endl
            <<"3. Edit Akun "<<endl
            <<"4. Log Out"<<endl
            <<"Pilihan Anda : ";cin>>menu_akun;
            switch (menu_akun){
            case 1:
                addStatus(Akun,Status);
                break;
            case 2:
                viewStatus(Akun,Status);
                break;
            case 3:
                editAkun(Akun);
                break;
            case 4:
                berhasil = false;
            }
    }
}

// Bagian Create List
void createListAkun(list_akun &Akun){
    Akun.first = NULL;
}

void createListStatus(list_status &Status){
    Status.first = NULL;
    Status.last = NULL;
}

// Bagian Akun
void addAkun(list_akun &Akun, infotype_akun detail_akun){
    address_akun new_akun = new elmakun;
    new_akun->info_akun = detail_akun;
    if (Akun.first == NULL){
        insertFirstAkun(Akun, new_akun);
    }
    else {
        insertLastAkun(Akun, new_akun);
    }
    //cout<<Akun.first->info_akun.tgl_lahir;
}

void insertFirstAkun(list_akun &Akun, address_akun new_akun){
    Akun.first = new_akun;
    new_akun->next = NULL;
}

void insertLastAkun(list_akun &Akun, address_akun new_akun){
    address_akun P = Akun.first;
    while (P->next != NULL){
        P = P->next;
    }
    P->next = new_akun;
}

void insertNextAkun(list_akun &Akun,address_akun Pointer, infotype_akun detail_akun){

}

address_akun deleteAkun(list_akun &Akun){

}

address_akun deleteFirstAkun(list_akun &Akun){
    address_akun P = Akun.first;

    if(P == NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else
    {
        Akun.first=Akun.first->next;
        P->next=NULL;
        cout<<"ID Akun yang dihapus "<<P->info_akun.id_akun<<endl;
        return P;
    }
}

address_akun deleteLastAkun (list_akun &A, elmakun &P)
{
    elmakun &Q;
    if (A.first == NULL)
    {
        cout<<"There is no data to delete!"<<endl;
    }
    else
    {
        Q = A.first;
        if (Q->next == NULL)
        {
            delete q;
            A.first = NULL;
        }
        else
        {
            while( (Q->next)->next != NULL)
            {
                Q = Q->next;
            }
            P = Q->next;
            P->next = NULL;
            Q->next = NULL;
            delete p;
        }
        cout<<endl<<"Delete Last Data Success!"<<endl;
    }
}

address_akun deleteNextAkun(list_akun &Akun, infotype_akun detail_akun){
    elmakun q = Akun.first;

    while(q != NULL)
     {
        if(q->info_akun.id_akun == detail_akun.id_akun)
            break;
        else
            q = q->next;
     }
     if(q == NULL)
        cout<<"ID not found!"<<endl;
     else if(q->next == NULL)
        cout<<"Founded ID is the last account, nothing to delete!"<<endl;
     else
     {
        elmakun r = next(q);
        next(q) = next(r);
        next(r) = NULL;
        delete r;
        cout<<"Delete Success!";
     }
}

void editAkun(list_akun &Akun){
    int cari;
    address_akun Pointer = Akun.first;
    cout<<"Masukkan id akun yang ingin anda cari ";cin>>cari;
    while (Pointer != NULL){
        if (cari == Pointer->info_akun.id_akun){
            cout<<"Data ada !"<<endl;
            cout<<"Masukkan nama anda : ";cin>>Pointer->info_akun.nama;
            cout<<"Masukkan tanggal lahir anda : ";cin>>Pointer->info_akun.tgl_lahir;
            cout<<"Masukkan username baru : ";cin>>Pointer->info_akun.username;
            cout<<"Masukkan password baru : ";cin>>Pointer->info_akun.password;
            break;
        }
        Pointer = Pointer->next;
    }
    cout<<"Data tidak ditemukan !!"<<endl<<endl;
}

void sort_akun(list_akun &Akun){
    address_akun pointer = Akun.first;
    address_akun next_point = Akun.first->next;
    int min_id;

    while (pointer != NULL){

    }
}


int count_akun(list_akun Akun){
    address_akun Pointer = Akun.first;
    int jumlah=0;

    while (Pointer != NULL){
        jumlah++;
        Pointer = Pointer->next;
    }
    return jumlah;
}

// Bagian status

void addStatus(list_akun &Akun, list_status &Status){

}

void insertFirstStatus (list_status &S, elmstatus &P)
{
    if(S.first == NULL)
    {
        S.first = P;
        S.last = P;
    }
    else
    {
        P->next = S.first;
        (P->next)->prev = P;
        S.first = P;
    }
}

void viewStatus(list_akun Akun, list_status Status){
    //viewakun
    elmakun P;
    if (Akun.first == NULL)
    {
        cout<<"View Akun"<<endl;
        cout<<"Empty List Akun"<<endl;
    }
    else
    { //string id_akun,nama,tgl_lahir,username,password
        cout<<"View Akun"<<endl;
        P = Akun.first;
        while(P != NULL)
        {
            cout<<"ID Akun : "<<P->info_akun.id_akun<<endl;
            cout<<"Nama : "<<P->info_akun.nama<<endl;
            cout<<"Tgl Lahir : "<<P->info_akun.tgl_lahir<<endl;
            cout<<"Username : "<<P->info_akun.username<<endl;
            cout<<"Password : "<<P->info_akun.password<<endl;
            P = P->next;
        }
    }

    //viewstatus
    elmstatus P;
    if(Status.first == NULL)
    {
        cout<<"View Status"<<endl;
        cout<<"Empty List Status"<<endl;
    }
    else
    {
        cout<<"View Status"<<endl;
        P = Status.first;
        while (P != NULL)
        {//string id_status, tanggal, status;
            cout<<"ID Status : "<<P->info_status.id_status<<endl;
            cout<<"Tanggal : "<<P->info_status.tanggal<<endl;
            cout<<"Status : "<<P->info_status.status<<endl;
            P = P->next;
        }
    }

}

void findStatus(list_status S, string tanggal){

}

void sort_status(list_status &Status){

}

address_status deleteLastStatus(list_status &Status){
    address_status P=Status.last;

    Status.last =Status.last->prev;
    P->prev =NULL;
    Status.last->next =NULL;
    cout<<"ID Status yang dihapus "<<P->info_status.id_status<<endl;
    return P;
}


//START BAGIAN PRIMA ANANDA
void insertNextAkun(list_akun &A, address_akun P, address_akun prec)
{
    if (first(A) == NULL){
        insertFirstAkun(A, P); ///tolong buatin dan samain prosedurnya
    }
    else {
        address_akun current = first(A);
        while(current != NULL) {
            if(current == prec) {
                if(next(current) == NULL) {
                    insertLastAkun(A, P); ///tolong buatin dan samain prosedurnya
                } else {
                    next(P) = next(current);
                    next(current) = P;
                    prev(next(P)) = P;
                    prev(P) = current;
                }
                break;
            }
            current = next(current);
        }
    }
}

void insertNextStatus(list_status &S, address_akun Q, address_status P, address_status prec) {
    ///pertama dicek apakah list akun kosong atau tidak
    if(first(S) != NULL) {
        address_akun induk = find_element(S, info_akun(Q)); ///buat dong fungsi atau prosedur find elemen ///masih eror
        /// ngecek list anak kosong apa nggak
        if(induk->lstatus) { ///masih eror
            insertFirstStatus(S, Q, P); ///masih eror voidnya belum ada
        } else {
            address_status current = first(induk->lstatus);
            while(current != NULL) {
                if(current == prec) {
                    /// menentukan apakah current merupakan elemen terakhir atau bukan
                    if(next(current) == NULL) {
                        insertLastStatus(S, Q, P); ///masih eror voidnya belum ada
                    } else {
                        next(P) = next(current);
                        next(current) = P;
                        prev(next(P)) = P;
                        prev(P) = current;
                    }
                    break;
                }
                current = next(current);
            }
        }
    }
}

void deleteFirstStatus(list_status &S, address_akun P, address_status Q){
    /// cek apakah list akun kosong atau tidak
    if(first(S) != NULL) {
        address_akun induk = find_element(S, info_akun(P)); ///buat dong fungsi atau prosedur find elemen ///masih eror;
        /// cek apakah list status kosong atau tidak
        if(first(induk->ltatus)) { ///masih eror
            /// cek apa ada satu elemen di status
            if(next(first(induk->lstatus)) == NULL) {
                first(induk->lstatus) = NULL;
                last(induk->lstatus) = NULL;
            } else {
                Q = first(induk->lstatus); ///masih eror
                first(induk->lstatus) = next(first(induk->lstatus));
                next(Q) = NULL; ///masih eror
                prev(first(induk->lstatus)) = NULL;
            }
        }
    }
}

void deleteLastStatus(list_status &S, address_akun P, address_status Q) {
    /// cek apakah list akun kosong atau tidak
    if(first(S) != NULL) {
        address_akun induk = find_element(S, info_akun(P)); ///buat dong fungsi atau prosedur find elemen ///masih eror;
        /// cek apakah list status kosong atau tidak
        if(first(induk->ltatus)) { ///masih eror
            /// cek apa ada satu elemen di status
            if(next(first(induk->lstatus)) == NULL) {
                deleteLastStatus(S, P, Q);
            } else {
                Q = last(induk->lstatus); ///masih eror
                last(induk->lstatus) = prev(Q);
                prev(Q) = NULL; ///masih eror
                next(last(induk->lstatus)) = NULL;
            }
        }
    }
}

void akundanStatus(list_status &S, list_akun &A){
    if(first(S) != NULL) {
        return 0;
        ///masih bingung
    }
}

void deleteLastAkun(list_akun &A, address_akun P) {
    if(first(A) != NULL) {
        address_akun current = first(A);
        if(next(current) == NULL) {
            deletefirst_akun(&A, P); ///MASIH ERROR
        } else {
            P = first(A);
            first(A) = prev(P);
            next(first(A)) = NULL;
            prev(P) = NULL;
        }
    }
}

///END PRIMA ANANDA
