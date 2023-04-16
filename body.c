#include "header.h"

address Alokasi (infotype X, int n) {
	address P;
	P = (address)malloc(sizeof(customer));
	if (P != Nil) {
		P->prev = Nil;
		P->nm_cus = X;
		P->cus_std = Nil;
		P->next = Nil;
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

void insertCus(antrean *q, infotype X, int n) {
	address P;
	P = Alokasi (X, n);
	if (P != Nil) {
		if (cekKosong(*q)) {
			q->head = P;
		} else {
			q->tail->next = P;
			P->prev = q->tail;
		}
		q->tail = P;
	} else {
		printf("Proses memasukkan customer gagal!");
	}
}

void asc (address J) {
	while (J != Nil) {
		printf("%s", J->nm_cus);
		J = J->next;
	}
}