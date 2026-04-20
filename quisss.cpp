#include <iostream>
using namespace std;

#define MAX 10

struct Pelanggan {
    int id;
    string nama;
    float totalBelanja;
};

Pelanggan queue[MAX];
int front = -1, rear = -1;


bool isKosong() {
    return front == -1;
}


bool isPenuh() {
    return rear == MAX - 1;
}


void enqueue() {
    if (isPenuh()) {
        cout << "Queue penuh!\n";
    } else {
        if (isKosong()) {
            front = 0;
        }
        rear++;
        cout << "Masukkan ID: ";
        cin >> queue[rear].id;
        cout << "Masukkan Nama: ";
        cin >> queue[rear].nama;
        cout << "Masukkan Total Belanja: ";
        cin >> queue[rear].totalBelanja;

        cout << "Data berhasil ditambahkan!\n";
    }
}


void dequeue() {
    if (isKosong()) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Data dihapus: " << queue[front].nama << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }
}


void cetakQueue() {
    if (isKosong()) {
        cout << "Queue kosong!\n";
    } else {
        cout << "\nIsi Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "ID: " << queue[i].id
                 << ", Nama: " << queue[i].nama
                 << ", Total: " << queue[i].totalBelanja << endl;
        }
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n=== MENU QUEUE ===\n";
        cout << "1. Tambah data pelanggan\n";
        cout << "2. Hapus data pelanggan\n";
        cout << "3. Tampilkan queue\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: cetakQueue(); break;
            case 4: cout << "Keluar program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}