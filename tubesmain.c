#include "xaviera.h"
#include "arya.h"

int main() {
	warna();
	int pilihan_film, jumlah_kursi, pembayaran;
    int lanjut = 1;
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

		printf("\n\t\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
		printf("\t\t\t\t\xB3            Pembelian Tiket Film           \xB3\n");
		printf("\t\t\t\t\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n");
		printf("\t\t\t\t\xB3 [1] Input Customer                        \xB3\n");
		printf("\t\t\t\t\xB3 [2] Pindahkan Customer ke antrean         \xB3\n");
		printf("\t\t\t\t\xB3 [3] Loket                                 \xB3\n");
//	printf("\t\t\t\t\xB3 [4] Exit                                  \xB3\n");
		printf("\t\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
		printf("\t\t\tInput : ");
		scanf("%d", &pil);
		switch(pil) {

			case 1:
				
//				printf("%d", Loket->loket);
				validInput = 0;
				while (!validInput) {
					printf("\n\t\t\t\t\tAda berapa customer di bioskop?\t");
					// Meminta input pengguna hingga angka yang valid dimasukkan
					if (scanf("\n%d", &n) == 1) {
						validInput = 1;
						for (i = 1; i <= n; i++) {
							printf("\n\t\t\t\t\tMasukkan namanya: ");
							fflush(stdin);
							scanf("%s", &input);
							enqueue(&q, input, s);
						}
					} else {
						printf("\t\t\t\t     Input tidak valid. Mohon masukkan angka.\n");
						// Membersihkan input buffer
//						system("cls");
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
				printf("\n ini kondisi q2 setelah move node utk lkt 1:\n");
				PrintA(q2);
				NodeToEmptyLoket(&q2.head, Loket_1, Loket_2);
				printf("\n ini kondisi q2 setelah move node utk lkt 2:\n");
				PrintA(q2);
				
				/*error
				printf("ini print loket\n");
				PrintIsiDuaLoket(Loket_1, Loket_2);
				*/
				
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

			printf("Daftar film yang sedang tayang:\n");
    printf("1. Film BATMAN\n");
    printf("2. Film DUNE\n");
    printf("3. Film BARBIE\n");

    while (lanjut) {
        printf("Pilih film yang ingin ditonton (1-3): ");
        scanf("%d", &pilihan_film);

        printf("Berapa banyak kursi yang ingin Anda pesan? ");
        scanf("%d", &jumlah_kursi);

        printf("Masukkan jumlah pembayaran: ");
        scanf("%d", &pembayaran);

        tampilkan_kursi_tersedia();

        if (pilihan_film >= 1 && pilihan_film <= JUMLAH_FILM) {
            printf("Anda telah memilih Film %c.\n", 'A' + pilihan_film - 1);
            pesan_kursi(pilihan_film - 1, jumlah_kursi, pembayaran);
        } else {
            printf("Pilihan film tidak valid.\n");
        }

        tampilkan_kursi_tersedia();

        printf("Apakah Anda ingin melakukan pembelian lagi? (1 = Ya, 0 = Tidak): ");
        scanf("%d", &lanjut);
    }
		}
		printf("\nApakah ingin kembali ke menu?");
		fflush(stdin);
		ulang = getche();
		system("cls");
	} while(ulang == 'y' || ulang == 'Y');
	return 0;
}
