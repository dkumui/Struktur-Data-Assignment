#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku[0] = "The Alpha Girl's Guide";
    favorit.pengarang[0] = "Henry Manampiring";
    favorit.penerbit[0] = "Gagas Media";
    favorit.tebalHalaman[0] = 253;
    favorit.hargaBuku[0] = 79000;

    favorit.judulBuku[1] = "Si Anak Cahaya";
    favorit.pengarang[1] = "Tere Liye";
    favorit.penerbit[1] = "Tere Liye";
    favorit.tebalHalaman[1] = 473;
    favorit.hargaBuku[1] = 46000;
    
    favorit.judulBuku[2] = "Si Anak Pintar";
    favorit.pengarang[2] = "Tere Liye";
    favorit.penerbit[2] = "Tere Liye";
    favorit.tebalHalaman[2] = 374;
    favorit.hargaBuku[2] = 42000;

    favorit.judulBuku[3] = "Si Anak Spesial";
    favorit.pengarang[3] = "Tere Liye";
    favorit.penerbit[3] = "Tere Liye";
    favorit.tebalHalaman[3] = 406;
    favorit.hargaBuku[3] = 37000;

    favorit.judulBuku[4] = "Si Anak Kuat";
    favorit.pengarang[4] = "Tere Liye";
    favorit.penerbit[4] = "Tere Liye";
    favorit.tebalHalaman[4] = 476;
    favorit.hargaBuku[4] = 42000;

    // Menampilkan informasi buku favorit
    cout << "\t===== Buku Favorit Saya =====\n" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "\t=== Buku ke-" << i+1 << " ===" << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i]  << "\n" << endl;
    }

    return 0;
}