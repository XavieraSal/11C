#include "header_utama.h"
#include "body_queue.c"


int main() {
	char y = 'y';
	int pil, n;
	int i;

	
	infotype X, nm;
	antrean q;
	bikinQ(&q);
	address Front = Nil, Rear = Nil;
	while (y == 'y' || y == 'Y') {
		printf("[1] Alokasi Customer");
		printf("\n[2] Lihat Antrean\n");

		scanf("%d", &pil);

		switch(pil) {
			case 1 :
				printf("\nMasukkan jumlah customer: ");
				scanf("%d", &n);
				for ( i = 1; i <= n; i++) {
					printf("\nMasukkan nama customer: ");
					scanf("%s", &X);
					insertCus(&q.head, X);
				}
				break;
			case 2 :
				PrintA(q);
				break;
		}
		printf("\nKembali ke menu? [Y / N]\n");
		y = getch();
	}
	return 0;
}
