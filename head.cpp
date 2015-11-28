#include "head.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;


/// Bagian Create List
void createListAkun(list_akun &Akun){
    Akun.first = NULL;
}

void createListStatus(list_status &Status){
    Status.first = NULL;
    Status.last = NULL;
}


/// Bagian menu
void menu_1(list_akun &Akun){
    infotype_akun detail_akun;

    cout<<"Masukkan id akun         : ";cin>>detail_akun.id_akun;
    cout<<"Masukkan nama anda       : ";cin>>detail_akun.nama;
    cout<<"Masukkan tgl lahir anda  : ";cin>>detail_akun.tgl_lahir;
    cout<<"Masukkan username anda   : ";cin>>detail_akun.username;
    cout<<"Masukkan password anda   : ";cin>>detail_akun.password;
    addAkun(Akun,detail_akun);
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
    if (pointer->lstatus.first == NULL){
        createListStatus(Status);
    }
    getch();
    while (berhasil){///tolong hubungin setiap akun yang masuk ke lstatus masing2
        cout<<"============ Menu Akun ============"<<endl
            <<"1. Tulis Status"<<endl
            <<"2. view All Status "<<endl
            <<"3. Edit Akun "<<endl
            <<"4. Delete Akun "<<endl
            <<"5. Delete Status "<<endl
            <<"6. Sort akun"<<endl
            <<"7. Log Out"<<endl
            <<"Pilihan Anda : ";cin>>menu_akun;
            switch (menu_akun){
            case 1:
                addStatus(pointer,Status);
                break;
            case 2:
                viewStatus(Akun,Status);
                break;
            case 3:
                editAkun(Akun);
                break;
            case 4:
                deleteAkun(Akun);
                berhasil=false;
                break;
            case 5:
                deleteStatus(Status);
                break;
            case 6:
                sort_status(Status);
                break;
            case 7:
                berhasil = false;
            }
    }
}

/// Bagian Akun
void addAkun(list_akun &Akun, infotype_akun detail_akun){
    address_akun new_akun = new elmakun;
    new_akun->info_akun = detail_akun;
    char pil;
    int after_id;

    cout<<"Apakah anda ingin memasukkan akun secara manual ? (Y/N)";cin>>pil;

    if (Akun.first == NULL && (pil != 'Y' || pil !='y')){
        insertFirstAkun(Akun, new_akun);
    }
    else {
        if (pil == 'Y' || pil == 'y'){///error juga
            address_akun next_pointer;

            cout<<"masukkan id akun yang ingin anda masukkan setelahnya : ";cin>>after_id;
            next_pointer = findAkun(Akun,after_id);
            cout<<next_pointer<<endl;
            insertNextAkun(Akun,new_akun,next_pointer);
        }
        else {
            insertLastAkun(Akun, new_akun);
        }
    }
    ///cout<<Akun.first->info_akun.tgl_lahir;
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

void insertNextAkun(list_akun &Akun, address_akun new_akun, address_akun next_pointer)
{
    new_akun->next = next_pointer->next;
    next_pointer->next = new_akun;
}

void deleteAkun(list_akun &Akun){
    address_akun pointer = Akun.first;
    address_akun will_delete;
    int delete_id;
    char pil;

    if (pointer == NULL){
        cout<<"Tidak ada account"<<endl;
    }
    else {
        cout<<"Masukkan id yang akan anda hapus : ";cin>>delete_id;
        if (delete_id == pointer->info_akun.id_akun){
            will_delete = deleteFirstAkun(Akun);
        }
        else {
            cout<<"Apakah anda ingin menghapus secara manual ? (Y/N) : ";cin>>pil;///masih error
            if (pil == 'y' || pil== 'Y'){
                int before_delete;

                cout<<"Masukkan id akun sebelum akun yang ingin anda hapus : ";cin>>before_delete;
                will_delete = deleteNextAkun(Akun,before_delete);
            }
            else {
                will_delete = findAkun(Akun,delete_id);
            }
        }
        delete will_delete;
    }
}

address_akun deleteFirstAkun(list_akun &Akun){
    address_akun P = Akun.first;

    Akun.first=Akun.first->next;
    P->next=NULL;
    cout<<"ID Akun yang dihapus "<<P->info_akun.id_akun<<endl;
    return P;

}

address_akun deleteLastAkun(list_akun &Akun){
    address_akun pointer, will_delete;
    pointer = Akun.first;

    if (pointer->next == NULL)
    {
        Akun.first = NULL;
        return pointer;
    }
    else
    {
        while( (pointer->next)->next != NULL)
        {
            pointer = pointer->next;
        }
        will_delete = pointer->next;
        will_delete->next = NULL;
        pointer->next = NULL;
        return pointer;
    }
}

address_akun deleteNextAkun(list_akun &Akun, int detail_akun){///masih error
    address_akun pointer = Akun.first; 

    if(pointer == NULL){
        cout<<"Akun kosong"<<endl;
        return NULL;
    }
    while(pointer != NULL)
     {
        if(pointer->info_akun.id_akun == detail_akun)
            {break;}
        pointer = pointer->next;
     }

     if(pointer->next == NULL){
        cout<<"Founded ID is the last account, nothing to delete!"<<endl;
     }
     else
     {
        address_akun will_delete = pointer->next;
        pointer->next = will_delete->next;
        will_delete->next = NULL;
        return will_delete;
     }
}

address_akun findAkun(list_akun Akun, int after_id){
    address_akun next_pointer = Akun.first;
        while (next_pointer != NULL){
            if (next_pointer->info_akun.id_akun == after_id){
                break;
            }
            next_pointer = next_pointer->next;
        }
    return next_pointer;
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
}

void viewAkun(list_akun Akun){
    address_akun Pointer;

    if (Akun.first == NULL)
    {
        cout<<"View Akun"<<endl;
        cout<<"Empty List Akun"<<endl;
    }
    else
    {
        cout<<"View Akun"<<endl;
        Pointer = Akun.first;
        while(Pointer != NULL)
        {
            cout<<"ID Akun  : "<<Pointer->info_akun.id_akun<<endl;
            cout<<"Nama     : "<<Pointer->info_akun.nama<<endl;
            cout<<"Tgl Lahir: "<<Pointer->info_akun.tgl_lahir<<endl;
            cout<<"Username : "<<Pointer->info_akun.username<<endl;
            cout<<"Password : "<<Pointer->info_akun.password<<endl;
            Pointer = Pointer->next;
        }
    }
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

/// Bagian status

void addStatus(address_akun pointer, list_status &Status){
    address_status pointer_status= Status.first;
    address_status new_status = new elmstatus;
    infotype_status detail_status;
    int after_id;char pil;

    cout<<"Masukkan id status   : ";cin>>detail_status.id_status;
    cout<<"Tulis Status         : ";cin>>detail_status.status;
    cout<<"Masukkan Tanggal     : ";cin>>detail_status.tanggal;
    new_status->info_status = detail_status;
    if (pointer_status== NULL){
        insertFirstStatus(Status,new_status);
    }
    else{
        cout<<"Apakah anda ingin memasukkan akun secara manual ? (Y/N)";cin>>pil;
        if (pil == 'Y' || pil == 'y'){
            cout<<"masukkan id status yang ingin anda masukkan setelahnya : ";cin>>after_id;
            while (pointer_status != NULL){
                if (pointer_status->info_status.id_status == after_id){
                    break;
                }
                pointer_status = pointer_status->next;
            }
            insertNextStatus(Status,new_status,pointer_status);
        }
        else {
            insertLastStatus(Status,new_status);
        }
    }
}

void insertFirstStatus(list_status &Status, address_status new_status){
    if (Status.first == NULL){
        Status.first = new_status;
        Status.last = new_status;
        new_status->next = NULL;
        new_status->prev = NULL;
    }
    else {
        new_status->next = Status.first;
        Status.first->prev = new_status;
        Status.first = new_status;
    }
}

void insertLastStatus(list_status &Status, address_status new_status){
    if (Status.first == NULL){
        insertFirstStatus(Status,new_status);
    }
    else {
        Status.last->next= new_status;
        new_status->prev = Status.last;
        Status.last = new_status;
    }
}

void insertNextStatus(list_status &Status, address_status new_status, address_status pointer_status){
    new_status->next = pointer_status->next;
    (pointer_status->next)->prev = new_status;
    pointer_status->next = new_status;
    new_status->prev = pointer_status;
}

void viewStatus(list_akun Akun, list_status Status){
    address_status pointer_status;

    if(Status.first == NULL)
    {
        cout<<"View Status"<<endl;
        cout<<"TIdak ada status"<<endl;
    }
    else
    {
        cout<<"View Status"<<endl;
        pointer_status = Status.first;
        while (pointer_status != NULL)
        {//string id_status, tanggal, status;
            cout<<"ID Status : "<<pointer_status->info_status.id_status<<endl;
            cout<<"Tanggal : "<<pointer_status->info_status.tanggal<<endl;
            cout<<"Status : "<<pointer_status->info_status.status<<endl;
            pointer_status = pointer_status->next;
        }
    }
}

void deleteStatus(list_status &Status){
    address_status pointer_first = Status.first;
    address_status pointer_last  = Status.last;
    string tanggal_hapus;
    char pilih_manual;
    address_status will_delete = NULL;

    cout<<"Masukkan tanggal status yang ingin anda hapus : ";cin>>tanggal_hapus;
    cout<<"Apakah anda ingin menghapus status secara manual ? (Y/N) : ";cin>>pilih_manual;
    if (pointer_first == NULL){
        cout<<"Tidak ada status "<<endl;
    }
    else {
        if ((pilih_manual == 'Y' || pilih_manual == 'y')){
            will_delete = deleteNextStatus(Status);
        }
        else if ((pointer_last->info_status.tanggal == tanggal_hapus) && (pointer_first->info_status.tanggal == tanggal_hapus)){
            will_delete = deleteFirstStatus(Status);
        }
        else if ((pointer_first != pointer_last) && (pointer_last->info_status.tanggal == tanggal_hapus)){
            will_delete = deleteFirstStatus(Status);
        }
        else {
            while (pointer_first != NULL){
                if (pointer_first->info_status.tanggal == tanggal_hapus){
                    will_delete = deleteFirstStatus(Status);
                    break;
                }
                pointer_first = pointer_first->next;
            }
        }
    }
    if (will_delete != NULL){
        cout<<"Status berhasil di hapus"<<endl;
        delete will_delete;
    }
}

address_status deleteFirstStatus(list_status &Status){
    address_status pointer = Status.first;

    Status.first = pointer->next;
    Status.first = NULL;
    pointer->next;
    return pointer;
}

address_status deleteLastStatus(list_status &Status){
    address_status P=Status.last;

    Status.last =Status.last->prev;
    P->prev =NULL;
    Status.last->next =NULL;
    cout<<"ID Status yang dihapus "<<P->info_status.id_status<<endl;
    return P;
}

address_status deleteNextStatus(list_status &Status){
    address_status pointer = Status.first;
    address_status will_delete;
    string tanggal_sebelum;

    cout<<"Masukkan tanggal status sebelum yang ingin anda hapus : ";cin>>tanggal_sebelum;
    while (pointer != NULL){
        if (pointer->info_status.tanggal == tanggal_sebelum)
            break;
    }

    will_delete = pointer->next;
    pointer->next = will_delete->next;
    (will_delete->next)->prev = pointer;
    will_delete->next = NULL;
    will_delete->prev = NULL;
    return will_delete;
}

address_status findStatus(list_status Status, string tanggal){
    address_status pointer_status = Status.first;

    while (pointer_status != NULL){
        if (pointer_status->info_status.tanggal == tanggal)
            break;
    }
    return pointer_status;
}

void sort_status(list_status &Status){

}

int count_status(list_status &Status){
    address_status pointer_status = Status.first;

    while (pointer_status != NULL){
        cout<<"Status : "<<pointer_status->info_status.status<<endl;
        cout<<"Tanggal: "<<pointer_status->info_status.tanggal<<endl<<endl;
    }
}
