#ifndef arya_H
#define arya_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include "xaviera.h"

#define Nil NULL

typedef const char* infotype;
typedef int infotype1;
typedef float infotype2;

typedef struct seat *address_Seat;
typedef struct seat {
	infotype info_seat;
	address_Seat next_seat;
} Seat;

typedef struct film *address_film;
typedef struct film {
	infotype nm_film;
	infotype2 jm_tyg[3];
	address_Seat bwh_se;
	address_film next_fl;
} Film;

typedef struct stud *address_studio;
typedef struct stud {
	address_studio next_st;
	infotype1 studio;
	address_film next_fl;
} studio;

typedef struct node_cus *address;
typedef struct node_cus {
	infotype nm_cus;
	address prev;
	address_studio cus_std[10];
	address next;
} customer;

typedef struct queue {
	address head;
	address tail;
} antrean;

address First;
address Last;

typedef struct lkt *address_loket;
typedef struct lkt {
	address_studio bwh_studio;
	address_loket next_loket;
	infotype1 loket;
	address lkt_cus;
} Loket;


address_studio sStudio (infotype1 j, address_film mov);
address_loket alokasiLoket (infotype1 j, address_studio stud, address cust);
address_loket Locket (infotype1 j, address_studio stud, address cust);
address_film movie(infotype nama, infotype2 jam[3]);
address_studio add_studio(address_studio first);
void add_film(address_film *first, address_film *now);
void addPrintFilm(address_film *head, address_film *now);
void print_film(address_film current);
#endif