// 1. SEQUENTIAL SEARCH

#include <iostream>

using namespace std;

void sequential_search(int data[], int length, int cari) {

    bool b_flag = false;
    for(int i = 0; i < length; i++) {
        if(data[i] == cari) {
            b_flag = true;
            cout << "\nData ditemukan di indeks ke-" << i << endl;
        }
    }
    if(!b_flag) {
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main() {
    int data[6] = {1, 2, 3, 4, 5, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int cari;

    cout << "\t ======= Sequential Search ======= " << endl;

    cout << endl;

    for(int i = 0; i < length; i++){
        cout << data[i] << " ";
    }

    cout << endl;

    cout << "Masukkan data yang ingin anda cari: ";
    cin >> cari;

    sequential_search(data, length, cari);

    return EXIT_SUCCESS;
}