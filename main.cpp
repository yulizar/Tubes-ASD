#include <iostream>
#include "head.h"
using namespace std;

int main()
{
    list_akun Akun;
    list_status Status;
    int pilih_menu=0;
    bool home = true;

    createListAkun(Akun);
    /*std::vector<int> x(10);
    std::iota(std::begin(x), std::end(x), 0); //0 is the starting number
    *////-> Buat nentuin range
    while (home){
        cout<<"============== WELCOME TO BOOKFACE ==============="<<endl<<endl
            <<"MENU :"<<endl
            <<"1. Make Account "<<endl
            <<"2. Log In "<<endl
            <<"3. view Akun "<<endl
            <<"4. Count Akun "<<endl
            <<"5. Exit"<<endl<<endl
            <<"Pilihan Anda : ";cin>>pilih_menu;
        system("cls");
            switch (pilih_menu){
            case 1:
                menu_1(Akun);
                system("cls");
                break;
            case 2:
                menu_2(Akun,Status);
                system("cls");
                break;
            case 3:
                viewAkun(Akun);
                getch();
                system("cls");
                break;
            case 4:
                cout<<"Akun yang terdaftar ada :"<<count_akun(Akun)<<" akun";
                getch();
                system("cls");
                break;
            case 5:
                home = false;
                break;
            default: break;
            }
    }
    return 0;
}
