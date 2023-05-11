#include "xaviera.h"

void enqueue(antrean *q, infotype data) {
	int i;
	address new_node = (address) malloc(sizeof(customer));
	new_node->nm_cus = data;
	new_node->next = Nil;
	new_node->prev = Nil;

	if (q->tail == Nil) {
		q->head = new_node;
		q->tail = new_node;

		for ( i = 0; i < 10; i++);
		{
			new_node->cus_std[i] = (address_studio)malloc(sizeof(studio));
			new_node->cus_std[i]->next_fl = Nil;
			new_node->cus_std[i]->studio = Nil;
			new_node->cus_std[i]->next_st = Nil;
		}
	} else {
		q->tail->next = new_node;
		q->tail = new_node;
	}
}

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

void moveNode(antrean *q1, antrean *q2, infotype data) {
	address current = q1->head;
	address later = Nil;
	while (current->next != Nil && current->nm_cus != data) {
		later = current;
		current = current->next;
	}
	//
	if (current == Nil) {
		printf("Node tidak ditemukan di dalam queue 1.\n");
		return;
	}
	//
	if (later == Nil) { //pengecekkan jika q1 apakah merupakan node pertama atau bukan
		q1->head = current->next;
	} else {
		later->next = current->next;
	}
	//
	if (q1->tail == current) { //apakah node yang dipindahkan saat ini adalah node terakhir pada antrean q1
		q1->tail = later;
	}
	current->next = Nil;
	//
	if (q2->tail == Nil) {//digunakan untuk memeriksa apakah q2 merupakan antrean kosong atau tidak. 
		q2->head = current;
		q2->tail = current;
	} else {
		q2->tail->next = current; //tidak kosong
		q2->tail = current;
	}
	printf("Customer berhasil dipindahkan dari queue luar ke queue dalam\n");
}

void moveToLoket(antrean *antreanQ, antrean *loketQ) {
    if (loketQ->head == NULL) {
        if (antreanQ->head != NULL) {
            address nodeToMove = antreanQ->head;
            antreanQ->head = nodeToMove->next;
            if (antreanQ->head == NULL) {
                antreanQ->tail = NULL;
            }
            nodeToMove->next = NULL;
            loketQ->head = nodeToMove;
            loketQ->tail = nodeToMove;
            printf("Node pertama berhasil dipindahkan ke queue loket.\n");
        } else {
            printf("Queue antrean kosong\n");
        }
    } else {
        printf("Queue loket sudah terisi\n");
    }
}
