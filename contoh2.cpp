#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
void bsim(int x);
void awal();
void cetak();
void insert();
struct node
   int info;
   struct node *link;   };
typedef struct node simpul;
simpul *p, *first, *last, *q;
int x;
int main()  {
   int a[7] = {22, 28, 8, 66, 55, 12};
   int i;
   first = NULL;
   i=0;
   x=a[i];
   bsim(x);
   awal;
   for(i=1; i<=6; i++)
 {
   x=a[i];
   bsim(x)
   insert();  }
   cout << "nilai sebelum : ";
   cetak();
   x = 100;
   bsim(x);
   insert();
   cout<<endl;
   cout << "nilai setelah : ";
   cetak();
   cout<<endl;
   cin.get();
   
void bsim(int x)
{
   p=(simpul*) malloc(sizeof(simpul));
   if(p != NULL)
     p -> info = x;  }
	else  {
	  cout << "pembuatan simpul" << endl;
	  cin.get();
	  exit(1);  } }
	  
void awal()
{
  first = p;
  last = p;
  p -> link = NULL; }
  
  void cetak()
  {
    int x;
	q = first;
	while(q != NULL)  {
	  x = q info;
	  cout << "  " << x;
	  q = q -> link; }  }