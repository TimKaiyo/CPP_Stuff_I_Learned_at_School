#include <iostream>

using namespace std;

int main(){
    int umur[6] = {3, 8, 9, 19, 6};
    cout << "1. Tampilkan isi array: ";
    for(int i = 0; i < 5; i++){
        cout << umur[i];
        if (i != 4){
            cout << ", ";
        }
    }

    cout << "\n\n" << "2. Input angka ke array umur: \n";
    int input;
    for (int i = 0; i < 6; i++){
        cout << "input(" << i + 1 << "): ";
        cin >> input;
        umur[i] = input;
    }

    for(int i = 0; i < 6; i++){
        cout << umur[i];
        if (i != 5){
            cout << ", ";
        }
    }
    
    cout << "\n\n3. ";
    for(int i = 0; i < 6; i++){
        cout << umur[i];
        if (i != 5){
            cout << " + ";
        }
    }

    cout << " = ";
    int hasil_jumlah = 0;
    for(int i = 0; i < 5; i++){
        hasil_jumlah = hasil_jumlah + umur[i];
    }
    cout << hasil_jumlah << "\n\n";

    cout << "4. Input sisi ke array(max 3): \n";
    int sisi[3] = {};
    int galon_aqua;
    for (int i = 0; i < 3; i++){
        cout << "input(" << i + 1 << "): ";
        cin >> galon_aqua;
        sisi[i] = galon_aqua;
    }
    
    cout << "\n";
    for(int i = 0; i < 3; i++){
        cout << "(" << sisi[i] << " * " << sisi[i] << ") ";
        if(i != 2){
            cout << " +  ";
        } 
    }
    cout << " = ";

    int hasil_perkalian = 0;
    for(int i = 0; i < 3; i++){
        hasil_perkalian = hasil_perkalian + (sisi[i]*sisi[i]);
    }
    cout << hasil_perkalian << "\n\n";


    return 0;
}