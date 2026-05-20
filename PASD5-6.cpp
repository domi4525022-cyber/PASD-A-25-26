#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* depan = NULL;
Node* belakang = NULL;


void enqueue(string data);


void isiAwal() {
    depan = belakang = NULL;

    enqueue("Iphone");
    enqueue("Windows");
    enqueue("Mac");
    enqueue("Symbian");
}


void enqueue(string data) {
    Node* baru = new Node{data, NULL};

    if (depan == NULL) {
        depan = belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }
}


void hapus(string target) {
    Node *bantu = depan, *prev = NULL;

    while (bantu != NULL) {
        if (bantu->data == target) {
            if (prev == NULL) {
                depan = bantu->next;
            } else {
                prev->next = bantu->next;
            }

            if (bantu == belakang) {
                belakang = prev;
            }

            delete bantu;
            return;
        }
        prev = bantu;
        bantu = bantu->next;
    }
}

void tambahSetelah(string cari, string dataBaru) {
    Node* bantu = depan;

    while (bantu != NULL) {
        if (bantu->data == cari) {
            Node* baru = new Node{dataBaru, bantu->next};
            bantu->next = baru;

            if (bantu == belakang) {
                belakang = baru;
            }
            return;
        }
        bantu = bantu->next;
    }
}


void tampil(string judul) {
    cout << judul << endl;
    Node* bantu = depan;
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl << endl;
}

int main() {

    // a
    isiAwal();
    hapus("Mac");
    enqueue("Maemo 4");
    tampil("a:");

    // b
    isiAwal();
    hapus("Iphone");
    tambahSetelah("Windows", "Windows Mobile");
    tampil("b:");

    // c
    isiAwal();
    tambahSetelah("Symbian", "Java Midlet");
    tampil("c:");

    // d
    isiAwal();
    tambahSetelah("Mac", "Lion OS X");
    tampil("d:");

    // e
    isiAwal();
    tambahSetelah("Iphone", "Android");
    tampil("e:");

    return 0;
}