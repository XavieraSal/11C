#include "arya.h"

int cekKosong (antrean q) {
	int k;

	k = q.head == Nil && q.tail == Nil;
	return k;
}

address_studio sStudio (infotype1 j, address_film mov) {
	address_studio A;

	A = (address_studio)malloc(sizeof(studio));
	if (A != Nil) {
		A->studio = j;
		A->next_fl = mov;
		A->next_st = Nil;
	}
	return A;
}

address_loket alokasiLoket (infotype1 j, address_studio stud, address cust) {
	address_loket L;
	L = (address_loket)malloc(sizeof(Loket));

	if (L != Nil) {
		L->bwh_studio = stud;
		L->loket = j;
		while (cust->next != Nil) {
			cust = cust->next;
		}
		L->lkt_cus = cust->next;
		L->next_loket = Nil;
	}
	return L;
}

address_loket Locket (infotype1 j, address_studio stud, address cust) {
	address_loket L, R;
//	L = alokasiLoket(j, stud, cust);
//	int i;
//	L->loket = 1;
//	R = L;
	if (R != Nil) {
//		for (i = 1; i < 3; i++) {
		R/*->next_loket*/ = alokasiLoket(j, stud, cust);
//			R->loket = i;
//		printf("%d ", R->bwh_studio->studio);
//			R = R->next_loket;
//		}
//		R->next_loket = L;
	}
	return R;
}


//void tampilkan_kursi_tersedia() {
//	int i;
//	int kursi_tersedia[JUMLAH_FILM] = {JUMLAH_KURSI_PER_FILM, JUMLAH_KURSI_PER_FILM, JUMLAH_KURSI_PER_FILM};
//	printf("Jumlah kursi yang tersedia:\n");
//	for ( i = 0; i < JUMLAH_FILM; i++) {
//		printf("Film %c: %d\n", 'A' + i, kursi_tersedia[i]);
//	}
//	printf("\n");
//}
//
//void pesan_kursi(int pilihan_film, int jumlah_kursi, int pembayaran) {
//	int kursi_tersedia[JUMLAH_FILM] = {JUMLAH_KURSI_PER_FILM, JUMLAH_KURSI_PER_FILM, JUMLAH_KURSI_PER_FILM};
//	int total_harga = jumlah_kursi * SEAT_PRICE;
//
//	if (pilihan_film < 0 || pilihan_film >= JUMLAH_FILM) {
//		printf("Pilihan film tidak valid.\n");
//		return;
//	}
//
//	if (pembayaran < total_harga) {
//		printf("Maaf, pembayaran Anda kurang. Total harga: %d\n", total_harga);
//		printf("Apakah Anda ingin melakukan pembayaran ulang? (1 = Ya, 0 = Tidak): ");
//		int pilihan;
//		scanf("%d", &pilihan);
//
//		if (pilihan == 1) {
//			printf("Masukkan jumlah pembayaran tambahan: ");
//			int tambahan_pembayaran;
//			scanf("%d", &tambahan_pembayaran);
//			pesan_kursi(pilihan_film, jumlah_kursi, pembayaran + tambahan_pembayaran);
//		} else {
//			printf("Pemesanan dibatalkan.\n");
//		}
//	} else {
//		if (jumlah_kursi <= kursi_tersedia[pilihan_film]) {
//			kursi_tersedia[pilihan_film] -= jumlah_kursi;
//			int kembalian = pembayaran - total_harga;
//			printf("Anda telah memesan %d kursi untuk Film %c. Total harga: %d\n", jumlah_kursi, 'A' + pilihan_film, total_harga);
//			printf("Pembayaran berhasil. Kembalian Anda: %d\n", kembalian);
//		} else {
//			printf("Maaf, kursi yang tersedia untuk Film %c tidak mencukupi.\n", 'A' + pilihan_film);
//			printf("Apakah Anda ingin mengurangi jumlah kursi yang dipesan? (1 = Ya, 0 = Tidak): ");
//			int pilihan;
//			scanf("%d", &pilihan);
//
//			if (pilihan == 1) {
//				printf("Masukkan jumlah kursi yang ingin dikurangi: ");
//				int kursi_dikurangi;
//				scanf("%d", &kursi_dikurangi);
//				pesan_kursi(pilihan_film, jumlah_kursi - kursi_dikurangi, pembayaran);
//			} else {
//				printf("Pemesanan dibatalkan.\n");
//			}
//		}
//	}
//}

address_jam Alokasi_Jam(/*address_jam j, */infotype2 jam) {
	address_jam j;
	int i;
	printf("%f", jam);
	j = (address_jam)malloc (sizeof(Jam));
	if(j == Nil) {
		j->bwh_se = Nil;
		j->jamtyng = jam;
		j->next_jam = Nil;
	}
	return j;
}

address_film movie(infotype nama, infotype2 sjam[][3]) {
	address_jam JM, jm;
	address_film f;
	int i, j;
	f = (address_film)malloc (sizeof(Film));

	if (f != Nil) {
		f->nm_film = nama;
		if(f->nm_film == "The Batman") {
			i = 0;
		} else if(f->nm_film == "Dune") {
			i = 1;
		} else if(f->nm_film == "Barbie") {
			i = 2;
		}
		for (j = 0; j < 3; j++) {
			if(jm == Nil) {
				JM = Alokasi_Jam(sjam[i][j]);
				jm = JM;
			} else {
				jm = jm->next_jam;
				jm = Alokasi_Jam(sjam[i][j]);
			}
		}
		f->jm_tyg = JM;
		printf("film %s jam %f, %f, %f\n",f->nm_film, f->jm_tyg->jamtyng, f->jm_tyg->next_jam->jamtyng, f->jm_tyg->next_jam->next_jam->jamtyng);
	} else {
		printf("Alokasi gagal");
	}
	return(f);
}

address_studio add_studio(address_studio first) {
	infotype1 i;
	address_film mov;
	address_studio s;
	address_studio last;

	for (i = 0; i < 3; i++) {
		s = sStudio(i+1, mov); //modul alokasi untuk node bertipe studio
		if (s != Nil) {
			if (first == Nil) {
				first = s;
			} else {
				last = first;
				while (last->next_st != Nil) {
					last = last->next_st;
				}
				last->next_st = s;
			}
		}
	}
	return first;
}

address_studio add_studio2(address_studio pirst) {
	pirst = Nil;
	int i;

	if(pirst == NULL) {
		for(i = 1; i <= 1; i++) {
			pirst = add_studio(pirst); //pirst menunjuk node awal dari rangkaian node yg terben
		}
	}
	return pirst;
}

void add_film(address_studio *first, address_studio *now) {
	infotype nama_film[] = {"The Batman", "Dune", "Barbie"};
	infotype2 jam_tayang[3][3]/* = {{10.00, 13.00, 16.00}, {11.00, 14.00, 17.00}, {12.00, 15.00, 18.00}}*/;
	jam_tayang[0][0] = 10.00;
	jam_tayang[0][1] = 13.00;
	jam_tayang[0][2] = 16.00;
	jam_tayang[1][0] = 11.00;
	jam_tayang[1][1] = 14.00;
	jam_tayang[1][2] = 17.00;
	jam_tayang[2][0] = 12.00;
	jam_tayang[2][1] = 15.00;
	jam_tayang[2][2] = 18.00;
	int i;
	address_film f;

	for (i = 0; i < 3; i++) {
		f = movie(nama_film[i], jam_tayang); // alokasi untuk f sebagai variable node bertipe film
		printf("film %s jam %f, %f, %f\n",f->nm_film, f->jm_tyg->jamtyng, f->jm_tyg->next_jam->jamtyng, f->jm_tyg->next_jam->next_jam->jamtyng);
		if ((*first)->next_fl != Nil) {
			if ((*first)->next_fl == Nil) {
				(*first)->next_fl = f;
				(*now) = (*first);
			} else {
				(*now) = (*now)->next_st;
				(*now)->next_fl = f;
			}
		}
	}
}

void print_film(address_film current, address_studio *pirst) {
	printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
	printf("\t\t\t\xB3%12s\xB3%24s\xB3%24s\xB3%12s\xB3\n", "   Studio   ", "     Nama Film      ", "Jam         ", "   Harga   ");
	printf("\t\t\t\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n");
	int i, j;
	address_studio first;
	*pirst = add_studio2(*pirst);
	first = *pirst;

	while (current != Nil) {
		int j;
		printf("\t\t\t\xB3%12d\xB3%24s\xB3", first->studio, current->nm_film);
		for ( j = 0; j < 3; j++) {
			printf("%-8.2f", current->jm_tyg[j]);
		}
		first = (first)->next_st;
//		current = current->next_fl;
		printf("\xB3%12s\xB3\n", "  25.000   ");
	}
	printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
}

void addPrintFilm(address_studio *head, address_studio *now, address_studio *first) {
	if (*head == Nil) {
		add_film(head, now); //modul untuk membentuk rentetan node bertipe film
	}
//	printf("Studio %d \nNama Film : %s\nJam Tayang : %f", (*head)->next_st->studio, (*head)->next_fl->nm_film, (*head)->next_fl->jm_tyg->jamtyng);
//	print_film(*head, first);
}

/*Membuat status awal kursi "Belum dipesan"*/
address_Seat create_seats() {
	int i;
	address_Seat head = NULL;
	address_Seat tampung;

	for(i=MAX_SEATS; i>=1; i--) {
		tampung = (address_Seat)malloc(sizeof(Seat));
		tampung->seat_number = i;
		tampung->is_booked = 0;
		tampung->next_seat = head;
		head = tampung;
	}

	return head;
}


/*Vico*/
/*Menampilkan jumlah kursi yang masih tersedia*/
void display_seats(address_Seat head) {
	address_Seat tampung = head;

	while(tampung != NULL) {
		if(tampung->is_booked) {
			printf("X ");
		} else {
			printf("%d ", tampung->seat_number);
		}
		tampung = tampung->next_seat;
	}

	printf("\n");
}

/*Memesan kursi*/
void book_seat(address_Seat head, int num_seats, SeatHistory **history_head) {
	address_Seat tampung = head;
	int hitung = 0;
	int total_price = 0;

	while(tampung != NULL && hitung < num_seats) {
		if(!tampung->is_booked) {
			tampung->is_booked = 1;
			hitung++;
			total_price += SEAT_PRICE;

			// Simpan riwayat pembelian kursi
			SeatHistory *new_history = (SeatHistory *)malloc(sizeof(SeatHistory));
			new_history->seat_number = tampung->seat_number;
			new_history->price = SEAT_PRICE;
			new_history->next_history = *history_head;
			*history_head = new_history;
		}
		tampung = tampung->next_seat;
	}

	printf("\nTotal harga: Rp %d\n", total_price);
}

/*Memesan kursi yang dapat diatur sebanyak yang diinginkan*/
void book_seats(address_Seat head, SeatHistory **history_head) {
	int jumlah, nomor_kursi, i;
	address_Seat tampung;

	printf("\nBanyaknya kursi : ");
	scanf("%d", &jumlah);

	if(jumlah > 0 && jumlah <= 25) {
		printf("Masukan nomor kursi yang ingin di ambil (Gunakan spasi jika lebih dari 1 ): ");

		for( i = 0; i < jumlah; i++) {
			scanf("%d", &nomor_kursi);

			if(nomor_kursi < 1 || nomor_kursi > 25) {
				printf("Invalid seat number. Please try again.\n");
				break;
			} else if(head == NULL) {
				printf("The cinema has not been set up yet.\n");
				break;
			} else {
				tampung = head;

				while(tampung != NULL) {
					if(tampung->seat_number == nomor_kursi) {
						if(tampung->is_booked) {
							printf("Seat number %d is already booked.\n", nomor_kursi);
							break;
						} else {
							tampung->is_booked = 1;

							// Simpan riwayat pembelian kursi
							SeatHistory *new_history = (SeatHistory *)malloc(sizeof(SeatHistory));
							new_history->seat_number = tampung->seat_number;
							new_history->price = SEAT_PRICE;
							new_history->next_history = *history_head;
							*history_head = new_history;

							printf("Seat number %d has been booked.\n", nomor_kursi);
							break;
						}
					}
					tampung = tampung->next_seat;
				}

				if(tampung == NULL) {
					printf("Invalid seat number. Please try again.\n");
				}
			}
		}
	}
}

/*Menghapus riwayat pembelian kursi*/
void clear_history(SeatHistory **history_head) {
	SeatHistory *current_history = *history_head;
	SeatHistory *next_history;

	while(current_history != NULL) {
		next_history = current_history->next_history;
		free(current_history);
		current_history = next_history;
	}

	*history_head = NULL;
}

/*Menampilkan riwayat pembelian kursi*/
void display_history(SeatHistory *history_head) {
	SeatHistory *current_history = history_head;

	while(current_history != NULL) {
		printf("Seat number %d, Rp %d\n", current_history->seat_number, current_history->price);
		current_history = current_history->next_history;
	}
}
