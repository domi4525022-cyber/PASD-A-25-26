#include <iostream>
using namespace std;

#define MAX 20

string Q[MAX];
int depan = 0;
int belakang = -1;

// enqueue
void enqueue(string data) {
    if (belakang == MAX - 1) {
        cout << "Antrian penuh!" << endl;
    } else {
        belakang++;
        Q[belakang] = data;
    }
}

// dequeue
string dequeue() {
    if (depan > belakang) {
        return "";
    } else {
        return Q[depan++];
    }
}

// tampil
void tampil() {
    for (int i = depan; i <= belakang; i++) {
        cout << Q[i];
        if (i < belakang) cout << " -> ";
    }
    cout << endl;
}

// reset queue
void reset() {
    depan = 0;
    belakang = -1;
}

int main() {

    // =====================
    // DATA AWAL
    // =====================
    enqueue("Maemo");
    enqueue("Symbian");
    enqueue("Mac");
    enqueue("Windows");
    enqueue("Iphone");

    cout << "Antrian awal: ";
    tampil();

    // =====================
    // a. Iphone 5 di atas Iphone
    // =====================
    cout << "\na. Iphone 5 di atas Iphone" << endl;

    string temp[MAX];
    int i = 0;

    while (depan <= belakang) {
        string x = dequeue();
        if (x == "Iphone") {
            temp[i++] = "Iphone 5";
        }
        temp[i++] = x;
    }

    reset();
    for (int j = 0; j < i; j++) enqueue(temp[j]);

    tampil();

    // =====================
    // b. Windows Phone di atas Windows
    // =====================
    cout << "\nb. Windows Phone di atas Windows" << endl;

    i = 0;
    while (depan <= belakang) {
        string x = dequeue();
        if (x == "Windows") {
            temp[i++] = "Windows Phone";
        }
        temp[i++] = x;
    }

    reset();
    for (int j = 0; j < i; j++) enqueue(temp[j]);

    tampil();

    // =====================
    // c. SnowLeopard setelah Mac
    // =====================
    cout << "\nc. SnowLeopard setelah Mac" << endl;

    i = 0;
    while (depan <= belakang) {
        string x = dequeue();
        temp[i++] = x;
        if (x == "Mac") {
            temp[i++] = "SnowLeopard";
        }
    }

    reset();
    for (int j = 0; j < i; j++) enqueue(temp[j]);

    tampil();

    // =====================
    // d. Symbian Belle setelah Symbian
    // =====================
    cout << "\nd. Symbian Belle setelah Symbian" << endl;

    i = 0;
    while (depan <= belakang) {
        string x = dequeue();
        temp[i++] = x;
        if (x == "Symbian") {
            temp[i++] = "Symbian Belle";
        }
    }

    reset();
    for (int j = 0; j < i; j++) enqueue(temp[j]);

    tampil();

    // =====================
    // e. Maemo 4 paling bawah
    // =====================
    cout << "\ne. Maemo 4 paling bawah" << endl;

    enqueue("Maemo 4");
    tampil();

    return 0;
}