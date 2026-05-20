#include <iostream>
using namespace std;


struct Alamat {
    string Jalan;
    string Kota;
    int KodePos;
};


struct Lahir {
    int Tanggal;
    int Bulan;
    int Tahun;
};


struct KTP {
    int NOKTP;
    string Nama;
    Alamat Alamat;
    Lahir Lahir;
};

int main() {
    KTP data;
    KTP *JatiDiri = &data;

    // ===== INPUT DATA =====
    cout << "Masukkan No KTP : ";
    cin >> JatiDiri->NOKTP;
    cin.ignore();

    cout << "Masukkan Nama : ";
    getline(cin, JatiDiri->Nama);

    cout << "\nAlamat\n";
    cout << "Jalan : ";
    getline(cin, JatiDiri->Alamat.Jalan);

    cout << "Kota : ";
    getline(cin, JatiDiri->Alamat.Kota);

    cout << "Kode Pos : ";
    cin >> JatiDiri->Alamat.KodePos;

    cout << "\nTanggal Lahir\n";
    cout << "Tanggal : ";
    cin >> JatiDiri->Lahir.Tanggal;

    cout << "Bulan : ";
    cin >> JatiDiri->Lahir.Bulan;

    cout << "Tahun : ";
    cin >> JatiDiri->Lahir.Tahun;

    
    cout << "\n=== DATA KTP ===\n";
    cout << "No KTP : " << JatiDiri->NOKTP << endl;
    cout << "Nama : " << JatiDiri->Nama << endl;

    cout << "Alamat : "
         << JatiDiri->Alamat.Jalan << ", "
         << JatiDiri->Alamat.Kota << ", "
         << JatiDiri->Alamat.KodePos << endl;

    cout << "Tanggal Lahir : "
         << JatiDiri->Lahir.Tanggal << "-"
         << JatiDiri->Lahir.Bulan << "-"
         << JatiDiri->Lahir.Tahun << endl;

    cin.get();
}