#include "header.h"

/*Algoritma meng-alokasikan node */
address Alokasi (infokata X) {
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

void insertCus(address* L, infokata X) { 

	address P;
	
	P = Alokasi (X);
	if (P != Nil)
	{
		Insertlastcust(&(*L), P); }
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


address searchNode(address L, infokata nm) {
    int found = 0;
    address P = L;
    
    while (P != Nil && found == 0)
    {
        if (strcmp(P->nm_cus, nm) == 0)
        {
            found = 1;
        }
        else
        {
            P = P->next;
        }
    }
    
    if (found == 0)
    {
        printf("%s tidak ada dalam antrean\n", nm);
        return Nil;
    }
    else
    {
        return P;
    }
}

bool isAvailable(address_Seat seat) {
    return seat->info_seat == NULL;
}

address_Seat createSeats(int row, int col) {
    char ch = 'A';
    int num = 1;
    int i,j;
    address_Seat new_seat;

    address_Seat curr_seat = NULL;
    address_Seat prev_seat = NULL;

    for (i = 0; i < row; i++) {
        curr_seat = NULL;
        for (j = 0; j < col; j++) {
            new_seat = (address_Seat) malloc(sizeof(Seat));
            new_seat->info_seat = NULL;
            new_seat->next_seat = NULL;

            if (curr_seat == NULL) {
                curr_seat = new_seat;
                prev_seat = new_seat;
            } else {
                prev_seat->next_seat = new_seat;
                prev_seat = new_seat;
            }

            num++;
            printf(" %s", new_seat);
        }
        ch++;
        num = 1;
        printf(" %s", curr_seat);
    }

    return curr_seat;
}

void displayAvailableSeats(address_Seat curr_seat) {
    printf("Available seats:\n");
    address_Seat ptr = curr_seat;
    while (ptr != NULL) {
        if (isAvailable(ptr)) {
            printf("%s ", ptr->info_seat);
        }
        ptr = ptr->next_seat;
    }
    printf("\n");
}

