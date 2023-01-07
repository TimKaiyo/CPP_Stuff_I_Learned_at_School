#include <iostream>
#include <string>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head;
Node *tail;

void awal() {
    head == NULL;
    tail == NULL;
}

bool isEmpty() {
    if(head == NULL) {
        return true;
    }
    return false;
}

void total(int nilaiMasukan){
    int jumlah = jumlah + nilaiMasukan;
    cout << "Total: " << jumlah << endl;
}

void tambahDepan(int dataBaru) {
    // deklarasi node baru
    Node *nodeBaru;
    nodeBaru = new Node;

    // lengkapi node baru
    nodeBaru -> data = dataBaru;
    nodeBaru -> next = NULL;
    nodeBaru -> prev = NULL;

    // sambungkan ke DLL sekarang
    if (isEmpty()) { // kondisi DLL kosong
        // langsung 1adikan node pertama
        head = nodeBaru;
        tail = nodeBaru;
        head -> next = NULL;
        head -> prev = NULL;
    }else { // kondisi DLL ada node
        //sambungkan nodebaru ke DLL sekarang
        nodeBaru -> next = head; // sambungin ke head
        head -> prev = nodeBaru; // head sambungin ke nodebaru
        head = nodeBaru; // head ganti nodebaru
    }
}

void hapusDepan() {
    if(isEmpty()) {
        cout << "Tidak ada node yang dihapus nich" << endl;
    }else {
        // cek apakah node cuma 1
        if(head -> next != NULL){
            // jika node lebih dari 1
            head = head -> next; // head ganti dengan nextnya
            head -> prev = NULL; // prev dari head kita NULL - kan
        }else {
            // jika node cuma 1
            // head dan tail langsung kita NULL - kan
            head = NULL;
            tail = NULL;
        }
    }
}

void tampil() {
    if(isEmpty()) {
        cout << "Kosong Nich" << endl;
    }else {
        Node *current;

        int jumlah = 0; 
        for(current = head; current != NULL; current = current -> next) {
            cout << "<-" << current -> data << "-> ";
            jumlah = jumlah + current->data; 
        }
        cout << "TOTAL SALDO ANDA ADALAH: " << jumlah << endl; 
        cout << endl;
    }
}

void tampilNode() {
    if(isEmpty()) {
        cout << "Kosong Nich" << endl;
    }else {
        int count = 0;
        Node *p;
        p = head;

        while (p != NULL)
        {
            p = p->next;
            count++;
        }
        cout << "Jumlah nodenya adalah: " << count << " node" << endl;
    }
}

int main(){
    cout << "TIMOTHY MULYA CAHYANA - A11.2021.13887\n" << endl;

    cout << "Tambahkan nilai yang akan disetorkan:" << endl; 
    tambahDepan(11000);
    tambahDepan(23000);
    tambahDepan(40000);
    tampil();

    tambahDepan(23000);
    tambahDepan(90000);
    tambahDepan(66000);
    tampil();

    cout << "Hapus depan: " << endl;
    hapusDepan();
    tampil();

    tampilNode(); 

    return 0;
}