#include <iostream> 
#include <string>
#include <stdlib.h>

using namespace std;
struct Node{
    int data; 
    Node *next; 
};

Node *head; 

void awal(){
    head=NULL; 
}

bool isEmpty(){
    if(head==NULL){
        return true;
    }
    else {
        return false;
    }
}

void tambahDepan(int dataBaru){
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
    cout << "DATA YANG MASUK KE NODE: " << nodeBaru->data << "\n"; 
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
    cout << dataBaru << " BERHASIL DITAMBAHKAN DIBELAKANG NODE" << "\n";
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
        cout << tmp << " SUDAH TERHAPUS" << "\n";
    }else{
        cout << "DATA MASIH KOSONG";
    }
}


void tampil(){
    if(isEmpty()){
        cout << "NODE KOSONG" << "\n";
    }else{
        cout << "\nISI DARI NODE: "; 
        Node *bantu; 
        bantu = head; 
            do{
                cout << bantu->data << "->";
                bantu = bantu->next;
            }while(bantu!=NULL);
    }
    cout << "\n\n";
}



int main(){
    cout << "NIM: A11.2021.13887" << "\n";
    cout << "NAMA: TIMOTHY MULYA CAHYANA" << "\n\n";
    awal();
    tambahDepan(1);
    tambahDepan(2);
    tambahDepan(3);
    tampil();

    hapusBelakang();
    tampil();

    tambahBlkg(8);
    tampil();
    return 0;
}