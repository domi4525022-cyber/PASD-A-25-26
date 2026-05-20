#include <iostream>
#include <string>
using namespace std;

struct KTP {
    string NIK, Nama, Alamat, JenisKelamin, Agama, Status, Pekerjaan, Kewarganegaraan, MasaBerlaku;
    int TahunLahir;
};

int main() {
    KTP data;

    cout << "=== INPUT DATA KTP ===" << endl;
    cout << "NIK: "; cin >> data.NIK;
    cin.ignore();
    cout << "Nama: "; getline(cin, data.Nama);
    cout << "Alamat: "; getline(cin, data.Alamat);
    cout << "Tahun Lahir: "; cin >> data.TahunLahir;
    cin.ignore();
    cout << "Jenis Kelamin: "; getline(cin, data.JenisKelamin);
    cout << "Agama: "; getline(cin, data.Agama);
    cout << "Status: "; getline(cin, data.Status);
    cout << "Pekerjaan: "; getline(cin, data.Pekerjaan);
    cout << "Kewarganegaraan: "; getline(cin, data.Kewarganegaraan);
    cout << "Masa Berlaku: "; getline(cin, data.MasaBerlaku);

    cout << "\n=== DATA KTP ===" << endl;
    cout << "NIK: " << data.NIK << endl;
    cout << "Nama: " << data.Nama << endl;
    cout << "Alamat: " << data.Alamat << endl;
    cout << "Tahun Lahir: " << data.TahunLahir << endl;
    cout << "Jenis Kelamin: " << data.JenisKelamin << endl;
    cout << "Agama: " << data.Agama << endl;
    cout << "Status: " << data.Status << endl;
    cout << "Pekerjaan: " << data.Pekerjaan << endl;
    cout << "Kewarganegaraan: " << data.Kewarganegaraan << endl;
    cout << "Masa Berlaku: " << data.MasaBerlaku << endl;

    cin.get();
}