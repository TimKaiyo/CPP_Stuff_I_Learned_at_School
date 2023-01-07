#include <iostream>
#include <string>

using namespace std;
int storage[1];
int revenue[1];  

struct Node{
    int data;
    int items; 

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

void tmbhBlkg(int dataBaru, int inputEmber){
    Node *nodeBaru;
    nodeBaru = new Node;

    Node *newNode;
    newNode = new Node; 

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    newNode->items = inputEmber;
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
        int i_count = 1;
        int jumlah = 0;  
        for(current = head; current !=NULL; current = current->next){ 
            //cout << " Ember ke: <-" << current->data << "->";
            jumlah = jumlah + current->data;
            i_count++;
        }
        for(skg = second_head; skg !=NULL; skg = skg->after){
            //cout << " Isi(Liter): <-" << skg->items << "->\n"; 
        }

        storage[0] = i_count;
        cout << "BERHASIL DITAMBAHKAN!" << endl;
}

void hapusDpn(){
if(isEmpty()){
cout << "Tidak ada node yang bisa ditumpahkan yeaa\n"; 
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

        cout << "Ember berhasil ditumpahkan!" << endl;
        for(skg = second_head; skg !=NULL; skg = skg->after){
            //cout << "<-" << skg->items << "->"; 
        }

        // buat looping untuk menampilkan node di DLL
        for(current = head; current !=NULL; current = current->next){
            //cout << "<-" << current->data << "->";
            jumlah = jumlah + current->data;
        }
        cout << "BERHASIL DIHAPUS!\n";
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


//hanya sebuah relic yang tak penuh/terpanggil awkaowkoawokawoakw
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
    }
}

void total(){
    int total_revenue = revenue[0] * 5;
    cout << "Jumlah Total(Liter) Pasir yang telah dikeluarkan: " << total_revenue << "\n";
}

void availability(){
    int available_ember = 10 - storage[0];
    int ember_full = storage[0]; 

    cout << "Jumlah Ember kosong: " << available_ember << "\n";
    cout << "Jumlah Ember yang penuh: " << ember_full << "\n";
}

void lineCount(){
    cout << "Jumlah ember yang terpakai: " << storage[0] << "\n";
}

void displayEmber(){
    Node *skg; 
    for(skg = second_head; skg !=NULL; skg = skg->after){
        cout << "<-" << skg->items << "->\n"; 
    }
}

void hapoes(){
    int brp = 0;
    cout << "EMBERNYA MAU DIKELUARIN BERAPA KALI(Max 10)?\nInput:";
    cin >> brp;
    for(int i = 1; i <= brp; i++){
        hapus();
    }

}

void tambuah(){
    int ember = 0;
    ember = ember + storage[0];
    int isi = 5;
    tmbhBlkg(ember, isi);
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
    string pilihan[6] = {"Jumlah Pasir yang berhasil dikeluarkan", "cek ember yang Kosong", "Jumlah ember yang terpakai", "Hapus Depan", "Tambah Belakang", "Exit" };

    cout << "PILIH FITUR:\n"; 
    for(int i = 1; i < 7; i++){
        cout << i << ". " << pilihan[i-1] << endl; 
    }
    cout << "Silahkan input pilihan anda: "; cin >> casval; 

    if (casval > 7){
        cout << "\nPASTIKAN ANGKA TIDAK LEBIH DARI 6\n"; 
        menu(); 
    }else{
        switch(casval){
        case 1:
            n();
            line();
            total();
            line();
            menu();
            break;
        case 2:
            n();
            line();
            availability();
            line();
            menu(); 
            break;
        case 3:
            n();
            line();
            lineCount();
            line();
            menu();
            break;
        case 4:
            n();
            cout << "Hapus Depan!\n";
            line();
            hapoes();
            line();
            menu();
            break;
        case 5:
            n();
            cout << "Tambah Belakang!\n";
            line(); 
            tambuah();
            line();
            menu();
            break;
        case 6:
            tampil();
            exit(0);
        }
        
    }
}

int main(){
    line();

    perkenalan();

    line();
    cout << "UAS_A11.2021.13887_TIMOTHY MULYA CAHYANA " << endl;
    line();

    cout << "Jika dimisalkan cuman ada 10 ember yang tersedia\n\n";
    awal();
    tambuah();
    tambuah();
    tambuah();
    
    tampil();

    menu(); 

    line();
    
    return 0; 
}