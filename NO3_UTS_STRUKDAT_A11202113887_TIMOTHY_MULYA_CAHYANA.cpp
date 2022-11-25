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

    cout << "\n\nHEAD = " << head->data;

    return 0;
}