#ifndef header_H
#define header_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#define Nil NULL

typedef const char* infokata;
typedef int infoangka;

typedef struct stud *address_studio;
typedef struct stud {
	address_studio bwh_st;
	infokata studio;
	address_studio next_st;
} studio;

typedef struct node_cus *address;
typedef struct node_cus {
	infokata nm_cus;
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

typedef struct seat *address_Seat;
typedef struct seat{
	infokata info_seat;
	address_Seat next_seat;
}Seat;

typedef struct lkt *address_loket;
typedef struct lkt {
	address_Seat next_bwh;
	address_loket next_lkt;
	infoangka loket;
	infoangka studio;
	float hrgTkt;
}Loket;

typedef struct film *address_film;
typedef struct film{
	infokata nm_film;
	float jm_tyg;
	address_Seat bwh_se;
	address_film next_fl;
}Film;

address Alokasi (infokata X);
int cekKosong (antrean q);
void bikinQ(antrean *q);
void insertCus(address* L, infokata X);
void PrintA(antrean c);
void Insertlastcust (address* L, address H);
address searchNode(address L, infokata nm);
#endif
