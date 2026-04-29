#include <iostream>
using namespace std;

#define MAX 3

struct Mahasiswa {
    string npm;
    string nama_mhs;
    float nilai;
};

Mahasiswa Q[MAX];
int depan = 0;
int belakang = -1;

bool isFull() {
    return (belakang == MAX - 1);
}

bool isEmpty() {
    return (belakang == -1);
}

void enqueue() {
    if (isFull()) {
        cout << "Antrian penuh!" << endl;
    } else {
        belakang++;

        cout << "Masukkan NPM   : "; cin >> Q[belakang].npm;
        cout << "Masukkan Nama  : "; cin >> Q[belakang].nama_mhs;
        cout << "Masukkan Nilai : "; cin >> Q[belakang].nilai;
    }
}


void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "Data keluar: " << Q[depan].nama_mhs << endl;
        depan++;
    }
}

void tampil() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "Isi Antrian:" << endl;
        for (int i = depan; i <= belakang; i++) {
            cout << "NPM   : " << Q[i].npm << endl;
            cout << "Nama  : " << Q[i].nama_mhs << endl;
            cout << "Nilai : " << Q[i].nilai << endl;
            cout << "----------------------" << endl;
        }
    }
}

int main() {

    enqueue();
    enqueue();
    enqueue();

    tampil();

    dequeue();

    tampil();

    return 0;
}