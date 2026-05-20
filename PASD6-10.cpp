#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nilai;
};

void Q_Sort(Mahasiswa data[], int kiri, int kanan) {
    int i = kiri;
    int j = kanan;
    int pivot = data[(kiri + kanan) / 2].nilai;

    do {
        while (data[i].nilai < pivot)
            i++;

        while (data[j].nilai > pivot)
            j--;

        if (i <= j) {
            swap(data[i], data[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (kiri < j)
        Q_Sort(data, kiri, j);

    if (i < kanan)
        Q_Sort(data, i, kanan);
}

int main() {
    int jumlah;

    cout << "Masukkan jumlah data mahasiswa : ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    cout << "\nInput Data Mahasiswa" << endl;
    cout << "======================" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> mhs[i].nama;
        cout << "Nilai : ";
        cin >> mhs[i].nilai;
    }

    // Data sebelum diurutkan
    cout << "\nData SEBELUM diurutkan" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << setw(10) << mhs[i].nama
             << " : " << mhs[i].nilai << endl;
    }

    Q_Sort(mhs, 0, jumlah - 1);


    cout << "\nData SETELAH diurutkan " << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << setw(10) << mhs[i].nama
             << " : " << mhs[i].nilai << endl;
    }

    return 0;
}