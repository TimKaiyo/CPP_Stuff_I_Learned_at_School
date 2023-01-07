#include <iostream>
#include <string>

using namespace std;

struct Node{
    int data;
    string items; 

    Node *after;
    Node *before;

    Node *next;
    Node *prev;

};

struct Data_Diri{
    string nama;
    string nim; 
} datdir;


Node *head;
Node *tail;
Node *second_head;
Node *second_tail;

void awal(){
    head=NULL;
    tail=NULL;
    second_head=NULL;
    second_tail=NULL;
}

bool isEmpty(){
    if (head == NULL){
        return true;
    }
    if (second_head == NULL){
        return true;
    }
    return false;
}

void tambahDpn(int dataBaru, string barang){
    // Deklarasi node baru
    Node *nodeBaru;
    nodeBaru = new Node;

    Node *newNode;
    newNode = new Node; 

    // lengkapi node baru
    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    newNode->items = barang;
    newNode->after = NULL;
    newNode->before = NULL;


    // sambungkan ke DLL sekarang
    if(isEmpty()){ //kondisi DLL kosong
        // langsung jadikan node pertama
        head = nodeBaru;
        tail = nodeBaru;
        head->next = NULL;
        head->prev = NULL;

        second_head = newNode;
        second_tail = newNode;
        second_head->after = NULL;
        second_head->before = NULL;

    }else{ //kondisi DLL ada node
        // sambungkan nodebaru ke DLL skrng
        nodeBaru->next = head; // sambungin ke head
        head->prev = nodeBaru; // head sambungin ke nodebaru
        head = nodeBaru; // head ganti nodebaru

        newNode->after = second_head;
        second_head->before = newNode;
        second_head = newNode;
    }
        Node *current;
        Node *skg;
        int jumlah = 0;

        cout << "Barang yang ditambahkan: " << endl; 
        for(skg = second_head; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->items << "->\n"; 
        }
        // buat looping untuk menampilkan node di DLL
        for(current = head; current !=NULL; current = current->next){
            cout << current->data << " + ";
            jumlah = jumlah + current->data;
        }
        cout << "\n\n";
        cout << "Total: " << jumlah << "\n\n";
}

void tmbhBlkg(int dataBaru, string barang){
    Node *nodeBaru;
    nodeBaru = new Node;

    Node *newNode;
    newNode = new Node; 

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    newNode->items = barang;
    newNode->after = NULL;
    newNode->before = NULL;

    if(isEmpty()){
        head=nodeBaru;
        tail=nodeBaru;
        head->next = NULL;
        head->prev = NULL; 

        second_head=newNode;
        second_tail=newNode;
        second_head->after = NULL;
        second_head->before = NULL;
    }else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;

        second_tail->after = newNode;
        newNode->before = second_tail;
        second_tail = newNode; 
    }
        Node *current;
        Node *skg;
        int jumlah = 0;

        // buat looping untuk menampilkan node di DLL
        cout << "Barang yang ditambahkan: " << endl;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->items << "->\n"; 
        }
        for(current = head; current !=NULL; current = current->next){
            cout << current->data << "+";
            jumlah = jumlah + current->data;
        }
        cout << "\n\n";
   
 
        cout << "\n\n"; 
        cout << "Total: " << jumlah << "\n\n";
}

void tmbhTengah(int nodeSetelah, int dataBaru){
    Node *nodeBaru, *current, *current2;
    nodeBaru = new Node;

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    if(isEmpty()){
        head = nodeBaru; 
        tail = nodeBaru;
        head->next = NULL;
        head->prev = NULL;
    }else{
        for(current=head; current->data!=nodeSetelah; current=current->next){

        }
        current2 = current->next;

        nodeBaru->next = current2;
        nodeBaru->prev = current; 

        current2->prev = nodeBaru;
        current->next = nodeBaru;
    }
}

void hapusDpn(){
if(isEmpty()){
cout << "Tidak ada node yang bisa dihapus yeaa\n"; 
}else{
    if(head->next != NULL){
        head = head->next;
        head->prev = NULL; 
    }else{
        head=NULL;
        tail=NULL;
    }
    if(second_head->after != NULL){
        second_head = second_head -> after;
        second_head ->before = NULL;
    }else{
        second_head=NULL;
        second_tail=NULL; 
    }
}
        Node *current;
        Node *skg;
        int jumlah = 0;

        cout << "Barang berhasil dihapus!" << endl;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->items << "->"; 
        }

        // buat looping untuk menampilkan node di DLL
        for(current = head; current !=NULL; current = current->next){
            cout << "<-" << current->data << "->";
            jumlah = jumlah + current->data;
        }
        cout << "\n\n";
        cout << "Total: " << jumlah << "\n\n";
}

void hapusBlkg(){
int tmp;
string ember;

if(isEmpty()){
cout << "Data masih kosong !!";
} else {
    if(tail->prev != NULL){
        tmp = tail->data;
        tail = tail->prev;
        tail->next = NULL;


    }else {
        tmp = tail->data;
        tail = NULL; 
    }
    if(second_tail->before != NULL){
        ember = second_tail->items;
        second_tail = second_tail->before;
        second_tail->after = NULL;
    }else {
        ember = second_tail->items;
        second_tail = NULL; 
    }
        Node *current;
        Node *skg;
        int jumlah = 0;
        cout << "Data paling belakang berhasil dihapus!" << endl;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->items << "->"; 
        }
        // buat looping untuk menampilkan node di DLL
        for(current = head; current !=NULL; current = current->next){
            cout << "<-" << current->data << "->";
            jumlah = jumlah + current->data;
        }

        cout << "\n\n"; 
        cout << "Total: " << jumlah << "\n\n";
}
}

void tampil(){
    if(isEmpty()){
        cout << "KOSONG OKE" << endl;
    }else{
        Node *current;
        Node *skg;
        int jumlah = 0;

        cout << "Tampil();" << " | " << "Tampilkan semua data yang tersimpan" << endl;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->items << "->"; 
        }
        // buat looping untuk menampilkan node di DLL
        for(current = head; current !=NULL; current = current->next){
            cout << "<-" << current->data << "->";
            jumlah = jumlah + current->data;
        }

        cout << "\n\n"; 
        cout << "Total: " << jumlah << "\n\n";
    }
}

//Digunakan untuk print garis 
void garis(){
    int i = 0;
    cout << "\n";
    while(i!=75){
        cout << "-";
        i++;
    }
    cout << "\n";
}

//tampilkan head & tail
void tampilHead(){
    cout << "Isi dari head: " << head->data << endl;
}
void tampilTail(){
    cout << "Isi dari tail: " << tail->data << endl;
}


//Panggil fungsi agar untuk menampilkan nama dan nim
void perkenalan(){
    datdir.nama = "TIMOTHY MULYA CAHYANA";
    datdir.nim = "A11.2021.13887";

    cout << "NAMA: " << datdir.nama << "\n";
    cout << "NIM : " << datdir.nim << "\n";
}

int main(){
    garis();

    perkenalan();

    garis();
    cout << "Tugas pertemuan 10: " << endl;
    garis();
    awal();
    tambahDpn(8000, "Pringles");
    tambahDpn(11000, "Chips");
    tambahDpn(90000, "salmon");
    tampil();

    tmbhBlkg(22000, "Onigiri");

    hapusBlkg();
    tampil();

    hapusDpn();
    tampil();
    cout << "Tampilkan Head: " << endl;
    tampilHead();
    cout << "Tampilkan Tail: " << endl;
    tampilTail();

    garis();
    
    return 0; 
}