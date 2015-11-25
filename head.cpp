#include "head.h"

void addAkun (list_akun &A)
{
    first(A)=NULL;
}

address_akun alokasi_akun (infotype_akun x)
{

    address_akun A = new elmakun;
    A->info_akun= x;
    next(A) = NULL;
    prev(A) = NULL;
    return A;
}
void insertFirstAkun (list_akun &A, address_akun P)
{
    {
    if(first(A)==NULL)
    {

        first(A)=P;
        next(first(A))=NULL;
        next(P)=first(A);
    }
    else
    {
        next(P)=NULL;
        first(A)=P;
    }
    }
}

void insertLastAkun (list_akun &A, address_akun P)
{
    address_akun Q;
    Q=first(A);
    if(Q==NULL)
    {
        first(A)=P;
        next(first(A))=NULL;
    }
    else
    {
        while(next(Q)!=NULL)
        {
            Q=next(Q);
        }
        next(P)=NULL;
        next(Q)=P;
    }
}

void addStatus (list_status &S)
{
    first(S)=NULL;
    last(S)=NULL;
}

void deletefirst_akun(list_akun &A,address_akun &P)
{

    P=first(A);
    if(P==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else
    {
        first(A)=next(first(A));
        next(P)=NULL;
        cout<<"ID Akun yang dihapus "<<info_akun(P).id_akun<<endl;
    }
}

void deleteLast_status(list_status &S,address_status *P)
{
    P=last(S);
    last(S)=prev(last(S));
    prev(P)=NULL;
    next(last(S))=NULL;
    cout<<"ID Status yang dihapus "<<info_status(P).id_status<<endl;
}
