#include <iostream>
#include "tubes.h"

void createListWisata(ListWisata &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyWisata(ListWisata L) {
    return L.first == nullptr;
}

adrWisata createElemenWisata(string id, string nama, string lokasi, string kota, string jenis, int hargaTiket) {
    adrWisata wisata = new elemenWisata;

    wisata->info.id = id;
    wisata->info.nama = nama;
    wisata->info.lokasi = lokasi;
    wisata->info.kota = kota;
    wisata->info.jenis = jenis;
    wisata->info.hargaTiket = hargaTiket;

    wisata->next = nullptr;
    wisata->prev = nullptr;
    wisata->firstWahana = nullptr;

    return wisata;
}

void insertLastWisata(ListWisata &L, adrWisata wisata) {
    if (isEmptyWisata(L)) {
        L.first = wisata;
        L.last = wisata;
    } else {
        wisata->prev = L.last;
        L.last->next = wisata;
        L.last = wisata;
    }
}

void searchWisataByID(ListWisata L, string id, adrWisata &wisata) {
    wisata = L.first;

    while (wisata != nullptr && wisata->info.id != id) {
        wisata = wisata->next;
    }
}

void deleteFirstWisata(ListWisata &L, adrWisata &wisata) {
    if (!isEmptyWisata(L)) {
        wisata = L.first;

        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = wisata->next;
            L.first->prev = nullptr;
        }

        wisata->next = nullptr;
        wisata->prev = nullptr;
    } else {
        wisata = nullptr;
    }
}

void deleteLastWisata(ListWisata &L, adrWisata &wisata) {
    if (!isEmptyWisata(L)) {
        wisata = L.last;

        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = wisata->prev;
            L.last->next = nullptr;
        }

        wisata->next = nullptr;
        wisata->prev = nullptr;
    } else {
        wisata = nullptr;
    }
}

void deleteAfterWisata(ListWisata &L, adrWisata precWisata, adrWisata &wisata) {
    wisata = nullptr;

    if (precWisata != nullptr && precWisata->next != nullptr) {
        wisata = precWisata->next;

        if (wisata == L.last) {
            deleteLastWisata(L, wisata);
        } else {
            precWisata->next = wisata->next;
            wisata->next->prev = precWisata;

            wisata->next = nullptr;
            wisata->prev = nullptr;
        }
    }
}

void deleteWisata(ListWisata &L, string id) {
    adrWisata wisata;
    adrWisata precWisata;
    adrWisata hapus;

    searchWisataByID(L, id, wisata);

    if (wisata != nullptr) {
        deleteAllWahana(wisata);

        if (wisata == L.first) {
            deleteFirstWisata(L, hapus);
        } else if (wisata == L.last) {
            deleteLastWisata(L, hapus);
        } else {
            precWisata = wisata->prev;
            deleteAfterWisata(L, precWisata, hapus);
        }

        cout << "Data wisata berhasil dihapus." << endl;
    } else {
        cout << "Data wisata tidak ditemukan." << endl;
    }
}

void searchWisataByLokasi(ListWisata L, string lokasi) {
    adrWisata wisata = L.first;
    bool ditemukan = false;

    while (wisata != nullptr) {
        if (wisata->info.lokasi == lokasi) {
            cout << "ID Wisata    : " << wisata->info.id << endl;
            cout << "Nama Wisata  : " << wisata->info.nama << endl;
            cout << "Lokasi       : " << wisata->info.lokasi << endl;
            cout << "Kota         : " << wisata->info.kota << endl;
            cout << "Jenis Wisata : " << wisata->info.jenis << endl;
            cout << "Harga Tiket  : " << wisata->info.hargaTiket << endl;
            cout << "------------------------" << endl;

            ditemukan = true;
        }

        wisata = wisata->next;
    }

    if (!ditemukan) {
        cout << "Wisata berdasarkan lokasi tidak ditemukan." << endl;
    }
}

bool isEmptyWahana(adrWisata wisata) {
    return wisata == nullptr || wisata->firstWahana == nullptr;
}

adrWahana createElemenWahana(string id, string nama, string jenis, int tinggiMinimum, string statusOperasional, int biayaTambahan) {
    adrWahana wahana = new elemenWahana;

    wahana->info.id = id;
    wahana->info.nama = nama;
    wahana->info.jenis = jenis;
    wahana->info.tinggiMinimum = tinggiMinimum;
    wahana->info.statusOperasional = statusOperasional;
    wahana->info.biayaTambahan = biayaTambahan;

    wahana->next = nullptr;
    wahana->prev = nullptr;

    return wahana;
}

void insertLastWahana(adrWisata wisata, adrWahana wahana) {
    if (wisata != nullptr) {
        if (isEmptyWahana(wisata)) {
            wisata->firstWahana = wahana;
        } else {
            adrWahana precWahana = wisata->firstWahana;

            while (precWahana->next != nullptr) {
                precWahana = precWahana->next;
            }

            precWahana->next = wahana;
            wahana->prev = precWahana;
        }
    }
}

void searchWahanaByID(adrWisata wisata, string id, adrWahana &wahana) {
    wahana = nullptr;

    if (wisata != nullptr) {
        wahana = wisata->firstWahana;

        while (wahana != nullptr && wahana->info.id != id) {
            wahana = wahana->next;
        }
    }
}

void deleteFirstWahana(adrWisata wisata, adrWahana &wahana) {
    if (!isEmptyWahana(wisata)) {
        wahana = wisata->firstWahana;

        wisata->firstWahana = wahana->next;

        if (wisata->firstWahana != nullptr) {
            wisata->firstWahana->prev = nullptr;
        }

        wahana->next = nullptr;
        wahana->prev = nullptr;
    } else {
        wahana = nullptr;
    }
}

void deleteLastWahana(adrWisata wisata, adrWahana &wahana) {
    wahana = nullptr;

    if (!isEmptyWahana(wisata)) {
        adrWahana precWahana = wisata->firstWahana;

        while (precWahana->next != nullptr) {
            precWahana = precWahana->next;
        }
        wahana = precWahana;
        if (wahana->prev == nullptr) {
            wisata->firstWahana = nullptr;
        } else {
            wahana->prev->next = nullptr;
        }
        wahana->next = nullptr;
        wahana->prev = nullptr;
    }
}

void deleteAfterWahana(adrWisata wisata, adrWahana precWahana, adrWahana &wahana) {
    wahana = nullptr;

    if (wisata != nullptr && precWahana != nullptr && precWahana->next != nullptr) {
        wahana = precWahana->next;

        if (wahana->next == nullptr) {
            deleteLastWahana(wisata, wahana);
        } else {
            precWahana->next = wahana->next;
            wahana->next->prev = precWahana;
            wahana->next = nullptr;
            wahana->prev = nullptr;
        }
    }
}

void deleteWahana(adrWisata wisata, string id) {
    adrWahana wahana;
    adrWahana precWahana;
    adrWahana hapus;

    searchWahanaByID(wisata, id, wahana);

    if (wahana != nullptr) {
        if (wahana == wisata->firstWahana) {
            deleteFirstWahana(wisata, hapus);
        } else if (wahana->next == nullptr) {
            deleteLastWahana(wisata, hapus);
        } else {
            precWahana = wahana->prev;
            deleteAfterWahana(wisata, precWahana, hapus);
        }
        cout << "Data wahana berhasil dihapus." << endl;
    } else {
        cout << "Data wahana tidak ditemukan." << endl;
    }
}

void deleteAllWahana(adrWisata wisata) {
    adrWahana wahana;

    while (!isEmptyWahana(wisata)) {
        deleteFirstWahana(wisata, wahana);
    }
}


int hitungWahana(adrWisata wisata) {
    int jumlah = 0;
    adrWahana wahana;

    if (wisata != nullptr) {
        wahana = wisata->firstWahana;
        while (wahana != nullptr) {
            jumlah++;
            wahana = wahana->next;
        }
    }
    return jumlah;
}
void searchWahanaByJenis(adrWisata wisata, string jenis) {
    adrWahana wahana;
    bool ditemukan = false;

    if (wisata != nullptr) {
        wahana = wisata->firstWahana;

        while (wahana != nullptr) {
            if (wahana->info.jenis == jenis) {
                cout << "ID Wahana   : " << wahana->info.id << endl;
                cout << "Nama Wahana : " << wahana->info.nama << endl;
                cout << "Jenis       : " << wahana->info.jenis << endl;
                cout << "------------------------" << endl;
                ditemukan = true;
            }
            wahana = wahana->next;
        }
    }
    if (!ditemukan) {
        cout << "Wahana berdasarkan jenis tidak ditemukan." << endl;
    }
}
void cariWisataTerbanyak(ListWisata L, adrWisata &hasil) {
    adrWisata wisata = L.first;
    int jumlahTerbanyak = -1;

    hasil = nullptr;

    while (wisata != nullptr) {
        if (hitungWahana(wisata) > jumlahTerbanyak) {
            jumlahTerbanyak = hitungWahana(wisata);
            hasil = wisata;
        }

        wisata = wisata->next;
    }
}

int hitungTotalHarga(adrWisata wisata, adrWahana wahana) {
    int total = 0;

    if (wisata != nullptr && wahana != nullptr) {
        total = wisata->info.hargaTiket + wahana->info.biayaTambahan;
    }
    return total;
}

void printWisata(ListWisata L) {
    adrWisata wisata = L.first;

    if (isEmptyWisata(L)) {
        cout << "Data wisata masih kosong." << endl;
    } else {
        while (wisata != nullptr) {
            cout << "ID Wisata       : " << wisata->info.id << endl;
            cout << "Nama Wisata     : " << wisata->info.nama << endl;
            cout << "Lokasi          : " << wisata->info.lokasi << endl;
            cout << "Kota            : " << wisata->info.kota << endl;
            cout << "Jenis Wisata    : " << wisata->info.jenis << endl;
            cout << "Harga Tiket     : " << wisata->info.hargaTiket << endl;
            cout << "------------------------------" << endl;

            wisata = wisata->next;
        }
    }
}

void printWahana(adrWisata wisata) {
    adrWahana wahana;

    if (isEmptyWahana(wisata)) {
        cout << "Belum ada wahana." << endl;
    } else {
        wahana = wisata->firstWahana;
        while (wahana != nullptr) {
            cout << "  ID Wahana          : " << wahana->info.id << endl;
            cout << "  Nama Wahana        : " << wahana->info.nama << endl;
            cout << "  Jenis Wahana       : " << wahana->info.jenis << endl;
            cout << "  Tinggi Minimum     : " << wahana->info.tinggiMinimum << " cm" << endl;
            cout << "  Status Operasional : " << wahana->info.statusOperasional << endl;
            cout << "  Biaya Tambahan     : " << wahana->info.biayaTambahan << endl;
            cout << "  ----------------------------" << endl;

            wahana = wahana->next;
        }
    }
}

void printAll(ListWisata L) {
    adrWisata wisata = L.first;

    if (isEmptyWisata(L)) {
        cout << "Data WonderPark masih kosong." << endl;
    } else {
        while (wisata != nullptr) {
            cout << "\n================================" << endl;
            cout << "         DATA TEMPAT WISATA" << endl;
            cout << "================================" << endl;

            cout << "ID Wisata       : " << wisata->info.id << endl;
            cout << "Nama Wisata     : " << wisata->info.nama << endl;
            cout << "Lokasi          : " << wisata->info.lokasi << endl;
            cout << "Kota            : " << wisata->info.kota << endl;
            cout << "Jenis Wisata    : " << wisata->info.jenis << endl;
            cout << "Harga Tiket     : " << wisata->info.hargaTiket << endl;

            cout << "\n         DAFTAR WAHANA" << endl;
            printWahana(wisata);

            wisata = wisata->next;
        }

        cout << "================================" << endl;
    }
}
