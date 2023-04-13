/*
File				: ADT utama
Deskripsi			: Berisi tipe data utama
Dibuat oleh			: Xaviera Sadiya Salsabeel, Aryagara Kristandy Rukmana Putra, Vico Triansyah Nasril
Tanggal pembuatan	: Rabu, 12 April 2023
*/

#ifndef utama_H
#define utama_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define string const char*

typedef struct queue_cus *address;

typedef struct seat *address_seat;

typedef struct tLoket *address_loket;

typedef struct queue_cus{
	address_seat bwh;
	int no_antr;
	string nm_cust;
	address next; 
} Queue_cus;


typedef struct seat{
	string info_seat;
	address_seat next_seat;
} Seat;

typedef struct tLoket {
	address_seat next_bwh;
	address_loket next_lkt;
	int loket;
	double jm_tayang [50];
	string nm_film [50];
	string studio [50];
	double hrg_tiket;
} Loket;

#endif
