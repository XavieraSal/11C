#include "header.h"

int main() {
	char y = 'y';
	int pil, n;
	int i, row, col;

	address_Seat seats;
	infokata X, nm;
	antrean q, q2;
	bikinQ(&q);
	address P, Front = Nil, Rear = Nil, L;
	while (y == 'y' || y == 'Y') {
		system("cls");
		printf("[1] Alokasi Customer");
		printf("\n[2] Lihat Antrean\n");
		printf("[3] Cek customer\n");
		
		printf("Masukan pilihan anda :");
		scanf("%d", &pil);

		switch(pil) {
			case 1 :
				system("cls");
				printf("\nMasukkan jumlah customer: ");
				scanf("%d", &n);
				for ( i = 1; i <= n; i++) {
					printf("\nMasukkan nama customer: ");
					scanf("%s", &X);
					insertCus(&q.head, X);
				}
			break;
			
			case 2 :
				system("cls");
				PrintA(q);
			break;
			
			case 3:
				system("cls");
                printf("Masukkan nama pelanggan yang dicari: ");
                scanf("%s", nm);
                P = searchNode(q.head, nm);
                if (P != Nil)
                {
                    printf("%s ditemukan dalam antrean\n", nm);
                }
			break;

    		
			default :
				printf("Angka yang anda pilih tidak ada");
			break;
		}
		printf("\nKembali ke menu? [Y / N]\n");
		y = getch();
	}
	return 0;
}
