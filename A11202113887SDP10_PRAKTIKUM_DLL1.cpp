#include <iostream>
#include <string>

using namespace std;

struct Node{
    int data;
    string brg; 

    Node *after;
    Node *before;

    Node *next;
    Node *prev;

};

Node *head;
Node *tail;
Node *pala;
Node *bokong;

void awal(){
    head=NULL;
    tail=NULL;
    pala=NULL;
    bokong=NULL;
}

bool isEmpty(){
    if (head == NULL){
        return true;
    }
    if (pala == NULL){
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

    newNode->brg = barang;
    newNode->after = NULL;
    newNode->before = NULL;


    // sambungkan ke DLL sekarang
    if(isEmpty()){ //kondisi DLL kosong
        // langsung jadikan node pertama
        head = nodeBaru;
        tail = nodeBaru;
        head->next = NULL;
        head->prev = NULL;

        pala = newNode;
        bokong = newNode;
        pala->after = NULL;
        head->before = NULL;

    }else{ //kondisi DLL ada node
        // sambungkan nodebaru ke DLL skrng
        nodeBaru->next = head; // sambungin ke head
        head->prev = nodeBaru; // head sambungin ke nodebaru
        head = nodeBaru; // head ganti nodebaru

        newNode->after = pala;
        pala->before = newNode;
        pala = newNode;
    }
}

void tmbhBlkg(int dataBaru, string barang){
    Node *nodeBaru;
    nodeBaru = new Node;

    Node *newNode;
    newNode = new Node; 

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    newNode->brg = barang;
    newNode->after = NULL;
    newNode->before = NULL;

    if(isEmpty()){
        head=nodeBaru;
        tail=nodeBaru;
        head->next = NULL;
        head->prev = NULL; 

        pala=newNode;
        bokong=newNode;
        pala->after = NULL;
        pala->before = NULL;
    }else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;

        bokong->after = newNode;
        newNode->before = bokong;
        bokong = newNode; 
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
    if(pala->after != NULL){
        pala = pala -> after;
        pala ->before = NULL;
    }else{
        pala=NULL;
        bokong=NULL; 
    }
}
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
    if(bokong->before != NULL){
        ember = bokong->brg;
        bokong = bokong->before;
        bokong->after = NULL;
    }else {
        ember = bokong->brg;
        bokong = NULL; 
    }
}
}

void tampil(){
    if(isEmpty()){
        cout << "KOSONG OKEYY" << endl;
    }else{
        Node *current;
        Node *skg;
        int nom;

        // buat looping untuk menampilkan node di DLL
        for(current = head; current !=NULL; current = current->next){
            cout << "<-" << current->data << "->";
            nom = nom + current->data;
        }
        cout << "\n\n";
        for(skg = pala; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->brg << "->"; 
        }
        cout << "\n\n"; 
        cout << "Total: " << nom << "\n\n";
    }
}

void tampilHead(){
    cout << "Isi dari head: " << head->data << endl;
}
void tampilTail(){
    cout << "Isi dari tail: " << tail->data << endl;
}
void tampilPala(){
    cout << "Isi dari pala: " << pala->brg << "\n";
}
void tampilBokong(){
    cout << "Isi dari bokong " << bokong->brg << "\n"; 
}

int main ()
{
    awal();
    tambahDpn(8000, "ikan asin");
    tambahDpn(11000, "katjang meteh");
    tambahDpn(90000, "salmon");
    tampil();

    tmbhBlkg(22000, "petjel leleh");
    tampil();

    hapusBlkg();
    tampil(); 

    tampilTail();
    tampilHead();
    return 0;

}