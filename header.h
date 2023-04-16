#ifndef header_H
#define header_H
//#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Nil NULL


typedef const char* infotype;
typedef int infotype1;
typedef struct std *address_studio;
typedef struct node_cus *address;
typedef struct node_cus {
	address prev;
	infotype nm_cus;
	address_studio cus_std;
	address next;
} customer;

typedef struct std {
	address_studio bwh_st;
	infotype studio;
	address_studio next_st;
} studio;

typedef struct queue {
	address head;
	address tail;
} antrean;

address Alokasi (infotype X, int n);
int cekKosong (antrean q);
void bikinQ(antrean *q);
void insertCus(antrean *q, infotype X, int n);
void asc (address J);

#endif
