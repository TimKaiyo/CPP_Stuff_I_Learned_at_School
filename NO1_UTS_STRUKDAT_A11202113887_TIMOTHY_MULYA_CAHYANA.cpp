#include <iostream>
#include <stdlib.h>
#include <string>
#define MAX 5

using namespace std;

struct troly{
    int top, data[MAX];
    string nama[MAX];

};

troly harga;
troly jajanan;

//fungsi cek jajan habis
bool isEmpty(){
    return harga.top == -1;
}

// fungsi cek jajan full
bool isFull(){
    return harga.top == MAX -1; 
}

void push(string namaj, int krepek){
    if (isFull()){ //cek full
        cout << "full\n";
    }else{ //belum full bisa masuk
        harga.top = harga.top + 1; 
        harga.data[harga.top] = krepek;
        jajanan.nama[harga.top] = namaj;
        cout << "\ndata masuk ke troly: " << jajanan.nama[harga.top] << ", Harga: " << harga.data[harga.top] << "\n";
        
        cout << "\ntotal setelah push: ";
        int total;
         for (int x = harga.top; x>=1; x=x-1){
            total = total + harga.data[x];
        }
        cout << total << "\n";
    }
}

void tampilin(){
    if(isEmpty()){ 
        cout << "tidak ada data masuk\n";
    }else{ 
        cout << "\nISI TROLY: \n";
        for (int x = harga.top; x>=1; x=x-1){
            cout << "\nNama Barang: " << jajanan.nama[x] << ", Harga: " << harga.data[x] << "\n";
        }
        
    }
}

void pop(){
    if (isEmpty()){
        cout << "tidak ada data masuk kok di pop" << "\n";
    }else{
        harga.top = harga.top -1; 
    }

        cout << "total setelah pop: ";
        int total;
         for (int x = harga.top; x>=1; x=x-1){
            total = total + harga.data[x];
        }
        cout << total << "\n";
}


int main(){

    cout << "NAMA: TIMOTHY MULYA CAHYANA\n";
    cout << "NIM: A11.2021.13887\n";

    push("ikan", 5000);
    tampilin();

    push("pisang", 10000);
    push("apel", 5000);
    push("ayam", 20000);
    tampilin();

    pop();
    tampilin();
    return 0;
}