#include "xaviera.h"
#include "arya.h"

int main() {
	address c, plgn1, plgn2, bukti;
	address_studio sTemp, s;
	address_loket Loket = Nil, Lkt;
	address_film now = Nil,
	             head = Nil;
	address_Seat depan = Nil;
	antrean q = {Nil, Nil};
	antrean q2 = {Nil, Nil};
	infotype input;
	char ulang = 'y';
	int cho, pil;
	int i, n;
	int num_seats;
	int seat_num;
	SeatHistory *history_head = Nil;


	do {
		printf("Customer yang berkeliaran:\n");
		PrintA(q);

		printf("Customer yang mengantre:\n");
		PrintA(q2);

		//print lkt1
		//print lkt2

		printf("\n[1] Input Customer\n");
		printf("[2] Pindahkan Customer ke antrean\n");
		printf("[3] Loket\n");
		scanf("%d", &pil);

		switch(pil) {

			case 1:
				printf("\nAda berapa customer di bioskop?\t");
				scanf("%d", &n);
				for ( i = 1; i <= n; i++) {
					printf("\nMasukkan namanya: ");
					fflush(stdin);
					scanf("%s", &input);
					enqueue(&q, input);
				}
				break;

			case 2:
				do {
					printf("\nSiapa yang mau mengantre untuk nonton film?\n");
					fflush(stdin);
					scanf("%s", &input);
					//printf("\nini movenode\n");
					moveNode(&q, &q2, input);
					printf("\nApakah ada yang ingin mengantre lagi?(y/t))\n");
					ulang = getche();
				} while (ulang== 'y' || ulang == 'Y');

				//node pertama masuk ke loket

				break;
			case 3 :
				system("cls");
				int o = 0;
				addPrintFilm(&head, &now, &s);
				sTemp = s;
				printf("\nStudio");
				plgn1 = q2.head;
				printf("\nPelanggan 1 (Loket 2's head)");
				plgn2 = plgn1->next;
				printf("\nPelanggan 2");
				while (plgn1 != Nil && plgn2 != Nil) {
//					if(plgn1 != Nil){
					plgn1->next = plgn2->next;
					plgn1 = plgn1->next;
					printf("\nBelakang antrian genap pindah ke ganjil DONE");
//					}
//					else{
					plgn2->next = plgn1->next;
					plgn2 = plgn2->next;
					printf("\nBelakang antrian ganjil pindah ke genap DONE");
//					}
					printf("\nPelanggan not NULL DONE");
				}
				plgn1 = q2.head;
				plgn2 = plgn1->next;
				while (plgn1 != Nil) {
					printf("%s", plgn1->nm_cus);
					plgn1 = plgn1->next;
				}
				while (plgn2 != Nil) {
					printf("%s", plgn2->nm_cus);
					plgn2 = plgn2->next;
				}
				printf("\nPrint nama pelanggan DONE");
				Lkt = Loket;
				for (i = 1; i <= 2; i++) {
//				do {
					if  (Lkt == Nil) {
						Lkt = Locket(i, sTemp, plgn1);
//						o = 1;
//						plgn1 = plgn2->next;
//						Lkt = Lkt->next_loket;
					} else {
						Lkt->next_loket = Locket(i, sTemp, plgn2);
//						o = 0;
//						plgn2 = plgn1->next;
//						Lkt = Loket;
					}
				}
//				} while (plgn1 != Nil && plgn2 != Nil);
				sTemp = sTemp->next_st; //alokasi loket
				bukti = Loket->lkt_cus;
				while(bukti != Nil) {
					printf("%s", bukti->nm_cus);
				}

				do {
					printf("1. Buat kursi\n");
					printf("2. Tampilkan kursi\n");
					printf("3. Book seat(s)\n");
					printf("4. Clear booking history\n");
					printf("5. Display booking history\n");
					scanf("%d",&pil);

					switch(pil) {
						case 1:
							system("cls");
							depan = create_seats();
							printf("Cinema seats created successfully.\n");
							break;
						case 2:
							display_seats(depan);
							break;
						case 3:
							printf("\n1. Book single seat\n");
							printf("2. Book multiple seats\n");
							printf("\nEnter your choice: ");
							scanf("%d", &pil);

							switch(pil) {
								case 1:
									printf("\nEnter seat number: ");
									scanf("%d", &seat_num);
									book_seat(depan, 1, &history_head);
									break;
								case 2:
									book_seats(depan, &history_head);
									break;
								default:
									printf("\nInvalid choice. Please try again.\n");
									break;
							}
							break;
						case 4:
							clear_history(&history_head);
							printf("\nBooking history cleared.\n");
							break;
						case 5:
							printf("\nBooking history:\n");
							display_history(history_head);
							break;
					}

					ulang = getche();
				} while (ulang== 'y' || ulang == 'Y');
		}
		printf("\nApakah ingin kembali ke menu?");
		fflush(stdin);
		ulang = getche();
		system("cls");
	} while(ulang == 'y' || ulang == 'Y');
	return 0;
}
