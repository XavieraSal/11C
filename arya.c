#include "arya.h"

address_studio sStudio (infotype1 j, address_film mov) {
	address_studio A = (address_studio)malloc(sizeof(studio));
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
		L->lkt_cus = cust;
		L->next_loket = Nil;
	}
	return L;
}

address_loket Locket (infotype1 j, address_studio stud, address cust) {
	address_loket L, R;
	int i;
	L = alokasiLoket(j, stud, cust);
	R = L;
	if (R != Nil) {
		for (i = 1; i < 3; i++) {
			R->next_loket = alokasiLoket(j+i, stud, cust);
			R = R->next_loket;
		}
		R->next_loket = L;
	}
	return R;
}

address_film movie(infotype nama, infotype2 jam[3]) {
	address_film f;
	int i;
	f = (address_film)malloc(sizeof(Film));
	if (f != Nil) {
		f->nm_film = nama;
		for (i = 0; i < 3; i++) {
			f->jm_tyg[i] = jam[i];
		}
		f->bwh_se = Nil;
		f->next_fl = Nil;
	} else {
		printf("Alokasi gagal");
	}
	return(f);
}

address_studio add_studio(address_studio first) {
	infotype1 i;
	address_film mov;
	for (i = 0; i < 3; i++) {
		address_studio s = sStudio(i+1, mov);
		if (s != Nil) {
			if (first == Nil) {
				first = s;
			} else {
				address_studio last = first;
				while (last->next_st != Nil) {
					last = last->next_st;
				}
				last->next_st = s;
			}
		}
	}
	return first;
}


void add_film(address_film *first, address_film *now) {
	infotype nama_film[] = {"The Batman", "Dune", "Barbie"};
	infotype2 jam_tayang[][3] = {{10.00, 13.00, 16.00}, {11.00, 14.00, 17.00}, {12.00, 15.00, 18.00}};
	int i;
	for (i = 0; i < 3; i++) {
		address_film f = movie(nama_film[i], jam_tayang[i]);
		if (f != Nil) {
			if (*first == Nil) {
				*first = f;
				*now = *first;
			} else {

				(*now)->next_fl = f;
				*now = f;
			}
		}
	}
}

void print_film(address_film current) {
	printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
	printf("\t\t\t\xB3%12s\xB3%24s\xB3%24s\xB3%12s\xB3\n", "   Studio   ", "     Nama Film      ", "Jam         ", "   Harga   ");
	printf("\t\t\t\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n");
	int i = 1;
	int j;
	address_studio first = Nil;
	if (first == Nil) {
		for (i = 1; i <= 1; i++) {
			first = add_studio(first);
		}
	}
	while (current != Nil) {
		printf("\t\t\t\xB3%12d\xB3%24s\xB3", first->studio, current->nm_film);
		for ( j = 0; j < 3; j++) {
			printf("%-8.2f", current->jm_tyg[j]);
		}
		first = first->next_st;
		current = current->next_fl;
		printf("\xB3%12s\xB3\n", "  45.000   ");
	}
	printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
}

void addPrintFilm(address_film *head, address_film *now) {
	if (*head == Nil) {
		add_film(head, now);
	}
	print_film(*head);
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