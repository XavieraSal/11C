#include "xaviera.h"
#include "arya.h"

int main() {
	warna();
	address c,
			plgn1,
			plgn2,
			bukti;
	address_studio sTemp,
				   s;
	address_loket Loket = Nil,
				  Lkt;
	address_film now = Nil,
	             head = Nil;
	address_Seat depan = Nil;
	antrean q = {Nil, Nil};
	antrean q2 = {Nil, Nil};
	infotype input;
	char ulang = 'y';
	int cho,
		pil,
		validInput,
		i,
		n,
		num_seats,
		seat_num;
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
				validInput = 0;
				while (!validInput) {
					printf("\nAda berapa customer di bioskop?\t");
					// Meminta input pengguna hingga angka yang valid dimasukkan
					if (scanf("%d", &n) == 1) {
						validInput = 1;
						for (i = 1; i <= n; i++) {
							printf("\nMasukkan namanya: ");
							fflush(stdin);
							scanf("%s", &input);
							enqueue(&q, input, s);
						}
					} else {
						printf("Input tidak valid. Mohon masukkan angka.\n");
						// Membersihkan input buffer
						while (getchar() != '\n');
					}
				}
				break;
			case 2:
				if (!cekKosong(q)) {
					do {
						printf("\nSiapa yang mau mengantre untuk nonton film?\n");
						fflush(stdin);
						scanf("%s", &input);
						moveNode(&q, &q2, input);
						printf("\nApakah ada yang ingin mengantre lagi?(y/t))\n");
						ulang = getche();
					} while (ulang == 'y' || ulang == 'Y');
				}
				printf("Belum ada customer di dalam bioskop\n");
				break;
			case 3 :
				system("cls");
				int o = 0;
				addPrintFilm(&head, &now, &s);
				sTemp = s;
				printf("\nStudio");

				address_loket Loket_1 = Locket(1, sTemp, q2.head);
				address_loket Loket_2 = Locket(2, sTemp, q2.head);

				printf("\n ini kondisi q2:\n");
				PrintA(q2);
				NodeToEmptyLoket(&q2.head, Loket_1, Loket_2);
				printf("\n ini kondisi q2 setelah move node utk lkt:\n");
				PrintA(q2);
				printf("ini print loket\n");
				PrintIsiDuaLoket(Loket_1, Loket_2);

				//alokasi loket
//				address_loket Loket_1 = Locket(1, sTemp, q.head);
//				address_loket Loket_2 = Locket(2, sTemp, q.head);
//
//				printf("\n ini kondisi q2:\n");
//				PrintA(q2);
//				NodeToEmptyLoket(&q2.head, Loket_1, Loket_2);
//				printf("\n ini kondisi q2 setelah move node utk lkt1:\n");
//				PrintA(q2);



				//	moveNodeToEmptyLoket(&q2.head, Loket_1, Loket_2);
				//	printf("\n ini kondisi q2 setelah move node utk lkt2:\n");
				//PrintA(q2);

				//PrintIsiDuaLoket(Loket_1, Loket_2);

//				printf("Loket 1 :");
//				plgn1 = Loket_1->lkt_cus;
//				while(plgn1 != Nil){
//				printf("%s", plgn1->nm_cus);
//				plgn1 = plgn1->next;
//				}
//				plgn2 = Loket_2->lkt_cus;
//				while(plgn2 != Nil){
//				printf("%s", plgn2->nm_cus);
//				plgn2 = plgn2->next;
//				}


//				plgn1 = q2.head;
//				printf("\nPelanggan 1 (Loket 2's head)");
//				plgn2 = plgn1->next;
//				printf("\nPelanggan 2");
//				while (plgn1 != Nil && plgn2 != Nil) {
////					if(plgn1 != Nil){
//					plgn1->next = plgn2->next;
//					plgn1 = plgn1->next;
//					printf("\nBelakang antrian genap pindah ke ganjil DONE");
////					}
////					else{
//					plgn2->next = plgn1->next;
//					plgn2 = plgn2->next;
//					printf("\nBelakang antrian ganjil pindah ke genap DONE");
////					}
//					printf("\nPelanggan not NULL DONE");
//				}
//				plgn1 = q2.head;
////				printf("\n%s", plgn1->nm_cus);
//				printf("\nPelanggan 1 (Loket 2's head)");
//				plgn2 = plgn1->next;
//				printf("\nPelanggan 2");
//				while (plgn1 != Nil) {
//					printf("\nPrint Nama Customer PLGN1 START");
////					printf("%s", plgn1->nm_cus); // segmentation fault
//					printf("\nPrint Nama Customer PLGN1 DONE");
//					plgn1 = plgn1->next;
//					printf("\nBelakang antrian genap pindah ke ganjil DONE");
//				}
//				while (plgn2 != Nil) {
//					printf("\nPrint Nama Customer PLGN2 START");
////					printf("%s", plgn2->nm_cus); //segmentation fault
//					printf("\nPrint Nama Customer PLGN2 DONE");
//					plgn2 = plgn2->next;
//					printf("\nBelakang antrian ganjil pindah ke genap DONE");
//				}
//				printf("\nPrint nama pelanggan DONE");
//				Lkt = Loket;
//				for (i = 1; i <= 2; i++) {
////				do {
//					if  (Lkt == Nil) {
//						printf("\nLkt checked as NULL DONE");
//						Lkt = Locket(i, sTemp, plgn1); // segmentation fault
//						printf("\nLkt assigned with Locket() DONE");
////						o = 1;
////						plgn1 = plgn2->next;
////						Lkt = Lkt->next_loket;
//					} else {
//						printf("\nLkt checked as NOT NULL DONE");
//						Lkt->next_loket = Locket(i, sTemp, plgn2); // segmentation fault
//						printf("\nLkt->next assigned with Locket() DONE");
////						o = 0;
////						plgn2 = plgn1->next;
////						Lkt = Loket;
//					}
//				}
////				} while (plgn1 != Nil && plgn2 != Nil);
//				sTemp = sTemp->next_st; //alokasi loket
//				bukti = Loket->lkt_cus;
//				while(bukti != Nil) {
//					printf("%s", bukti->nm_cus);
//				}

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
