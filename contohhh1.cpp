#include <iostream>
using namespace std;

// Deklarasi struktur data nilai MK
typedef struct {
    string kode;
    string nama_barang;
    int stock;
} NilaiMK;

// Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

// Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} queue;

// Fungsi membuat queue kosong
void buatQKosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// Fungsi cek queue kosong
int isKosong(queue Q) {
    bool hasil = false;

    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

// Fungsi menghitung jumlah elemen
int jmlElemen(queue Q) {
    int hasil = 0;

    if (Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;

        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

// Fungsi menambah elemen (enqueue)
void add(string kode, string nama_barang, int stock, queue *Q) {
    elemen *info;
    info = new elemen;

    info->Kontainer.kode = kode;
    info->Kontainer.nama_barang = nama_barang;
    info->Kontainer.stock = stock;
    info->next = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }

    (*Q).last = info;
    info = NULL;
}

// Fungsi menghapus elemen (dequeue)
void del(queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;

        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        } else {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }

        delete hapus;
    }
}

// Fungsi menampilkan queue
void CetakQueue(queue Q) {
    if (Q.first != NULL) {
        cout << "MENAMPILKAN QUEUE" << endl;

        elemen *bantu = Q.first;
        int i = 1;

        while (bantu != NULL) {
            cout << "-----------------------------" << endl;
            cout << "Elemen ke-" << i << endl;
            cout << "kode : " << bantu->Kontainer.kode << endl;
            cout << "Nama barang        : " << bantu->Kontainer.nama_barang << endl;
            cout << "Nilai stock       : " << bantu->Kontainer.stock << endl;

            bantu = bantu->next;
            i++;
        }
        cout << "-----------------------------" << endl;
    } else {
        cout << "Queue Kosong" << endl;
    }
}

// Main program
int main() {
    queue Q;

    buatQKosong(&Q);
    CetakQueue(Q);
    cout << endl << endl;

    cout << "=============================" << endl;

    add("4523210666", "hp", 8, &Q);
    add("4523210777", "laptop", 7, &Q);
    add("4523210888", "monitor", 9, &Q);
    add("4523210999", "mouse", 6, &Q);
    add("4523210555", "lampu", 7, &Q);


    CetakQueue(Q);

    cout << endl;
    cout << "=============================" << endl;

    del(&Q);
    CetakQueue(Q);

    cout << endl;

    del(&Q);
    CetakQueue(Q);

    cout << "=============================" << endl;

    return 0;
}