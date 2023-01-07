#include <iostream>
#include <string>

using namespace std;
int storage[1];
int revenue[1];  

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
} data_diri;


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

void tmbhBlkg(int dataBaru, string platNomor){
    Node *nodeBaru;
    nodeBaru = new Node;

    Node *newNode;
    newNode = new Node; 

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    newNode->items = platNomor;
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
        int i_count = 0;
        int jumlah = 0;  

        // buat looping untuk menampilkan node di DLL
       // cout << "Plat Nomor yang ditambahkan: " << endl;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            //cout << "<-" << skg->items << "->\n"; 
        }
        for(current = head; current !=NULL; current = current->next){ 
            //cout << current->data << "+";
            jumlah = jumlah + current->data;
            for(int i = 1; i <= 1; i++){
                i_count = i_count + i; 
            }
        }

        storage[0] = i_count;
        //cout << "\n\n"; 
        /*cout << "Total: " << jumlah << "\n";*/
        //cout << "Count: " << i_count << "\n";
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

        cout << "Plat Nomor berhasil dihapus!" << endl;
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

void hapus(){
    if (revenue[0] == 1){
        revenue[0] = revenue[0] - 1;

        int x = revenue[0]; 
        x = x + 1;
        revenue[0] = x;
    }else{
        int x = revenue[0]; 
        x = x + 1;
        revenue[0] = x;
    }

    hapusDpn();
}


//hanya sebuah relic yang tak terpakai/terpanggil awkaowkoawokawoakw
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

        cout << "\n"; 
        cout << "Total: " << jumlah << "\n\n";
    }
}



void total(){
    int total_revenue = revenue[0] * 5000;
    cout << "Total pendapatan: " << total_revenue << "\n";
}

void availability(){
    int available_spot = 10 - storage[0];
    int occupied_spot = storage[0]; 

    cout << "Jumlah parkiran kosong: " << available_spot << "\n";
    cout << "Jumlah parkiran yang terpakai: " << occupied_spot << "\n";
}

void lineCount(){
    cout << "Jumlah kendaraan yang antri bayar: " << storage[0] << "\n";
}

void where(){
    if(isEmpty()){
        cout << "KOSONG OKE" << endl;
    }else{
        Node *current;
        Node *skg;
        int i = 0;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            cout << "<-" << skg->items << "->"; 
            for(current = head; current !=NULL; current = current->next){
                cout << "<-A" << current->data + i << "->";
                break;
            }
            i++;
        }
        // buat looping untuk menampilkan node di DLL
        cout << "\n";
    }
}

void displayPlatNo(){
    Node *skg; 
    for(skg = second_head; skg !=NULL; skg = skg->after){
        cout << "<-" << skg->items << "->\n"; 
    }
}

//Digunakan untuk print line 
void line(){
    int i = 0;
    cout << "\n";
    while(i!=75){
        cout << "-";
        i++;
    }
    cout << "\n";
}

//Panggil fungsi agar untuk menampilkan nama dan nim
void perkenalan(){
    data_diri.nama = "TIMOTHY MULYA CAHYANA";
    data_diri.nim = "A11.2021.13887";

    cout << "NAMA: " << data_diri.nama << "\n";
    cout << "NIM : " << data_diri.nim << "\n";
}

void n(){
    cout << "\n\n";
}

void menu(){
    int casval = 0;
    string pilihan[5] = {"Jumlah Pendapatan", "Parkiran Kosong", "Hitung Kendaraan Yang Sedang Antri", "Cari Letak Mobil", "Exit" };

    cout << "PILIH FITUR:\n"; 
    for(int i = 1; i < 6; i++){
        cout << i << ". " << pilihan[i-1] << endl; 
    }
    cout << "Silahkan input pilihan anda: "; cin >> casval; 

    if (casval > 5){
        cout << "\nPASTIKAN ANGKA TIDAK LEBIH DARI 5\n"; 
        menu(); 
    }else{
        string temp_str; 
        switch(casval){
        case 1:
            n();
            total();
            menu();
            break;
        case 2:
            n();
            availability();
            menu(); 
            break;
        case 3:
            n();
            lineCount();
            menu();
            break;
        case 4:
            n();
            cout << "Daftar mobil dan dimana mobil itu diletakan: \n";
            where();
            menu();
            break;
        case 5:
            exit(0);
        }
        
    }
}

int main(){
    int initializer = 0; 

    line();

    perkenalan();

    line();
    cout << "Tugas pertemuan 14: " << endl;
    line();
    awal();
    
    cout << "Beberapa data awal: " << endl;
    tmbhBlkg(1, "F 12345 Y");
    tmbhBlkg(2, "B 12346 Y");
    tmbhBlkg(3, "G 123457 Y");
    tampil();

    menu(); 

    line();
    
    return 0; 
}