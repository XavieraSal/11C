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

void insertCus(address* L, infotype X) { 

	address P;
	
	P = Alokasi (X);
	if (P != Nil)
	{
		Insertlastcust(&(*L), P); }
}

void PrintA(antrean c)
{

	address H;
	int i=1;

	if (c.head == Nil)
	{
		 printf ("queue Kosong .... \a\n");
	}
	else
	{
		 H = c.head;
		 for (;;)
		 {
		if (H == Nil)
		{
			 printf("\n");
			 break;
		}
		else
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
	
	address Last;
	
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

void deleteCus(antrean *q, address *delNode) {
    if (cekKosong(*q)) {
        printf("Antrean kosong!\n");
    } else {
        *delNode = q->head;
        q->head = (*delNode)->next;
        if (q->head == NULL) {
            q->tail = NULL;
        } else {
            q->head->prev = NULL;
        }
    }
}
