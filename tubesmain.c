#include "tubesheader.h"

int main() {
	infotype input
	char ulang = 'y';
	int cho, pil;
	int i, n;
	antrean q = {Nil, Nil};
	antrean q2 = {Nil, Nil};

	do {

		printf("\n1.In\n");
		printf("2.Print\n");
		printf("3. Move node\n");
		scanf("%d", &pil);

		switch(pil) {

			case 1:
				printf("\nMasukkan jumlah cumstomer :");
				scanf("%d", &n);
				for ( i = 1; i <= n; i++) {
					printf("\nMasukkan nama : ");
					fflush(stdin);
					scanf("%s", &input);
					enqueue(&q, input);
				}
				break;

			case 2:
				PrintA(q);
				break;

			case 3:

				do {
					printf("\nini queue 1\n");
					PrintA(q);
					printf("\nmasukkan yg mw dicari\n");
					fflush(stdin);
					scanf("%s", &input);
					printf("\nini movenode\n");
					moveNode(&q, &q2, input);

					printf("\nini queue 1\n");
					PrintA(q);
					printf("\nini queue 2\n");
					PrintA(q2);

					printf("\napakah ingin memindahkan lagi?(y/t))\n");
					ulang = getche();
				} while (ulang== 'y' || ulang == 'Y');

				break;
		}
		printf("\nApkkh ingin menu?");
		fflush(stdin);
		ulang = getche();
		system("cls");
	} while(ulang == 'y' || ulang == 'Y');
	return 0;
}