#include <iostream>
using namespace std;

struct Data
{
    int angka[10];
    int n;
};

Data nilai = {{25, 12, 9, 30, 18, 5}, 6};

void tukar(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void tampil()
{
    for(int i = 0; i < nilai.n; i++)
    {
        cout << nilai.angka[i] << " ";
    }

    cout << endl;
}

void bubble_sort()
{
    for(int i = 1; i < nilai.n; i++)
    {
        for(int j = nilai.n - 1; j >= i; j--)
        {
            if(nilai.angka[j] < nilai.angka[j - 1])
            {
                tukar(nilai.angka[j], nilai.angka[j - 1]);
            }
        }

        tampil();
    }

    cout << endl;
}

int main()
{
    cout << "====================================" << endl;
    cout << "   BUBBLE SORT ASCENDING STRUCT     " << endl;
    cout << "====================================" << endl;

    cout << "Data sebelum diurutkan :" << endl;
    tampil();

    cout << endl;
    cout << "Proses Bubble Sort Ascending :" << endl;

    bubble_sort();

    cout << "Data setelah diurutkan :" << endl;
    tampil();

    cout << "====================================" << endl;
    cout << "          TERIMA KASIH              " << endl;
    cout << "====================================" << endl;

    return 0;
}