#include <iostream>

using namespace std;

int main(){
    int input, n_case; 

    cout << "Masukan Nilai 1 - 10: ";
    cin >> input;
    cout << "Pilih Case 1 atau 2: ";
    cin >> n_case;

    if (n_case >= 3){
        cout << "\nNilai maks case adalah 2, coba masukan nilai kembali!\n"; 
        main();
    }
    switch(n_case){
        case 1: 
            if(input <= 5){
                for(int i=input; i >= 0; i--){
                    cout << i;
                    if(i != 0 ){
                        cout << " -> "; 
                    }
                }
            }else{
                for(int i=input; i >= 5; i--){
                    cout << i;
                    if(i != 5 ){
                        cout << " -> "; 
                    }
                }
            }
            break; 
        case 2:
            if(input <= 5){
                for(int i=input; i <= 5; i++){
                    cout << i;
                    if(i != 5 ){
                        cout << " -> "; 
                    }
                }
            }else{
                for(int i=input; i <= 10; i++){
                    cout << i;
                    if(i != 10 ){
                        cout << " -> "; 
                    }
                }
            }
            break; 
    }
    return 0; 
}

