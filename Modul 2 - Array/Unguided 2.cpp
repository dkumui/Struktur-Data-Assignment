#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk menyimpan ukuran array
    int size_x, size_y, size_z;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "\nMasukkan ukuran array (x y z): ";
    cin >> size_x >> size_y >> size_z;

    // Deklarasi array sesuai dengan ukuran yang dimasukkan pengguna
    int arr[size_x][size_y][size_z];

    // Input elemen array
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            for (int z = 0; z < size_z; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Tampilan array
    cout << "Array:\n";
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            for (int z = 0; z < size_z; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
