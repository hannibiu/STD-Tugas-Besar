#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <string>
using namespace std;

typedef struct elemenWisata *adrWisata;
typedef struct elemenWahana *adrWahana;

struct Wisata {
    string id;
    string nama;
    string lokasi;
    string kota;
    string jenis;
    int hargaTiket;
};

struct Wahana {
    string id;
    string nama;
    string jenis;
    int tinggiMinimum;
    string statusOperasional;
    int biayaTambahan;
};

struct elemenWisata {
    Wisata info;
    adrWisata next;
    adrWisata prev;
    adrWahana firstWahana;
};

struct elemenWahana {
    Wahana info;
    adrWahana next;
    adrWahana prev;
};

struct ListWisata {
    adrWisata first;
    adrWisata last;
};

// Parent
void createListWisata(ListWisata &L);
bool isEmptyWisata(ListWisata L);
adrWisata createElemenWisata(string id, string nama, string lokasi, string kota, string jenis, int hargaTiket);

void insertLastWisata(ListWisata &L, adrWisata wisata);
void searchWisataByID(ListWisata L, string id, adrWisata &wisata);

void deleteFirstWisata(ListWisata &L, adrWisata &wisata);
void deleteLastWisata(ListWisata &L, adrWisata &wisata);
void deleteAfterWisata(ListWisata &L, adrWisata precWisata, adrWisata &wisata);
void deleteWisata(ListWisata &L, string id);

// Child
bool isEmptyWahana(adrWisata wisata);
adrWahana createElemenWahana(string id, string nama, string jenis, int tinggiMinimum, string statusOperasional, int biayaTambahan);

void insertLastWahana(adrWisata wisata, adrWahana wahana);
void searchWahanaByID(adrWisata wisata, string id, adrWahana &wahana);

void deleteFirstWahana(adrWisata wisata, adrWahana &wahana);
void deleteLastWahana(adrWisata wisata, adrWahana &wahana);
void deleteAfterWahana(adrWisata wisata, adrWahana precWahana, adrWahana &wahana);
void deleteWahana(adrWisata wisata, string id);
void deleteAllWahana(adrWisata wisata);

// Display
void printWisata(ListWisata L);
void printWahana(adrWisata wisata);
void printAll(ListWisata L);

// Fitur Tambahan
int hitungWahana(adrWisata wisata);
void cariWisataTerbanyak(ListWisata L, adrWisata &hasil);
void searchWisataByLokasi(ListWisata L, string lokasi);
void searchWahanaByJenis(adrWisata wisata, string jenis);
int hitungTotalHarga(adrWisata wisata, adrWahana wahana);

#endif // TUBES_H_INCLUDED
