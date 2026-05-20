#include <iostream>
using namespace std;

int data[10] = {12, 5, 9, 20, 15, 7};
int n = 6;

void tukar(int a, int b)
{
    int t;
    t = data[a];
    data[a] = data[b];
    data[b] = t;
}

void tampil()
{
    for(int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void bubble_sort_descending()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = n - 1; j >= i; j--)
        {
            if(data[j] > data[j - 1])
            {
                tukar(j, j - 1);
            }
        }

        tampil();
    }
}

int main()
{
    cout << "==================================" << endl;
    cout << "      BUBBLE SORT DESCENDING      " << endl;
    cout << "==================================" << endl;

    cout << "Data sebelum diurutkan : " << endl;
    tampil();

    cout << endl;
    cout << "Proses Bubble Sort Descending : " << endl;

    bubble_sort_descending();

    cout << endl;
    cout << "Data setelah diurutkan : " << endl;
    tampil();

    cout << "==================================" << endl;
    cout << "         TERIMA KASIH             " << endl;
    cout << "==================================" << endl;

    return 0;
}