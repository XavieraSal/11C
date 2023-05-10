#include "header_arya.h"

address_studio sStudio (infotype1 j) {
	address_studio A = (address_studio)malloc(sizeof(studio));
	if (A != Nil) {
		A->studio = j;
		A->filmm = Nil;
		A->next_st = Nil;
	}
	
	return A;
}

address_loket alokasiLoket (infotype1 j, address_studio stud) {
	address_loket L;
	L = (address_loket)malloc(sizeof(Loket));
	if (L != Nil) {
		L->bwh_studio = stud;
		L->loket = j;
		L->lkt_cus = Nil;
		L->next_loket = Nil;
	}
	return L;
}

address_loket Locket (infotype1 j, address_studio stud) {
	address_loket L, R;
	R = L;
	for (int i; i < 3; i++) {
		while (R != Nil) {
			R = R->next_loket;
		}
		R = alokasiLoket(j, stud);	
	}
	R->next_loket = L;
	// menambahkan node kedua yang menunjuk ke node pertama
	address_loket temp;
	temp->bwh_studio = ;
	if (temp == Nil) {
		/* jika studio belum memiliki loket, maka loket pertama dan kedua
		   akan menunjuk ke dirinya sendiri */
		stud->next_st = L;
		L->next_loket = L;
	} else {
		/* jika studio sudah memiliki loket, maka loket kedua akan
		   menunjuk ke loket pertama dan loket terakhir (sebelum node baru)
		   akan menunjuk ke node baru */
		while (temp->next_loket != stud->next_st) {
			temp = temp->next_loket;
		}
		temp->next_loket = L;
		L->next_loket = stud->next_st;
	}
	return L;
}

//	if (K != Nil) {
//		while(K!=Nil) {
//			K = K->next_loket;
//		}
//		L = K;
//	}

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
			P->cus_std[i]->next_st = Nil;
			P->cus_std[i]->studio = 0;
			P->cus_std[i]->filmm = Nil;
		}
	} else {
		printf("Alokasi gagal");
	}
	return(P);
}

address_film movie(infotype nama, infotype2 jam[3]) {
	address_film f;
	f = (address_film)malloc(sizeof(Film));
	if (f != Nil) {
		f->nm_film = nama;
		for (int i = 0; i < 3; i++) {
			f->jm_tyg[i] = jam[i];
		}
		f->bwh_se = Nil;
		f->next_fl = Nil;
	} else {
		printf("Alokasi gagal");
	}
	return(f);
}

address_studio add_studio(address_studio first) {
//	infotype1 nomor_studio[] = {1, 2, 3};
	int i;
	for (i = 0; i < 3; i++) {
		address_studio s = sStudio(i+1);
		if (s != Nil) {
			if (first == Nil) {
				first = s;
			} else {
				address_studio last = first;
				while (last->next_st != Nil) {
					last = last->next_st;
				}
				last->next_st = s;
			}
		}
	}
	return first;
}


void add_film(address_film *first, address_film *now) {
	infotype nama_film[] = {"The Batman", "Dune", "Barbie"};
	infotype2 jam_tayang[][3] = {{10.00, 13.00, 16.00}, {11.00, 14.00, 17.00}, {12.00, 15.00, 18.00}};
	int i;
	for (i = 0; i < 3; i++) {
		address_film f = movie(nama_film[i], jam_tayang[i]);
		if (f != Nil) {
			if (*first == Nil) {
				*first = f;
				*now = *first;
			} else {

				(*now)->next_fl = f;
				*now = f;
			}
		}
	}
}

void print_film(address_film current) {
	printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
	printf("\t\t\t\xB3%12s\xB3%24s\xB3%24s\xB3%12s\xB3\n", "   Studio   ", "     Nama Film      ", "Jam         ", "   Harga   ");
	printf("\t\t\t\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n");
	int i = 1;
	address_studio first = Nil;
	if (first == Nil) {
		for (i = 1; i <= 1; i++) {
			first = add_studio(first);
		}
	}
	while (current != Nil) {
		printf("\t\t\t\xB3%12d\xB3%24s\xB3", first->studio, current->nm_film);
		for (int j = 0; j < 3; j++) {
			printf("%-8.2f", current->jm_tyg[j]);
		}
		printf("\xB3%12s\xB3\n", "  45.000   ");
		first = first->next_st;
		current = current->next_fl;
	}
	printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
}

void display_studio(address_studio head) {
	address_studio p = head;
	while (p != Nil) {
		printf("%d\n", p->studio);
		p = p->next_st;
	}
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
	if (P != Nil) {
		Insertlastcust(&(*L), P);
	}
}

//modul yang aku tambahin
void PrintA(antrean c) {
	/* Kamus Lokal */
	address H;
	int i=1;
	/* Algoritma */
	if (c.head == Nil) {
		printf ("queue Kosong .... \a\n");
	} else {	/* queue memiliki elemen */
		H = c.head;
		for (;;) {
			if (H == Nil) {
				printf("\n");
				break;
			} else {	/* Belum berada di akhir queue */
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
	while(b.head != Nil) {
		printf("%s \t", b.head);
		while (b.head->next != Nil) {
			printf("%s",b.head->next);
			b.head->next = b.head->next->next;
		}
		printf("\n");
	}
}

void Insertlastcust (address* L, address H) {
	/* Kamus Lokal */
	address Last;
	/* Algoritma */
	if ((*L) != Nil) {
		Last = (*L);
		while (Last->next != Nil) {
			Last = Last->next;
		}
		Last->next = H;
	} else {
		(*L) = H;
	}
}