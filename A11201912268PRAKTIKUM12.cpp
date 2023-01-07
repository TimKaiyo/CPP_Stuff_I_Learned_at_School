#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

struct Data_Diri{
    string nama;
    string nim; 
} datdir;

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

void cekSetelah(int nodeSetelah){
    if(nodeSetelah == tail->data){
        cout << "\nSetelah menunjuk ke tail\n";
    }else if(nodeSetelah == head->data){
        cout << "\nSetelah menunjuk ke head\n"; 
    }
}

void apaSetelahKosong(int nodeSetelah){
    if(nodeSetelah == NULL){
        cout << "\nNILAI SETELAH KOSONG!!!\n";
    }
}

void tambahTengah(int nodeSetelah, int dataBaru){
    cekSetelah(nodeSetelah);
    apaSetelahKosong(nodeSetelah); 
    // deklarasi node baru
    Node *nodeBaru, *current, *current2;
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
   
        // looping untuk pencarian node tengahnya
        // kalo ketemu, current = node yang dicari
        for(current=head; current->data!=nodeSetelah; current=current->next) {

        }
        current2 = current->next; // sambungin ke nextnya current

        // nodeBaru disambungkan ke node current dan ke node current2
        nodeBaru->next = current2;
        nodeBaru->prev = current;

        current2->prev = nodeBaru; // current2 sambung ke nodebaru
        current->next = nodeBaru; // current sambung ke nodebaru


    }


}



void tambahBelakang(int dataBaru){
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
        tail -> next = nodeBaru; // tail disambung ke node baru
        nodeBaru -> prev = tail; // prev dari nodebaru disambung ke tail
        tail = nodeBaru; //
    }
}

void hapusTengah(int cariData) {
    if(isEmpty()) {
        cout << "Tidak ada node yang dihapus nich" << endl;
    }else {
        // cek apakah node cuma 1
        if(head -> next != NULL){
            // jika node lebih dari 1

            // deklarasi node
            Node *hapus, *current, *current2;

            // looping untuk cari node dihapus
            for(current=head; current->data!=cariData; current=current->next) {

            }

            hapus = current; // node yang akan di hapus

            // current2 tamputng node setelah dari yang mau dihapus
            current2 = current->next;

            // current menyambungkan ke current 2
            current = hapus->prev;
            current->next = current2;

            // current2 sambung ke current
            current2->prev = current2;

        }else {
            // jika node cuma 1
            // head dan tail langsung kita NULL - kan
            head = NULL;
            tail = NULL;
        }
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

void hapusBelakang() {
    if(isEmpty()) {
        cout << "Tidak ada node yang dihapus nich" << endl;
    }else {
        // cek apakah node cuma 1
        if(head -> next != NULL){
            // jika node lebih dari 1
            tail = tail -> prev; // tail diganti node sebelum tail
            tail -> next = NULL; // next dari tail kita buat NULL
        }else {
            // jika node cuma 1
            // head dan tail langsung kita NULL - kan
            head = NULL;
            tail = NULL;
        }
    }
}

void tampilHead(){
    if(isEmpty()){
        cout << "Node Kosong !!" << endl;
    }else{
        cout << "Headnya adalah " << head->data << endl;
    }
}

void tampilTail(){
    if(isEmpty()){
        cout << "Node Kosong !!" << endl;
    }else{
        cout << "Tailnya adalah " << tail->data << endl;
    }
}

void tampil() {
    if(isEmpty()) {
        cout << "Kosong Nich" << endl;
    }else {
        Node *current;

        for(current = head; current != NULL; current = current -> next) {
            cout << "<-" << current -> data << "-> ";
        }
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

void kosongKah(){
    if(isEmpty()){
        cout << "LIST MASIH KOSONG!!\n"; 
    }
    else{
        cout  << "LIST TIDAK KOSONG!!\n"; 
    }
}

int main()
{   
    cout << "A11.2021.13887 - TIMOTHY MULYA CAHYANA\n"; 

    awal(); 
    cout << "\nList kosong?\n";
    kosongKah();

     
    cout << "\nTAMBAH DEPAN:\n"; 
    tambahDepan(110); 
    tambahDepan(221);
    tambahDepan(2357);
    tampil();

    cout << "\nTAMBAH TENGAH: \n";
    tambahTengah(221,30);
    tampil();

    cout << "\nTAMBAH BELAKANG: \n"; 
    tambahBelakang(32241);
    tampil();

    cout << "\nHAPUS BELAKANG: \n"; 
    hapusBelakang();
    tampil();

    cout << "\nHAPUS DEPAN: \n"; 
    hapusDepan(); 
    tampil(); 

    cout << "\nList kosong?\n";
    kosongKah();

    cout << "\nHAPUS TENGAH: \n"; 
    hapusTengah(30);
    tampil();
    
    cout << "\nHASIL TAMPIL NODE: " << endl;
    tampilNode();

    return 0;
}
