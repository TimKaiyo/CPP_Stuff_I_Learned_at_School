#include <iostream> 
#include <string>
#include <stdlib.h>

using namespace std;
struct Node{
    int data; 
    
    Node *next;
    Node *prev; 
};

Node *head; 
Node *tail;

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

//NULL <- 2 -> <- 10 M-> NULL
void tambahDepan(int dataBaru){

    //Buat Node Baru
    Node *nodeBaru;
    nodeBaru = new Node;

    //Bentuk node baru dengan data inputan
    nodeBaru->data = dataBaru; 
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    if(isEmpty()){
        //Kalo data kosong
        head = nodeBaru;
        tail = nodeBaru;
        head->next = NULL;
        head->prev = NULL;

        tail->next = NULL;
        tail->prev = NULL; 
    }else{
        nodeBaru->next = head;
        head ->prev = nodeBaru;
        head = nodeBaru;
    }
    cout << dataBaru << " BERHASIL DITAMBAHKAN" << endl;
}

void tambahBelakang(int dataBaru){
    Node *nodeBaru;
    nodeBaru = new Node;

    //Bentuk node baru dengan data inputan
    nodeBaru->data = dataBaru; 
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    if(isEmpty()){
        //Kalo data kosong
        head = nodeBaru;
        tail = nodeBaru;
        head->next = NULL;
        head->prev = NULL;

        tail->next = NULL;
        tail->prev = NULL; 
    }else{
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
    }
    cout << dataBaru << " BERHASIL DITAMBAHKAN DI BELAKANG" << endl;
}

void hapusBelakang(){
    Node *hapus; 
    if(isEmpty()){
        cout << "Data DLL masih kosong";
    }else{
        if(head->next != NULL){
            hapus = tail;
            tail = tail->prev; 
            tail->next = NULL; 
        }else{
            // data cuma
            hapus = head;
            head = NULL;
            tail = NULL;
        }
        cout << "Data paling belakang terhapus" << endl;
        delete hapus;
    }
}

void hapusDepan(){
        Node *hapus; 
    if(isEmpty()){
        cout << "Data DLL masih kosong";
    }else{
        if(head->next != NULL){
            hapus = head;
            head = head->next; 
            head->prev = NULL; 
        }else{
            // data cuma
            hapus = head;
            head = NULL;
            tail = NULL;
        }
        cout << "Data paling depan terhapus" << endl;
        delete hapus;
    }
}


void tampil(){
    Node *current;

    current = head;
    if(!isEmpty()){
        while(current != NULL){
            cout << "<- " << current->data << " ->";
            current = current->next;
        }
        cout << endl;
    }else {
        cout << " BELUM ADA DATA DI DLL " << endl;
    }
}

void menu(){
    int pil;
    cout << "MENU";
    cout << "1. Tambah Depan\n2. Tambah Belakang\n3. Hapus Depan\n4. Hapus Belakang\n5. Exit\n";
    cout << "Silahkan pilih salah satu: ";
    cin >> pil;

    if (pil > 5 || pil <= 0){
        cout << "\nJangan input lebih dari 4!" << endl;
        menu();
    }else{
        int angka; 
        if(pil == 1 ){
            cout << "\nSilahkan masukan angka untuk tambah depan -> ";
            cin >> angka;
            tambahDepan(angka);
            tampil();
            cout << endl;
            menu();
        }
        else if(pil == 2){
            cout << "\nSilahkan masukan angka untuk tambah belakang -> ";
            cin >> angka;
            tambahBelakang(angka);
            tampil();
            cout << endl;
            menu();
        }else if(pil == 3){
            cout << "\nHapus Depan\n";
            hapusDepan();
            tampil();
            cout << endl;
            menu();
        }else if(pil == 4){
            cout << "\nHapus Belakang\n";
            hapusBelakang();
            tampil();
            cout << endl;
            menu();
        }else if(pil == 5){
            exit(0);
        }
    }
}

int main(){
    cout << "A11.2021.13887 - TIMOTHY MULYA CAHYANA\n";
    cout << "--- MENU ---\n";
    menu();
    
    return 0; 
}