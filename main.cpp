#include <iostream>
#include "tubes.h"
using namespace std;

int main(){
    ListWisata L;
    adrWisata wisata;
    adrWisata hasil;
    adrWahana wahana;

    string idWisata, idWahana;
    string nama, lokasi, kota, jenis, statusOperasional;
    int hargaTiket, tinggiMinimum, biayaTambahan;
    int pilihan, jumlah;

    createListWisata(L);

    pilihan = -1;

    while (pilihan != 0) {
        cout << "\n================================" << endl;
        cout << "       WONDERPARK MANAGEMENT" << endl;
        cout << "================================" << endl;
        cout << "1. Tambah Wisata" << endl;
        cout << "2. Tambah Wahana" << endl;
        cout << "3. Cari Wisata berdasarkan Lokasi" << endl;
        cout << "4. Cari Wahana berdasarkan Jenis Wahana" << endl;
        cout << "5. Hapus Wisata" << endl;
        cout << "6. Hapus Wahana" << endl;
        cout << "7. Tampilkan Data Wisata" << endl;
        cout << "8. Tampilkan Semua Data" << endl;
        cout << "9. Hitung Jumlah Wahana" << endl;
        cout << "10. Cari Wisata dengan Wahana Terbanyak" << endl;
        cout << "11. Hitung Total Harga Wisata dan Wahana" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

      if (pilihan == 1) {
        cout << "\n=== TAMBAH DATA WISATA ===" << endl;

        cout << "ID Wisata       : ";
        cin >> idWisata;

        searchWisataByID(L, idWisata, wisata);

        if (wisata == nullptr) {
            cout << "Nama Wisata     : ";
        cin >> nama;
        cout << "Lokasi          : ";
        cin >> lokasi;
        cout << "Kota            : ";
        cin >> kota;
        cout << "Jenis Wisata    : ";
        cin >> jenis;
        cout << "Harga Tiket     : ";
        cin >> hargaTiket;

        wisata = createElemenWisata(idWisata, nama, lokasi, kota, jenis, hargaTiket);
        insertLastWisata(L, wisata);

        cout << "Data wisata berhasil ditambahkan." << endl;
        } else {
        cout << "ID wisata sudah digunakan." << endl;
        }
    } else if (pilihan == 2) {
        cout << "\n=== TAMBAH DATA WAHANA ===" << endl;

        cout << "Masukkan ID Wisata: ";
        cin >> idWisata;

        searchWisataByID(L, idWisata, wisata);

        if (wisata != nullptr) {
        cout << "ID Wahana          : ";
        cin >> idWahana;
        cout << "Nama Wahana        : ";
        cin >> nama;
        cout << "Jenis Wahana       : ";
        cin >> jenis;
        cout << "Tinggi Minimum (cm): ";
        cin >> tinggiMinimum;
        cout << "Status Operasional : ";
        cin >> statusOperasional;
        cout << "Biaya Tambahan     : ";
        cin >> biayaTambahan;

        searchWahanaByID(wisata, idWahana, wahana);

        if (wahana == nullptr) {
            wahana = createElemenWahana(idWahana, nama, jenis, tinggiMinimum, statusOperasional, biayaTambahan);
            insertLastWahana(wisata, wahana);

            cout << "Data wahana berhasil ditambahkan." << endl;
            } else {
                cout << "ID wahana sudah digunakan pada wisata tersebut." << endl;
            }
        } else {
            cout << "Data wisata tidak ditemukan." << endl;
        }

    } else if (pilihan == 3) {
        cout << "\n=== CARI WISATA BERDASARKAN LOKASI ===" << endl;
        cout << "Masukkan Lokasi: ";
        cin >> lokasi;

        searchWisataByLokasi(L, lokasi);

        } else if (pilihan == 4) {
            cout << "\n=== CARI WAHANA BERDASARKAN JENIS ===" << endl;

            cout << "Masukkan ID Wisata: ";
            cin >> idWisata;

            searchWisataByID(L, idWisata, wisata);

            if (wisata != nullptr) {
            cout << "Masukkan Jenis Wahana: ";
            cin >> jenis;

            searchWahanaByJenis(wisata, jenis);
        } else {
        cout << "Data wisata tidak ditemukan." << endl;
        }
    } else if (pilihan == 5) {
            cout << "\n=== HAPUS DATA WISATA ===" << endl;

            cout << "Masukkan ID Wisata: ";
            cin >> idWisata;

            deleteWisata(L, idWisata);

    } else if (pilihan == 6) {
            cout << "\n=== HAPUS DATA WAHANA ===" << endl;

            cout << "Masukkan ID Wisata: ";
            cin >> idWisata;

            searchWisataByID(L, idWisata, wisata);

            if (wisata != nullptr) {
                cout << "Masukkan ID Wahana: ";
                cin >> idWahana;

                deleteWahana(wisata, idWahana);
            } else {
                cout << "Data wisata tidak ditemukan." << endl;
            }

    } else if (pilihan == 7) {
        cout << "\n=== DAFTAR WISATA ===" << endl;

        printWisata(L);

    } else if (pilihan == 8) {
            cout << "\n=== SELURUH DATA WONDERPARK ===" << endl;

            printAll(L);

    } else if (pilihan == 9) {
            cout << "\n=== HITUNG JUMLAH WAHANA ===" << endl;

            cout << "Masukkan ID Wisata: ";
            cin >> idWisata;

            searchWisataByID(L, idWisata, wisata);

            if (wisata != nullptr) {
                jumlah = hitungWahana(wisata);

                cout << "Nama Wisata       : " << wisata->info.nama << endl;
                cout << "Jumlah Wahana     : " << jumlah << endl;
            } else {
                cout << "Data wisata tidak ditemukan." << endl;
            }

    } else if (pilihan == 10) {
            cout << "\n=== WISATA DENGAN WAHANA TERBANYAK ===" << endl;

            cariWisataTerbanyak(L, hasil);

            if (hasil != nullptr) {
                cout << "ID Wisata         : " << hasil->info.id << endl;
                cout << "Nama Wisata       : " << hasil->info.nama << endl;
                cout << "Lokasi            : " << hasil->info.lokasi << endl;
                cout << "Jumlah Wahana     : " << hitungWahana(hasil) << endl;
            } else {
                cout << "Data wisata masih kosong." << endl;
            }

    } else if (pilihan == 11) {
            cout << "\n=== HITUNG TOTAL HARGA ===" << endl;

            cout << "Masukkan ID Wisata: ";
            cin >> idWisata;

            searchWisataByID(L, idWisata, wisata);

            if (wisata != nullptr) {
            cout << "\nNama Wisata : " << wisata->info.nama << endl;
            cout << "Harga Tiket : Rp" << wisata->info.hargaTiket << endl;

            cout << "\nMasukkan ID Wahana: ";
            cin >> idWahana;

            searchWahanaByID(wisata, idWahana, wahana);

            if (wahana != nullptr) {
            jumlah = hitungTotalHarga(wisata, wahana);

            cout << "\n=== RINCIAN PEMBAYARAN ===" << endl;
            cout << "Wisata          : " << wisata->info.nama << endl;
            cout << "Wahana          : " << wahana->info.nama << endl;
            cout << "Harga Tiket     : Rp" << wisata->info.hargaTiket << endl;
            cout << "Biaya Wahana    : Rp" << wahana->info.biayaTambahan << endl;
            cout << "-----------------------------" << endl;
            cout << "Total Harga     : Rp" << jumlah << endl;
        } else {
            cout << "Data wahana tidak ditemukan." << endl;
        }
    } else if (pilihan == 0) {
            cout << "Program WonderPark Management selesai." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    }
    return 0;
}



