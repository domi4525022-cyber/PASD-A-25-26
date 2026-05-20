#include<iostream>
using namespace std;

int Search01(string kendaraan[], int jumlah, string cari);

int main()
{
    const int MaksData = 100;
    string kendaraan[MaksData];
    int jumlahData = 0;
    int pilihan;

    do
    {
        cout << "\n======================================" << endl;
        cout << "   PROGRAM DATA KENDARAAN" << endl;
        cout << "======================================" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Cari Kendaraan" << endl;
        cout << "3. Tampilkan Data Kendaraan" << endl;
        cout << "4. Keluar" << endl;
        cout << "======================================" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        cin.ignore();

        switch(pilihan)
        {
            case 1:
            {
                int jumlahInput;
                cout << "\nBerapa data kendaraan yang ingin diinput? ";
                cin >> jumlahInput;
                cin.ignore();

                for(int i = 0; i < jumlahInput; i++)
                {
                    cout << "Masukkan nama kendaraan ke-" << i + 1 << " : ";
                    getline(cin, kendaraan[jumlahData]);
                    jumlahData++;
                }

                cout << "\nData kendaraan berhasil ditambahkan!" << endl;
                break;
            }

            case 2:
            {
                if(jumlahData == 0)
                {
                    cout << "\nData kendaraan masih kosong!" << endl;
                }
                else
                {
                    string cari;
                    cout << "\nMasukkan nama kendaraan yang dicari : ";
                    getline(cin, cari);

                    int hasil = Search01(kendaraan, jumlahData, cari);

                    if(hasil != -1)
                    {
                        cout << "Kendaraan ditemukan pada posisi Data[" 
                             << hasil << "]" << endl;
                    }
                    else
                    {
                        cout << "Kendaraan tidak ditemukan!" << endl;
                    }
                }
                break;
            }

            case 3:
            {
                if(jumlahData == 0)
                {
                    cout << "\nBelum ada data kendaraan!" << endl;
                }
                else
                {
                    cout << "\nDaftar Kendaraan :" << endl;
                    for(int i = 0; i < jumlahData; i++)
                    {
                        cout << "Data[" << i << "] --> " 
                             << kendaraan[i] << endl;
                    }
                }
                break;
            }

            case 4:
            {
                cout << "\nProgram selesai. Terima kasih!" << endl;
                break;
            }

            default:
            {
                cout << "\nPilihan tidak valid!" << endl;
            }
        }

    } while(pilihan != 4);

    return 0;
}

int Search01(string kendaraan[], int jumlah, string cari)
{
    int flaq = -1;

    for(int i = 0; i < jumlah; i++)
    {
        if(cari == kendaraan[i])
        {
            flaq = i;
            break;
        }
    }

    return flaq;
}