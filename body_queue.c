#include "header_utama.h"


address Alokasi (infotype X) {
	int i;
    address P;
    P = (address)malloc(sizeof(customer));
    if (P != Nil) {
        P->prev = Nil;
        P->nm_cus = X;
        P->next = Nil;
        // alokasi memori untuk array of pointers
        for ( i = 0; i < 10; i++) {
            P->cus_std[i] = (address_studio)malloc(sizeof(studio));
            P->cus_std[i]->bwh_st = Nil;
            P->cus_std[i]->studio = "";
            P->cus_std[i]->next_st = Nil;
        }
    } else {
        printf("Alokasi gagal");
    }
    return(P);
}

int cekKosong (antrean q) {
	int k;
	k = q.head == Nil && q.tail == Nil;
	return (k);
}
void bikinQ(antrean *q) {
	q->head = Nil;
	q->tail = Nil;
}

void insertCus(address* L, infotype X) { //aku ubah parameter antrean jadi address.

	address P;
	
	P = Alokasi (X); //parameter integer aku hapus soalnya kamu deklar tapi ga dipake
	if (P != Nil)
	{
		Insertlastcust(&(*L), P); }
}

//modul yang aku tambahin
void PrintA(antrean c)
{
	/* Kamus Lokal */
	address H;
	int i=1;
	/* Algoritma */
	if (c.head == Nil)
	{
		 printf ("queue Kosong .... \a\n");
	}
	else	/* queue memiliki elemen */
	{
		 H = c.head;
		 for (;;)
		 {
		if (H == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir queue */
		{
			 printf ("%d. %s \n",i, H);
			 H = H->next;
			 i++;
		}
		 }
	}
}

void PrintB(antrean b)

{
	printf("QUEUE\n");
	while(b.head != Nil)
	{
		printf("%s \t", b.head);
		while (b.head->next != Nil)
		{
			printf("%s",b.head->next);
			b.head->next = b.head->next->next;
		}
		printf("\n");
	}
}

void Insertlastcust (address* L, address H)

{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	if ((*L) != Nil)
	{
		 Last = (*L);
		 while (Last->next != Nil)
		 {
		 	Last = Last->next;
		 }
		 Last->next = H;
 	}
	else
	{
		(*L) = H;
	}
}
