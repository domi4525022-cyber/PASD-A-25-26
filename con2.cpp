#include <iostream>
using namespace std;

struct maha{
		char NPM[9];
		char nama[30];
		float ipk;
		};
int main(){
	maha mha;
	cout << "nomor pokok mahasiswa 	= "; cin >> mha.NPM;
	cout << "nama mahasiswa 		= "; cin >> mha.nama;
	cout << "indek prestasi komulatif = "; cin >> mha.ipk;
	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << " 				data anda" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "nomor pokok mahasiswa 	= " << mha.NPM << endl;
	cout << "nama mahasiswa 		= "<< mha.nama << endl;
	cout << "indek presentasi komulatif = "<< mha.ipk << endl;
	cin.get();
}