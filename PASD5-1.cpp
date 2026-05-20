#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} queue;


void buatQUkosong (queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isKosong (queue Q) {
    bool hasil = false;
    if(Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}


int jmlElemen (queue Q) {
    int hasil = 0;
    if (Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;
        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu -> next;
        }
    }
    return hasil;
}

void add(string npm, string nama_mhs, double nilai, queue *Q) {
    elemen *info;
    info = new elemen;
    info -> Kontainer.npm = npm;
    info -> Kontainer.nama_mhs = nama_mhs;
    info -> Kontainer.nilai = nilai;
    info -> next = NULL;

    if((*Q).first == NULL) {
        (*Q).first = info;
    }
    else {
        (*Q).last -> next = info;
    }
    (*Q).last = info;
    info = NULL;
}


void CetakQueue (queue Q) {
    if (Q.first != NULL) {
        cout << "\n>>> MENAMPILKAN QUEUE <<<" << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL) {
            cout << "--------------------------------" << endl;
            cout << "Elemen ke : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << bantu -> Kontainer.npm << endl;
            cout << "Nama Mahasiswa        : " << bantu -> Kontainer.nama_mhs << endl;
            cout << "Nilai Mahasiswa       : " << bantu -> Kontainer.nilai << endl;
            bantu = bantu -> next;
            i = i + 1;
        }
        cout << "--------------------------------" << endl;
    }
    else {
        cout << "Queue Kosong" << endl;
    }
}

int main() {
    queue Q;
    buatQUkosong (&Q);

    int jumlah;
    string input_npm, input_nama;
    double input_nilai;

    cout << "=== ANTRIAN MAHASISWA ===" << endl;
    cout << "IMPUT DATA : ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        cout << "\nInput Data ke-" << i << endl;
        cout << "NPM   : "; 
        cin >> input_npm;
        
        cin.ignore(); 
        cout << "Nama  : "; 
        getline(cin, input_nama);
        
        cout << "Nilai : "; 
        cin >> input_nilai;

     
        add(input_npm, input_nama, input_nilai, &Q);
    }

  
    CetakQueue(Q);

    return 0;
}