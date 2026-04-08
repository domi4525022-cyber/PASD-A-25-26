#include <iostream>
using namespace std;

class maha{
		public:
		float kodebar[9];
		char nambar[30];
		float harga;
		};
int main(){
	maha mha;
	cout << "kodebar 	= "; cin >> mha.kodebar;
	cout << "nama nambar		= "; cin >> mha.nambar;
	cout << "indek harga = "; cin >> mha.harga;
	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << " 				data anda" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "kodebar	= " << mha.kodebar << endl;
	cout << "nambar		= "<< mha.nambar << endl;
	cout << "idek harga = "<< mha.harga << endl;
	cin.get();
}