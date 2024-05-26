#include <iostream>

using namespace std;

// Fungsi untuk menghitung berapa banyak angka 4 dalam array data
int countFours(const int data[], int length) {
    int count = 0;

    // Iterasi melalui setiap elemen dalam array data
    for (int i = 0; i < length; ++i) {
        // Periksa apakah elemen saat ini sama dengan angka 4
        if (data[i] == 4) {
            count++; // Tambahkan jumlah angka 4 yang ditemukan
        }
    }

    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int length = sizeof(data) / sizeof(data[0]);

    // Hitung berapa banyak angka 4 dalam array data
    int jumlahAngkaEmpat = countFours(data, length);

    cout << "Jumlah angka 4 dalam data adalah: " << jumlahAngkaEmpat << endl;

    return 0;
}