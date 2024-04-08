#include <iostream>
#include <string>
#include <cctype> // Untuk tolower()

using namespace std;

void binarysearch(const string& kalimat, char cari) {
    int index = -1; // Indeks karakter yang dicari
    int length = kalimat.length();

    // Konversi karakter cari menjadi lowercase
    cari = tolower(cari);

    // Iterasi melalui string untuk mencari karakter
    for (int i = 0; i < length; ++i) {
        if (tolower(kalimat[i]) == cari) {
            index = i;
            break; // Keluar dari loop jika karakter ditemukan
        }
    }

    if (index != -1)
        cout << "\nKarakter '" << cari << "' ditemukan pada index ke-" << index << endl;
    else
        cout << "\nKarakter '" << cari << "' tidak ditemukan dalam kalimat.\n";
}

int main() {
    string kalimat;

    cout << "\t BINARY SEARCH " << endl;
    cout << "\nMasukkan kalimat: ";
    getline(cin, kalimat); // Input sebuah kalimat

    char cari;
    cout << "Masukkan karakter yang ingin Anda cari dalam kalimat: ";
    cin >> cari;

    binarysearch(kalimat, cari);

    return 0;
}