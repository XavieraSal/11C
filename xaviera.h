#ifndef xaviera_H
#define xaviera_H
#include <string.h>
#include "arya.h"
#define MAX_STRING_LENGTH 100

//--------------------------------//

typedef struct node {
	int data;
	struct node *next;
} node;

void enqueue(antrean *q, infotype data);
void PrintA(antrean c);
void moveNode(antrean *q1, antrean *q2, infotype data);
void movetoLkt(antrean *q1, antrean *q2);
#endif