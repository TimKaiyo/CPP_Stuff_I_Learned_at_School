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

    //masukan data baru ke node baru
    //dengan ini terciptalah node baru
    //tapi belum masuk ke SLL

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;


    if(isEmpty()){
        //klo sll kosong maka nodebaru akan menjadi satu satunya node di dalam sll
        head = nodeBaru; 
        head->next = NULL; 
    }else {
        //klo sebelumnya sudah ada node di sll maka kita sambungkan pada node sebelumnya 
        nodeBaru->next = head;
        head = nodeBaru; //nodebaru menjadi head
    }
    cout << "Barang masyuk ke troleluy: " << nodeBaru->data << "\n"; 
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
        Node *bantu; //pakai node bantu
        bantu = head; //looping mulai
            do{
                //tampilkan node skr
                cout << bantu->data << "->";
                //pindah node selanjutnya
                bantu = bantu->next;
            }while(bantu!=NULL);
            /*
            for(bantu =head; bantu!=NULL; bantu=bantu->next){
                cout << bantu->data << "->"; 
            }
            */
    }
}



int main(){
    cout << "NIM: A11.2021.13887" << "\n";
    cout << "NAMA: TIMOTHY MULYA CAHYANA" << "\n";
    awal();
    tambahDepan(1);
    tambahDepan(2);
    tambahDepan(3);
    tambahDepan(4);
    tambahDepan(5); 
    tampol();

    hapusBelakang();
    tampol();

    return 0;
}