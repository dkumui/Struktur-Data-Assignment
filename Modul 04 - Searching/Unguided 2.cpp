#include <iostream>
#include <string>
#include <cctype> // Untuk isalpha() dan tolower()

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVowels(const string& kalimat) {
    int count = 0;
    // Set huruf vokal yang ingin dihitung
    string vowels = "aiueo";

    // Iterasi melalui setiap karakter dalam kalimat
    for (char ch : kalimat) {
        // Ubah karakter menjadi lowercase
        char lowercaseCh = tolower(ch);
        // Periksa apakah karakter merupakan huruf dan merupakan huruf vokal
        if (isalpha(lowercaseCh) && vowels.find(lowercaseCh) != string::npos) {
            count++; // Tambahkan jumlah huruf vokal
        }
    }

    return count;
}

int main() {
    string kalimat;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat); // Input sebuah kalimat

    // Hitung jumlah huruf vokal dalam kalimat
    int jumlahVokal = countVowels(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal << endl;

    return 0;
}