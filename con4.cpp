#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
	string npm;
	string nama_mhs;
	double nilai;
} nilaiMK;

typedef struct {
	int top;
	nilaiMK dat[10];
} stack;

void buatSTkosong(stack *S) {
	(*S) . top = -1;
}

bool IsKosong(stack S) {
	bool hasil = false;
	
	if(S.top == -1) {
	hasil = true;
	}
	return hasil;
}

bool IsPenuh(stack S) {
	bool hasil = false;
	
	if(S.top == 9) {
		hasil = true;
	}
	return hasil;
}


void push(string npm, string nama_mhs, double nilai, stack *S) {
	if(IsPenuh(*S) == 1 {
		cout << "stack penuh" << endl;
	}
	else {
	if(IsKosong(*S) == 1) {
		(*S).top = 0;
		(*S).Dat[0].npm = npm;
		(*S).Dat[0].nama_mhs = nama_mhs;
		(*S)Dat[0].nilai = nilai;
		}
		else {
		(*S).top = (*S).top + 1;
		(*S).Dat[(*S).top].npm = npm;
		(*S).Dat[(*S).top].nama_mhs = nama_mhs;
		(*S).Dat[(*S).top].nilai = nilai;
		}
	}
}

void pop()stack *S) {
	if((*S).top == 0) {
	(*S).top = -1;
	}
	else {
		if((*S).top != -1) {
		(*S).top = (*S).top -1;
		}
	}
}

void CetakStack(stack S)
{
	if(S.top != -1)
	{
		cout << " MENAMPILKAN STACK " << endl;
		int i;
		for(i=S.top; i>=0; i--)
		{
		cout << "---------------------------" << endl;
		cout << "elemen ke 	: " << i << endl;
		cout << "nomor pokok mahasiswa 	: " << S.Dat[i].npm << endl;
		cout << "nama mahasiswa 	: " << S.Dat[i].nama_mhs << endl;
		cout << "nilai mahasiswa 	: " << S.Dat[i].nilai << endl;
		cout << "----------------------------" << endl;
		}
	}
	else
		{
			cout << "stack kosong " << endl;
		}
}

int main() {
	stack S;
	
	buatSTkosong(&S);
	CetakStack(S);
	cout << endl;
	cout << endl;
	cout << "------------------" << endl;
	push("4525210002", "Adrian", 90.00, &S);
	push("4525210021", "Dafa", 90.00, &S);
	push("4525210022", "Dom", 90.00, &S);
	push("4525210053", "Ambatukam", 90.00, &S);
	CetakStack(S);
	cout << "================" << endl;
	cout << endl;
	cout << endl;
	Pop(&S);
	CetakStack(S);
	cout << "=====================" << endl;
	return 0;
}
	
	