#include <iostream>
using namespace std;

class Pelanggan {
public:
    string nama, alamat, telp;
    int umur;
    char kelamin;

    void input() {
        cout << "Nama Pelanggan Toko      : "; cin >> nama;
        cout << "Alamat Pelanggan Toko    : "; cin >> alamat;
        cout << "Umur Pelanggan Toko      : "; cin >> umur;
        cout << "Jenis Kelamin Pelanggan (L/P) : "; cin >> kelamin;
        cout << "No telp Pelanggan        : "; cin >> telp;
        cout << endl;
    }

    void tampil() {
        cout << nama << "\t" << alamat << "\t" << umur 
             << "\t" << kelamin << "\t" << telp << endl;
    }
};

int main() {
    int jumlah;

    cout << "INPUT DATA PELANGGAN" << endl;
    cout << "Jumlah pelanggan : ";
    cin >> jumlah;

    Pelanggan p[jumlah];

    cout << endl;
    for(int i = 0; i < jumlah; i++) {
        p[i].input();
    }

    cout << "==============================================" << endl;
    cout << "        Data Pelanggan Toko:" << endl;
    cout << "==============================================" << endl;
    cout << "Nama\tAlamat\tUmur\tKelamin\tNo telp" << endl;

    for(int i = 0; i < jumlah; i++) {
        p[i].tampil();
    }

    cout << "==============================================" << endl;

    return 0;
}