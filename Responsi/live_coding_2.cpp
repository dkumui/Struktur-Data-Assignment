// 2. REKURSIF

#include <iostream>

using namespace std;

int main() {
    int cari;
    cout << "Masukkan angka: ";
    cin >> cari;
    for(int n = 0; n < cari; cari--) {
        cout << cari << ", ";
    }
}