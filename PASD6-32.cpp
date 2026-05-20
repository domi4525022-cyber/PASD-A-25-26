#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua bagian menjadi data yang diurutkan
void Merge(int *a, int low, int high, int mid) {
    int i, j, k;
    
    int temp[100]; // array sementara

    i = low;
    k = low;
    j = mid + 1;

    // Gabungkan kedua bagian ke temp[]
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        } else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Masukkan sisa elemen dari bagian kiri
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Masukkan sisa elemen dari bagian kanan
    while (j <= high) {
        temp[k] = a[j];
        k++;
        j++;
    }

    // Copy kembali ke array asli
    for (i = low; i <= high; i++) {
        a[i] = temp[i];
    }
}

// Fungsi Merge Sort
void MergeSort(int *a, int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;

        // Bagi data menjadi dua bagian
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        // Gabungkan kembali
        Merge(a, low, high, mid);
    }
}

int main() {
    int n, i;

    cout << "Masukkan jumlah elemen data yang akan diurutkan : ";
    cin >> n;

    int arr[100];

    for (i = 0; i < n; i++) {
        cout << "Masukkan elemen " << i + 1 << " : ";
        cin >> arr[i];
    }

    // Proses sorting
    MergeSort(arr, 0, n - 1);

    // Cetak hasil
    cout << endl;
    cout << "Data Terurut" << endl;

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}