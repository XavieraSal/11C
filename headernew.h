#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define Nil NULL

typedef const char* infotype;
typedef int infotype1;

typedef struct node_cus *address;
typedef struct stud *address_studio;
typedef struct lkt *address_loket;
typedef struct film *address_film;
typedef struct seat *address_seat;


typedef struct node_cus {
	address prev;
	infotype nm_cus;
	address_studio cus_std[10];
	address next;
} customer;

typedef struct stud {
	address_studio bwh_st;
	infotype studio;
	address_studio next_st;
} studio;

address head;
address tail;

address First;
address Last;

typedef struct lkt {
	address_seat next_bwh;
	address_loket next_lkt;
	infotype1 loket;
	infotype1 studio;
	float hrg_tkt;
}Loket;

typedef struct film{
	infotype nm_film;
	float jm_tyg;
	address_seat bwh_se;
	address_film next_fl;
}Film;

typedef struct seat{
	infotype info_seat;
	address_seat next_seat;
}Seat;

