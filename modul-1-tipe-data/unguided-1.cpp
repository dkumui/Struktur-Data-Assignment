#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
int hitungLuasPersegi(int sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume kubus
int hitungVolumeKubus(int sisi) {
    return sisi * sisi * sisi;
}

int main() {
    char pilihanMenu; // Deklarasi variabel yang digunakan untuk memproses menu pilihan user
    float ukuranSisi; // Deklarasi variabel yang digunakan untuk menampung data input dari user
    cout << "1. Hitung Luas Persegi\n2. Hitung Volume Kubus\nPilih Menu (1,2) :" << endl;
    cin >> pilihanMenu; 

    switch (pilihanMenu)
    {
    case '1' :
        cout << "Masukkan  panjang sisi persegi: " <<endl;
        cin >> ukuranSisi;
        // Menampilkan hasil perhitungan luas persegi
        cout << "Luas Persegi dengan sisi " << ukuranSisi << " adalah: " << hitungLuasPersegi(ukuranSisi) << endl;   
        break;
    case '2' :
        cout << "Masukkan  panjang sisi persegi: " <<endl;
        cin >> ukuranSisi;
        // Menampilkan hasil perhitungan volume kubus
        cout << "Volume Kubus dengan sisi " << ukuranSisi << " adalah: " << hitungVolumeKubus(ukuranSisi) << endl;
        break;
    default:
        cout << "Menu Tidak Ada";
    }
    return 0;
}