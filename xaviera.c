#include "xaviera.h"

void enqueue(antrean *q, infotype data, address_studio st) {
	int i;
	address new_node; 
	new_node = (address) malloc(sizeof(customer));
	new_node->nm_cus = data;
	new_node->next = Nil;

	if (q->tail == Nil) {
		q->head = new_node;
		q->tail = new_node;

		for ( i = 0; i < 10; i++)
		{
			new_node->cus_std[i] = st;
//		    new_node->cus_std[i] = (address_studio)malloc(sizeof(studio));
//			new_node->cus_std[i]->next_fl = Nil;
//			new_node->cus_std[i]->studio = Nil;
//			new_node->cus_std[i]->next_st = Nil;
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

void moveNode(antrean *q1, antrean *q2, infotype data)
{
    address current = Nil;
    address later = Nil;
    current = q1->head;
    
    while (current != Nil && current->nm_cus != data)
	{
        later = current;
        current = current->next;
    }

    if (current == Nil)
	{
        printf("Customer tidak ditemukan di queue luar yang berkeliaran \n");
        return;
    }
    
    if (later == Nil)
	{ //pengecekkan jika q1 apakah merupakan node pertama atau bukan
        q1->head = current->next;
    }
	else
	{
        later->next = current->next;
    }

    if (q1->tail == current)
	{ //apakah node yang dipindahkan saat ini adalah node terakhir pada antrean q1
        q1->tail = later;
    }

    current->next = Nil;

    if (q2->tail == Nil)
	{ //digunakan untuk memeriksa apakah q2 merupakan antrean kosong atau tidak. 
        q2->head = current;
        q2->tail = current;
    }
	else
	{
        q2->tail->next = current;
        q2->tail = current;
    }
    printf("Customer berhasil dipindahkan dari queue luar ke queue dalam.\n");
}

void NodeToEmptyLoket(address *q, address_loket loket1, address_loket loket2) {

    if (loket1->lkt_cus == Nil){ //cek apakah loket1 kosong
        loket1->lkt_cus = *q; //pindahkan node dari queue ke loket1
        *q = (*q)->next; // perbarui head
        if (loket1->lkt_cus->next == Nil)
		{
            loket1->lkt_cus->next = Nil; //perbarui tail
            (*q) = Nil;
        }
		else
		{
            loket1->lkt_cus->next = Nil; // Set the next pointer of the moved node to Nil
        }
		int i;
        for (i = 0; i < 10; i++) //untuk array of pointer dari cus_std
		{
            loket1->lkt_cus->cus_std[i] = Nil;
        }
        return;
    }

    if (loket2->lkt_cus == Nil) { //cek apakah loket2 kosong
        loket2->lkt_cus = *q; //pindahkan node dari queue ke loket2
        *q = (*q)->next; // Update head
        if (loket2->lkt_cus->next == Nil)
		{
            loket2->lkt_cus->next = Nil; //update tail
            (*q) = Nil;
        }
		else
		{
            loket2->lkt_cus->next = Nil; 
        }
        
        int i;
        // Reset array dari cus_std array di moved_node
        for ( i = 0; i < 10; i++)
		{
            loket2->lkt_cus->cus_std[i] = Nil;
        }
        return;
    }
}

//int getScreenWidth() {
//    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
//    HANDLE handleOfConsoleOutput = NULL;
//
//    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//    _infoex.cbSize = sizeof(_infoex);
//    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);
//
//    return _infoex.srWindow.Right;
//}
//
//int getScreenHeight() {
//    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
//    HANDLE handleOfConsoleOutput = NULL;
//
//    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//    _infoex.cbSize = sizeof(_infoex);
//    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);
//
//    return _infoex.srWindow.Bottom;
//}

void warna(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 245 );

    system("cls");

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Buat CMD jadi full-size (entah mengapa di windows 10 berlaku, di windows 11 tidak)
}


Print_Loket(address_loket lk){
	printf("%s\n", lk->lkt_cus);
}
