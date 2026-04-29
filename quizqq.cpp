#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct dataKaryawan {
    string nip;
    string nama;
    double gaji;
};


struct elemen {
    dataKaryawan data;
    elemen* next;
};


struct queue {
    elemen* first;
    elemen* last;
};


void buatQueueKosong(queue &Q) {
    Q.first = NULL;
    Q.last = NULL;
}


bool isKosong(queue Q) {
    return (Q.first == NULL);
}


elemen* jdlElemen(string nip, string nama, double gaji) {
    elemen* baru = new elemen;
    baru->data.nip = nip;
    baru->data.nama = nama;
    baru->data.gaji = gaji;
    baru->next = NULL;
    return baru;
}


void add(queue &Q, string nip, string nama, double gaji) {
    elemen* baru = jdlElemen(nip, nama, gaji);

    if (isKosong(Q)) {
        Q.first = baru;
        Q.last = baru;
    } else {
        Q.last->next = baru;
        Q.last = baru;
    }
}


void del(queue &Q) {
    if (isKosong(Q)) {
        cout << "Queue kosong, tidak ada data yang dihapus.\n";
    } else {
        elemen* hapus = Q.first;
        cout << "Data dihapus: " << hapus->data.nama << endl;

        Q.first = Q.first->next;

        if (Q.first == NULL) {
            Q.last = NULL;
        }

        delete hapus;
    }
}

void CetakQueue(queue Q) {
    if (isKosong(Q)) {
        cout << "Queue kosong.\n";
    } else {
        elemen* bantu = Q.first;

        cout << "\n===== DATA KARYAWAN DALAM QUEUE =====\n";
        cout << left << setw(15) << "NIP"
             << setw(20) << "Nama"
             << setw(15) << "Gaji" << endl;
        cout << "--------------------------------------------------\n";

        while (bantu != NULL) {
            cout << left << setw(15) << bantu->data.nip
                 << setw(20) << bantu->data.nama
                 << setw(15) << bantu->data.gaji << endl;

            bantu = bantu->next;
        }
        cout << "--------------------------------------------------\n";
    }
}

// Main program
int main() {
    queue Q;

  
    buatQueueKosong(Q);

   
    cout << "Kondisi awal queue:\n";
    CetakQueue(Q);


    add(Q, "101", "Andi", 50000);
    add(Q, "102", "Budi", 55000);
    add(Q, "103", "Citra", 60000);
    add(Q, "104", "Dewi", 52000);
    add(Q, "105", "Eka", 58000);
    add(Q, "106", "Fajar", 61000);
    add(Q, "107", "Gina", 63000);

    cout << "\nSetelah 7 data ditambahkan:\n";
    CetakQueue(Q);

   
    cout << "\nMelakukan 3 kali penghapusan:\n";
    del(Q);
    del(Q);
    del(Q);

   
    cout << "\nSisa antrian setelah 3 kali del:\n";
    CetakQueue(Q);

    return 0;
}