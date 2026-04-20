#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct biodata {
	string ID;
    string nama;
    double total;
	
};
struct biodata mhs;
struct biodata dataQueue[MAX];  
void init(void);
int ispenuh(void);
int iskosong(void);
struct biodata entridata(void);
void enqueue(struct biodata mhs);
struct biodata dequeue(void);
void cetakqueue(struct biodata mhs);
void baca(void);
int awal, akhir;
char nocomment[10];

int main() {
    char pilih;
    cout << "== Program Entri Data Mahasiswa==\n";
    init();
    do {
        cout << "MENU PILIHAN :\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan queue\n";
        cout << "4. Selesai.\n";
        cout << "Pilih 1 sd 5 : ";
        cin >> pilih;
        switch(pilih) {
            case '1' :  mhs = entridata(); enqueue(mhs); break;
            case '2' :  cout << "\nData yang dihapus : \n";
                        mhs = dequeue(); cetakqueue(mhs); break;
            case '3' :  baca(); break;
            case '4' :  break;
            default  :  cout << "Pilih 1 sd 4!";
                        break;        }
        cout << "\n";
    }while(pilih != '4');
    return 0; }

void init(void) {
    awal = -1;
    akhir = -1;
}

void enqueue(struct biodata mhs) {
    if(iskosong() == true) {
        awal = 0;
        akhir = 0;
        dataQueue[awal] = mhs;  
    }else if(ispenuh() != true) {
        akhir++;
        dataQueue[akhir]=mhs;   
    }else cout << "Queue sudah penuh... \n";
}

struct biodata dequeue(void) {
    int i;
    if(iskosong() != true) {
        mhs=dataQueue[awal];
        for(i=awal;i<=akhir;i++)
            dataQueue[i]=dataQueue[i+1];
        akhir--;
        return(mhs);
    }else {
        cout << "Queue kosong...\n";
        return(mhs);  
    }
}

int ispenuh(void) {
    if(akhir==MAX-1) return(true);
    else return(false);
}

int iskosong(void) {
    if(akhir == -1) return(true);
    else return(false);
}

void baca(void) {
    int i;
    cout << "\nIsi Queue : \n";
    if(iskosong() != true) {
        for(i=awal;i<=akhir;i++) {
            cetakqueue(dataQueue[i]);  
        }
    }else cout << "Data kosong.";
    cout << "\n";
}

struct biodata entridata(void) {
    struct biodata mhs;
    cout << "\n";
	cout << "Masukkan ID : ";cin >> mhs.ID;
    cout << "Masukkan Nama : ";cin >> mhs.nama;
    cout << "Masukkan TOTAL : ";cin >> mhs.total;
    return(mhs);
}

void cetakqueue(struct biodata mhs) {
    cout << "\n";
	cout << "ID : " << mhs.ID << "\n";
    cout << "Nama : " << mhs.nama << "\n";
    cout << "TOTAL : " << mhs.total << "\n";
}