#include <iostream> 
#include <string>
#include <stdlib.h>

using namespace std;
//Deklarasi node dalam struct
struct Node{
    int data; //data dalam node
    Node *next; //pointer dalam node
};

Node *head; //buat object head

void awal(){
    head=NULL; //waktu awal head = null 
}

bool isEmpty(){
    if(head==NULL){ //kalau head tidak ada otomatis node tidak exist
        return true;
    }
    else {
        return false;
    }
}

void tambahDepan(int dataBaru){
    //buat node baru
    Node *nodeBaru; 

    nodeBaru = new Node; 

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;


    if(isEmpty()){
        head = nodeBaru; 
        head->next = NULL; 
    }else {
        nodeBaru->next = head;
        head = nodeBaru; 
    }
    cout << "Barang masyuk ke troleluy: " << nodeBaru->data << "\n"; 
}

void tambahBlkg(int dataBaru){
    Node *nodeBaru, *bantu;
    nodeBaru = new Node;
    nodeBaru->data = dataBaru;
    nodeBaru->next= NULL;

    if(isEmpty()){
        head = nodeBaru;
        head->next = NULL;
    }else{
        bantu = head;
        while(bantu->next != NULL){
            bantu = bantu->next;
        }
        bantu->next = nodeBaru;
    }
    cout << dataBaru << " Berhasil ditambahkan dibelakang" << "\n";
}

void hapusBelakang(){
    Node *hapus, *bantu;
    int tmp; 
    if(!isEmpty()){
        if(head->next!=NULL){
            bantu = head; 
            while (bantu->next->next!=NULL){
                bantu = bantu->next;
            }
            hapus = bantu->next;
            tmp = hapus->data;
            bantu->next=NULL; 
            delete hapus;
        }else{
            tmp = head->data;
            head=NULL; 
        }
        cout << tmp << "sudah terhapus" << "\n";
    }else{
        cout << "Data masih kosong";
    }
}


void tampol(){
    if(isEmpty()){
        cout << "troleley kosong" << "\n";
    }else{
        cout << "ISI TROLALUY: "; 
        Node *bantu; 
        bantu = head; 
            do{
                cout << bantu->data << "->";
                bantu = bantu->next;
            }while(bantu!=NULL);
    }
}



int main(){
    cout << "NIM: A11.2021.13887" << "\n";
    cout << "NAMA: TIMOTHY MULYA CAHYANA" << "\n";
    awal();
    tambahDepan(1);
    tambahDepan(2);
    tambahDepan(3);
    tampol();

    hapusBelakang();
    tampol();

    tambahBlkg(8);
    tampol();

    
    cout << "\n\nHEAD = " << head->data;

    return 0;
}