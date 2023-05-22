#include "xaviera.h"

//void enqueue(antrean *q, infotype data) {
//	int i;
//	address new_node = (address) malloc(sizeof(customer));
//	new_node->nm_cus = data;
//	new_node->next = Nil;
//	new_node->prev = Nil;
//
//	if (q->tail == Nil) {
//		q->head = new_node;
//		q->tail = new_node;
//
//		for ( i = 0; i < 10; i++)
//		{
//			new_node->cus_std[i] = (address_studio)malloc(sizeof(studio));
//			new_node->cus_std[i]->next_fl = Nil;
//			new_node->cus_std[i]->studio = Nil;
//			new_node->cus_std[i]->next_st = Nil;
//		}
//	} else {
//		q->tail->next = new_node;
//		q->tail = new_node;
//	}
//}

void enqueue(antrean *q, infotype data, address_studio st) {
	int i;
	address new_node = (address) malloc(sizeof(customer));
	new_node->nm_cus = data;
	new_node->next = Nil;
	//new_node->prev = Nil;

	if (q->tail == Nil) {
		q->head = new_node;
		q->tail = new_node;

		for ( i = 0; i < 10; i++)
		{
			new_node->cus_std[i] = (address_studio)malloc(sizeof(studio));
			new_node->cus_std[i]->next_fl = st;
			new_node->cus_std[i]->studio = st;
			new_node->cus_std[i]->next_st = st;
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

//void moveNode(antrean *q1, antrean *q2, infotype data) {
//	address current = Nil;
//	address later = Nil;
//	current = q1->head;
//	while (current->next != Nil && current->nm_cus != data) {
//		later = current;
//		current = current->next;
//	}
//	//
//	if (current == Nil) {
//		printf("Node tidak ditemukan di dalam queue 1.\n");
//		return;
//	}
//	//
//	if (later == Nil) { //pengecekkan jika q1 apakah merupakan node pertama atau bukan
//		q1->head = current->next;
//	} else {
//		later->next = current->next;
//	}
//	//
//	if (q1->tail == current) { //apakah node yang dipindahkan saat ini adalah node terakhir pada antrean q1
//		q1->tail = later;
//	}
//	current->next = Nil;
//	//
//	if (q2->tail == Nil) {//digunakan untuk memeriksa apakah q2 merupakan antrean kosong atau tidak. 
//		q2->head = current;
//		q2->tail = current;
//	} else {
//		q2->tail->next = current; //tidak kosong
//		q2->tail = current;
//	}
//	printf("Customer berhasil dipindahkan dari queue luar ke queue dalam\n");
//}

void moveNode(antrean *q1, antrean *q2, infotype data) {
    address current = Nil;
    address later = Nil;
    current = q1->head;
    while (current != Nil && current->nm_cus != data) {
        later = current;
        current = current->next;
    }

    if (current == Nil) {
        printf("Customer tidak ditemukan di dalam daerah yang berkeliaran \n");
        return;
    }

    if (later == Nil) {
        q1->head = current->next;
    } else {
        later->next = current->next;
    }

    if (q1->tail == current) {
        q1->tail = later;
    }

    current->next = Nil;

    if (q2->tail == Nil) {
        q2->head = current;
        q2->tail = current;
    } else {
        q2->tail->next = current;
        q2->tail = current;
    }

    printf("Customer berhasil dipindahkan dari queue luar ke queue dalam.\n");
}


// void moveNodeToEmptyLoket(antrean *q, address_loket loket1, address_loket loket2) {
//    if (loket1->lkt_cus == Nil) { // Check if loket1 is empty
//        if (q->head != Nil) {
//            loket1->lkt_cus = q->head; // Move the node from the queue to loket1
//            q->head = q->head->next; // Update the queue's head
//            if (q->head == Nil) {
//                q->tail = Nil; // If the queue becomes empty, update the tail as well
//            }
//            loket1->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
//
//            // Reset the cus_std array in the moved node
//            for (int i = 0; i < 10; i++) {
//                loket1->lkt_cus->cus_std[i] = Nil;
//            }
//            return;
//        }
//    }
//
//    if (loket2->lkt_cus == Nil) { // Check if loket2 is empty
//        if (q->head != Nil) {
//            loket2->lkt_cus = q->head; // Move the node from the queue to loket2
//            q->head = q->head->next; // Update the queue's head
//            if (q->head == Nil) {
//                q->tail = Nil; // If the queue becomes empty, update the tail as well
//            }
//            loket2->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
//
//            // Reset the cus_std array in the moved node
//            for (int i = 0; i < 10; i++) {
//                loket2->lkt_cus->cus_std[i] = Nil;
//            }
//            return;
//        }
//    }
//}
//
//ubah modul di atas agar parameter yang digunakan bukanlah antrean, tetapi address dan juga ada kondisi ketika q->head Nil

//void moveNodeToEmptyLoket(address *q, address_loket loket1, address_loket loket2) {
//    if (loket1->lkt_cus == Nil) { // Check if loket1 is empty
//        if (*q != Nil) {
//            loket1->lkt_cus = *q; // Move the node from the queue to loket1
//            *q = (*q)->next; // Update the queue's head
//            if (*q == Nil) {
//                // If the queue becomes empty, update the tail as well
//                // Since we don't have access to the queue's tail directly,
//                // we need to traverse the queue to find the tail.
//                address temp = *q;
//                while (temp != Nil && temp->next != Nil) {
//                    temp = temp->next;
//                }
//                if (temp != Nil) {
//                    temp->next = Nil;
//                }
//            }
//            loket1->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
//
//            // Reset the cus_std array in the moved node
//            for (int i = 0; i < 10; i++) {
//                loket1->lkt_cus->cus_std[i] = Nil;
//            }
//            return;
//        }
//    }
//
//    if (loket2->lkt_cus == Nil) { // Check if loket2 is empty
//        if (*q != Nil) {
//            loket2->lkt_cus = *q; // Move the node from the queue to loket2
//            *q = (*q)->next; // Update the queue's head
//            if (*q == Nil) {
//                // If the queue becomes empty, update the tail as well
//                // Since we don't have access to the queue's tail directly,
//                // we need to traverse the queue to find the tail.
//                address temp = *q;
//                while (temp != Nil && temp->next != Nil) {
//                    temp = temp->next;
//                }
//                if (temp != Nil) {
//                    temp->next = Nil;
//                }
//            }
//            loket2->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
//
//            // Reset the cus_std array in the moved node
//            for (int i = 0; i < 10; i++) {
//                loket2->lkt_cus->cus_std[i] = Nil;
//            }
//            return;
//        }
//    }
//}

void NodeToEmptyLoket(address *q, address_loket loket1, address_loket loket2) {

    if (*q == Nil) {
        printf("Antrian kosong\n");
        return;
    }

    if (loket1->lkt_cus == Nil) { // Check if loket1 is empty
        loket1->lkt_cus = *q; // Move the node from the queue to loket1
        *q = (*q)->next; // Update the queue's head
        if (loket1->lkt_cus->next == Nil) {
            // If the node was the last one in the queue, update the tail
            loket1->lkt_cus->next = Nil;
            (*q) = Nil;
        } else {
            loket1->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
        }

        // Reset the cus_std array in the moved node
        for (int i = 0; i < 10; i++) {
            loket1->lkt_cus->cus_std[i] = Nil;
        }
        return;
    }

    if (loket2->lkt_cus == Nil) { // Check if loket2 is empty
        loket2->lkt_cus = *q; // Move the node from the queue to loket2
        *q = (*q)->next; // Update the queue's head
        if (loket2->lkt_cus->next == Nil) {
            // If the node was the last one in the queue, update the tail
            loket2->lkt_cus->next = Nil;
            (*q) = Nil;
        } else {
            loket2->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
        }

        // Reset the cus_std array in the moved node
        for (int i = 0; i < 10; i++) {
            loket2->lkt_cus->cus_std[i] = Nil;
        }
        return;
    }
}


void PrintIsiLoket(address_loket loket) {
    printf("Isi Loket %d:\n", loket->loket);
    if (loket->lkt_cus == Nil) {
        printf("Loket kosong\n");
    } else {
        address temp = loket->lkt_cus;
        int i = 1;
        while (temp != Nil) {
            printf("%d. %s\n", i, temp->nm_cus);
            temp = temp->next;
            i++;
        }
    }
}

void PrintIsiDuaLoket(address_loket loket1, address_loket loket2) {
    printf("Isi Dua Loket:\n");
    printf("Loket %d:\n", loket1->loket);
    PrintIsiLoket(loket1);
    printf("\n");
    printf("Loket %d:\n", loket2->loket);
    PrintIsiLoket(loket2);
}

int getScreenWidth() {
    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
    HANDLE handleOfConsoleOutput = NULL;

    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    _infoex.cbSize = sizeof(_infoex);
    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);

    return _infoex.srWindow.Right;
}

int getScreenHeight() {
    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
    HANDLE handleOfConsoleOutput = NULL;

    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    _infoex.cbSize = sizeof(_infoex);
    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);

    return _infoex.srWindow.Bottom;
}

void warna(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 245 );

    system("cls");

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // Make the console windows become full-size
}

