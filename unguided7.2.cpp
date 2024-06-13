#include <iostream>
using namespace std;

// Definisi struktur Node dengan atribut nama mahasiswa dan NIM mahasiswa
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Deklarasi variabel untuk front dan back
Node* front = nullptr;
Node* back = nullptr;

// Fungsi untuk mengecek apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk menambahkan elemen ke dalam queue
void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
    cout << "Enqueued: Nama: " << nama << ", NIM: " << nim << endl;
}

// Fungsi untuk menghapus elemen dari queue
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        cout << "Dequeued: Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        delete temp;
    }
}

// Fungsi untuk menghitung jumlah elemen dalam queue
int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi untuk menghapus semua elemen dalam queue
void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

// Fungsi untuk menampilkan elemen dalam queue
void viewQueue() {
    cout << "Data antrian mahasiswa = " << endl;
    Node* temp = front;
    int index = 1;
    while (temp != nullptr) {
        cout << index << ". Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
        index++;
    }
    if (index == 1) {
        cout << "Antrian kosong" << endl;
    }
}

int main() {
    enqueueAntrian("Ahmadan", "2311102038");
    enqueueAntrian("syaridin", "2311102038");
    viewQueue();
    cout << "Jumlah antrian : " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian : " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}