
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>

#define Nil NULL

typedef const char* infotype;
typedef int infotype1;

typedef struct stud *address_studio;
typedef struct stud {
	address_studio bwh_st;
	infotype studio;
	address_studio next_st;
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


//address head;
//address tail;

address First;
address Last;


typedef struct seat *address_Seat;
typedef struct seat{
	infotype info_seat;
	address_Seat next_seat;
}Seat;

typedef struct lkt *address_loket;
typedef struct lkt {
	address_Seat next_bwh;
	address_loket next_lkt;
	infotype1 loket;
	infotype1 studio;
	float hrgTkt;
}Loket;

typedef struct film *address_film;
typedef struct film{
	infotype nm_film;
	float jm_tyg;
	address_Seat bwh_se;
	address_film next_fl;
}Film;

address Alokasi (infotype X);
int cekKosong (antrean q);
void bikinQ(antrean *q);
void insertCus(address* L, infotype X);
void PrintA(antrean c);
void PrintB(antrean b);
void Insertlastcust (address* L, address H);

