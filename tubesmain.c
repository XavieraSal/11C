#include "xaviera.h"
#include "arya.h"

int main() {
	warna();
	int pilihan_film;
	int jumlah_kursi;
	int pembayaran;
    int lanjut = 1;
    int cho;
    int pil;
    int validInput;
    int i;
    int n;
    int num_seats;
    int seat_num;
    int pilih_loket;
    
    char ulang = 'y';
    
	address c;
	address plgn1;
	address plgn2;
	address bukti;
	
	address_studio sTemp;
	address_studio s; //variable untuk modul enqueue : address studio
//	address_studio ;
	
	address_loket Loket = Nil;
	address_loket Lkt;
	
	address_studio now = Nil;
	
	address_studio head = Nil;
	
	address_Seat depan = Nil;
	
	antrean q = {Nil, Nil}; //variable untuk modul enqueue  : pengunjung
	antrean q2 = {Nil, Nil}; //variable untuk modul enqueue : pengunjung
	
	infotype input; //variable untuk menampung info pelanggan
	
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
		printf("\t\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
		printf("\t\t\tInput : ");
		scanf("%d", &pil);
		switch(pil)
		{
			case 1:
				validInput = 0;
				while (!validInput)
				{
					printf("\n\t\t\t\t\tAda berapa customer di bioskop?\t");
					if (scanf("\n%d", &n) == 1)
					{
						validInput = 1;
						for (i = 1; i <= n; i++)
						{
							printf("\n\t\t\t\t\tMasukkan namanya: ");
							fflush(stdin);
							scanf("%s", &input);
							enqueue(&q, input, s);
						}
					}
					else
					{
						printf("\t\t\t\t     Input tidak valid. Mohon masukkan angka.\n");
						while (getchar() != '\n');
					}
				}
				break;
				
			case 2:
				if (!cekKosong(q))
				{
					do
					{
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
				
				/*masih error
				addPrintFilm(&head, &now, &s); */
				//addPrintFilm(&head, &now, &s);
				sTemp = s;
				printf("\nStudio");

				address_loket Loket_1;
				address_loket Loket_2;
				
				Loket_1 = Locket(1, sTemp, q2.head); //modul untuk mengambil customer dari q2 untuk dilayani
				Loket_2 = Locket(2, sTemp, q2.head);
				
				/*Tracing apakah berhasil pindah ke loket
				NodeToEmptyLoket(&q2.head, Loket_1, Loket_2);
				printf("\n ini kondisi q2 setelah move node utk lkt 1:\n");
				PrintA(q2);
				NodeToEmptyLoket(&q2.head, Loket_1, Loket_2);
				printf("\n ini kondisi q2 setelah move node utk lkt 2:\n");
				PrintA(q2); */
				
				printf("Loket_1: ");
				Print_Loket (Loket_1);
				printf("Loket_2: ");
				Print_Loket (Loket_2);
				
				printf("Pilih loket yang ingin dilayani :");
				scanf("%d", &pilih_loket);

				int p;
				switch (pilih_loket)
				{
					case 1:
					printf("Pilih film : ");
					scanf("%d", &p);
					while(Loket_1->bwh_studio->studio != p){
//						studio = studio->next_st;
					}
//					Loket_1->lkt_cus->cus_std = sTemp->next_fl;

				}
			    while (lanjut)
				{
			        printf("Pilih film yang ingin ditonton (1-3): ");
			        scanf("%d", &pilihan_film);

			        printf("Berapa banyak kursi yang ingin Anda pesan? ");
			        scanf("%d", &jumlah_kursi);

			        printf("Masukkan jumlah pembayaran: ");
			        scanf("%d", &pembayaran);

			        tampilkan_kursi_tersedia();

			        if (pilihan_film >= 1 && pilihan_film <= JUMLAH_FILM)
					{
			            printf("Anda telah memilih Film %c.\n", 'A' + pilihan_film - 1);
			            pesan_kursi(pilihan_film - 1, jumlah_kursi, pembayaran);
			        }
					else
					{
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
