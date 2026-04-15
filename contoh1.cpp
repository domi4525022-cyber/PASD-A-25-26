#include <iostream>
using namespace std;

typedef struct {
  string npm;
  string nama_mhs;
  double nilai;
} NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm {
  NilaiMK Kontainer;
  alamatelm next;
} elemen;

typedef struct {
  elemen* top;
} stack;

void buatstkosong(stack *S) {
  (*S).top = NULL;
}

int iskosong(stack S) {
   bool hasil = false;
   
   if(S.top == NULL) {
    hasil = true;
	}
	return hasil;
}

int jmlelemen(stack S) {
  int hasil = 0;
  
  if(S.top != NULL) {
  elemen *bantu;
  bantu = S.top;
  
  while(bantu != NULL) {
    hasil = hasil + 1;
	bantu = bantu -> next;
	}
}
return hasil;

void push(string npm, string nama_mhs, double nilai, stack *S) {
  elemen *info;
  info -> Kontainer.npm = npm;
  info -> Kontainer.nama_mhs = nama_mhs;
  info -> Kontainer.nilai = nilai;
  
  if((*S).top == NULL) {
    cout << "stack penuh" << endl;
	info -> next = NULL;
	}
  else {
     info -> next = (*S).top;
	 }
	(*S).top = info;
	info = NULL;
}

void pop(stack *S) {
  if((*S).top != NULL) {
   elemen *hapus = (*S).top;
   
   if(jmlelemen(*S) == 1) {
   (*S).top = NULL;
   }
  else {
    (*S).top = (*S).top -> next;
	}
	hapus -> next = NULL;
	delete hapus;
	}
  else {
   cout << "stack kosong" << endl;
   }
  }
  
void ctakstack(stack S)
{
  if(S.top != NULL)
  {
    cout << "menampilakan stack" << endl;
	elemen *bantu = S.top;
	int i = 1;
	while(bantu != NULL)
	{
	  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	  cout << "elemen ke 				: " << i << endl;
	  cout << "nomor pokok mahasiswa 	: " << bantu -> Kontainer.npm << endl;
	  cout << "nama mahasiswa 			: " << bantu -> Kontainer.nama_mhs << endl;
	  cout << "nilai mahasiswa 			: " << bantu -> Kontainer.nilai << endl;
	  
	  bantu = bantu -> next;
	  i = i + 1;
	  }
	  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	else
	   {
	     cout << "stack kosong" << endl;
	    }
}

int main() {
  stack S;
  
  buatstkosong(&S);
  ctakstack(S);
  cout << endl;
  cout << endl;
  cout << "~~~~~~~~~~~~~~~~~~" << endl;
  push("4525210080", "asik", 88.51, &S)
  push("4525210081", "Bsik", 88.52, &S)
  push("4525210082", "Rsik", 88.53, &S)
  push("4525210083", "Ysik", 88.55, &S)
  push("4525210084", "Usik", 88.54, &S)
  push("4525210085", "Wsik", 88.58, &S)
  push("4525210086", "Qsik", 88.51, &S)
  push("4525210087", "Asik", 88.59, &S)
  ctakstack(S);
  cout << "==========================" << endl;
  cout << endl;
  cout << endl;
  pop(&S);
  ctakstack(S);
  cout << endl;
  cout << endl;
  pop(&S);
  ctakstack(S);
  cout << "=======================" << endl;
  return 0;
}
  