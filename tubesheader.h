#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <conio.h>
#define MAX_STRING_LENGTH 100

#define Nil NULL

typedef const char* infotype;
typedef int infotype1;

typedef struct stud *address_studio;
typedef struct stud {
	address_studio bwh_st;
	infotype studio;
	address_studio next_st;
} studio;

typedef struct nodeCus *address;
typedef struct nodeCus {
	infotype nm_cus;
	address prev;
	address_studio cus_std[10];
	address next;
} customer;

typedef struct queue {
	address head;
	address tail;
} antrean;


//address head;
//address tail;

address First;
address Last;


typedef struct seat *address_Seat;
typedef struct seat{
	infotype info_seat;
	address_Seat next_seat;
}Seat;

typedef struct lkt *addressLoket;
typedef struct lkt {
	address_Seat next_bwh;
	addressLoket next_lkt;
	infotype1 loket;
	infotype1 studio;
	float hrgTkt;
}Loket;

typedef struct film *addressFilm;
typedef struct film{
	infotype nm_film;
	float jm_tyg;
	address_Seat bwh_se;
	addressFilm next_fl;
}Film;


//--------------------------------//

typedef struct node {
    int data;
    struct node *next;
} node;

