//isi source code nya disini yo
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
    address Q;
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
void insertFirstStatus (list_status &S);
