#include <stdio.h>

#define JUMLAH_FILM 3
#define JUMLAH_KURSI_PER_FILM 25
#define HARGA_TIKET 25000

int kursi_tersedia[JUMLAH_FILM] = {JUMLAH_KURSI_PER_FILM, JUMLAH_KURSI_PER_FILM, JUMLAH_KURSI_PER_FILM};

void tampilkan_kursi_tersedia() {
    printf("Jumlah kursi yang tersedia:\n");
    for (int i = 0; i < JUMLAH_FILM; i++) {
        printf("Film %c: %d\n", 'A' + i, kursi_tersedia[i]);
    }
    printf("\n");
}

void pesan_kursi(int pilihan_film, int jumlah_kursi, int pembayaran) {
    int total_harga = jumlah_kursi * HARGA_TIKET;

    if (pilihan_film < 0 || pilihan_film >= JUMLAH_FILM) {
        printf("Pilihan film tidak valid.\n");
        return;
    }

    if (pembayaran < total_harga) {
        printf("Maaf, pembayaran Anda kurang. Total harga: %d\n", total_harga);
        printf("Apakah Anda ingin melakukan pembayaran ulang? (1 = Ya, 0 = Tidak): ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Masukkan jumlah pembayaran tambahan: ");
            int tambahan_pembayaran;
            scanf("%d", &tambahan_pembayaran);
            pesan_kursi(pilihan_film, jumlah_kursi, pembayaran + tambahan_pembayaran);
        } else {
            printf("Pemesanan dibatalkan.\n");
        }
    } else {
        if (jumlah_kursi <= kursi_tersedia[pilihan_film]) {
            kursi_tersedia[pilihan_film] -= jumlah_kursi;
            int kembalian = pembayaran - total_harga;
            printf("Anda telah memesan %d kursi untuk Film %c. Total harga: %d\n", jumlah_kursi, 'A' + pilihan_film, total_harga);
            printf("Pembayaran berhasil. Kembalian Anda: %d\n", kembalian);
        } else {
            printf("Maaf, kursi yang tersedia untuk Film %c tidak mencukupi.\n", 'A' + pilihan_film);
            printf("Apakah Anda ingin mengurangi jumlah kursi yang dipesan? (1 = Ya, 0 = Tidak): ");
            int pilihan;
            scanf("%d", &pilihan);

            if (pilihan == 1) {
                printf("Masukkan jumlah kursi yang ingin dikurangi: ");
                int kursi_dikurangi;
                scanf("%d", &kursi_dikurangi);
                pesan_kursi(pilihan_film, jumlah_kursi - kursi_dikurangi, pembayaran);
            } else {
                printf("Pemesanan dibatalkan.\n");
            }
        }
    }
}

int main() {
    printf("Selamat datang di Bioskop XYZ!\n");
    printf("Daftar film yang sedang tayang:\n");
    printf("1. Film A\n");
    printf("2. Film B\n");
    printf("3. Film C\n");

    int pilihan_film, jumlah_kursi, pembayaran;
    int lanjut = 1;

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

    return 0;
}

