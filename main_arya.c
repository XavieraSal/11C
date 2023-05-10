#include <stdio.h>
#include "header.h"
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char y = 'y';
	int pil, n, i;
	infotype X;
	address_studio first = Nil, T, sek = Nil;
	address_film head = Nil, now = Nil;
	infotype1 k, e;
	infotype2 jam_tayang[9];
	antrean q;
	bikinQ(&q);
	while (y == 'y' || y == 'Y') {
		printf("[1] Alokasi Customer\n");
		printf("[2] Lihat Antrean\n");
		printf("[3] Studio\n");
		printf("[4] Loket\n");

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
			case 3 :
				if (first == Nil) {
					for (i = 1; i <= 1; i++) {
						first = add_studio(first);
					}
					display_studio(first);
				}
				break;
			case 4 :
				addPrintFilm(&head, &now);
				break;
		}
		printf("\nKembali ke menu? [Y / N]\n");
		y = getch();
	}
	return 0;
}
