#include <iostream>
using namespace std;

#define MAX 10

struct Stack {
    char data[MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

bool full(Stack s) {
    return s.top == MAX - 1;
}

bool empty(Stack s) {
    return s.top == -1;
}

void push(Stack &s, char x) {
    if (!full(s)) {
        s.data[++s.top] = x;
    }
}

char pop(Stack &s) {
    if (!empty(s)) {
        return s.data[s.top--];
    }
    return '\0';
}

void tampil(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << endl;
    }
}

int main() {
    Stack s, temp;
    init(s);
    init(temp);

  
    push(s, 'A');
    push(s, 'B');
    push(s, 'C');

    cout << "Stack awal:\n";
    tampil(s);

   
    while (!empty(s)) {
        push(temp, pop(s));
    }

    push(s, 'F');

    while (!empty(temp)) {
        push(s, pop(temp));
    }

    cout << "\nSetelah tambah F paling bawah:\n";
    tampil(s);

    return 0;
}