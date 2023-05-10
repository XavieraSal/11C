#include "tubesheader.h"

void enqueue(antrean *q, infotype data) {
	int i;
    address new_node = (address) malloc(sizeof(customer));
    new_node->nm_cus = data;
    new_node->next = Nil;
    new_node->prev = Nil;
    
    if (q->tail == Nil) {
        q->head = new_node;
        q->tail = new_node;
        
        for ( i = 0; i < 10; i++); {
            new_node->cus_std[i] = (address_studio)malloc(sizeof(studio));
            new_node->cus_std[i]->bwh_st = Nil;
            new_node->cus_std[i]->studio = "";
            new_node->cus_std[i]->next_st = Nil;
        }
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

//void printCus(antrean q){
//	while (q.head != NULL) 
//	{
//		printf("%s ", q.head->nm_cus);
//		customer *temp = q.head;
//		q.head = q.head->next;
//	
//	}
//}
//	

void PrintA(antrean c)
{
	/* Kamus Lokal */
	address H;
	int i=1;
	/* Algoritma */
	if (c.head == Nil)
	{
		 printf ("queue Kosong .... \a\n");
	}
	else	/* queue memiliki elemen */
	{
		 H = c.head;
		 for (;;)
		 {
		if (H == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir queue */
		{
			 printf ("%d. %s \n",i, H);
			 H = H->next;
			 i++;
		}
		 }
	}
}

void moveNode(antrean *q1, antrean *q2, infotype data) {
    address current = q1->head;
    address prev = Nil;
    while (current != Nil && current->nm_cus != data) {
        prev = current;
        current = current->next;
    }
    if (current == Nil) {
        printf("Node tidak ditemukan di dalam queue 1.\n");
        return;
    }
    if (prev == Nil) {
        q1->head = current->next;
    } else {
        prev->next = current->next;
    }
    if (q1->tail == current) {
        q1->tail = prev;
    }
    current->next = Nil;
    if (q2->tail == Nil) {
        q2->head = current;
        q2->tail = current;
    } else {
        q2->tail->next = current;
        q2->tail = current;
    }
    printf("Node dengan data '%c' berhasil dipindahkan dari queue 1 ke queue 2.\n", data);
}

void movetoLkt(antrean *q1, antrean *q2) {
    if (q1->head == NULL) {
        printf("Queue 1 kosong.\n");
        return;
    }
    address nodeToMove = q1->head;
    q1->head = q1->head->next;
    if (q1->head == NULL) {
        q1->tail = NULL;
    }
    nodeToMove->next = NULL;
    if (q2->tail == NULL) {
        q2->head = nodeToMove;
        q2->tail = nodeToMove;
    } else {
        q2->tail->next = nodeToMove;
        q2->tail = nodeToMove;
    }
    printf("Node dengan data '%c' berhasil dipindahkan dari queue 1 ke queue 2.\n", nodeToMove->nm_cus);
}
