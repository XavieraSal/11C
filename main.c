#include <stdio.h>
#include "header.h"
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char y = 'y';
	int pil, n;
	address jumc, F = Nil, O;
	infotype X, nm;
	antrean q;
	bikinQ(&q);
	while (y == 'y' || y == 'Y') {
		printf("[1] Alokasi Customer");
		printf("\n[2] Lihat Antrean\n");

		scanf("%d", &pil);

		switch(pil) {
			case 1 :
				printf("\nMasukkan jumlah customer: ");
				scanf("%d", &n);
				for (int i = 1; i <= n; i++) {
					printf("\nMasukkan nama customer: ");
					scanf("%s", &X);
					insertCus(&q, X, 1);
				}
				break;
			case 2 :
				asc(F);
				break;
		}
		printf("\nKembali ke menu? [Y / N]\n");
		y = getch();
	}
	return 0;
}
