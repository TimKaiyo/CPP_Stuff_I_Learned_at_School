#include <iostream>
#include <string>
#define MAX 10

using namespace std;

struct antrian{ 
    int top;
    string data[MAX];
};

antrian kebunBinatang;

bool isEmpty(){
    return kebunBinatang.top == -1;
}

bool isFull(){
    return kebunBinatang.top == MAX -1; 
}

void push(string macwan){
    if (isFull()){ 
        cout << "Antrian full\n";
    }else{ 
        kebunBinatang.top = kebunBinatang.top + 1;
        kebunBinatang.data[kebunBinatang.top] = macwan; 
        cout << "Pengunjung masuk:" << kebunBinatang.data[kebunBinatang.top] << "\n";
    }
}

void tampil(){
    if(isEmpty()){
        cout << "antrian kosong" << "\n";
    }else{
        for(int x=kebunBinatang.top; x >= 1; x=x-1){
            cout << kebunBinatang.data[x] << "(" << x << ")" << " - ";
        }
    }
    cout << "| Antrian masuk kebun binatang xyz |" << "\n"; 
}

void pop(){
    if(isEmpty()){
        cout  << "kosong" << "\n";
    }else{
        cout << "Melayani nomer: " << kebunBinatang.data[1] << "\n";
        for(int x=1; x <= kebunBinatang.top; x=x+1){
            kebunBinatang.data[x] = kebunBinatang.data[x+1]; 
        }
        kebunBinatang.top = kebunBinatang.top -1;
    }
}

int main(){

    push("nama");
    push("nama");
    push("nama");
    tampil();

    pop();
    tampil();
    return 0;
}