#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Define Node structure
struct Node {
  string nama;
  string nim;
  Node *next;
};

Node *head;
Node *tail;

// Initialize the linked list
void init() {
  head = NULL;
  tail = NULL;
}

// Check if the linked list is empty
bool isEmpty() {
  return (head == NULL);
}

// Insert node at the front
void insertDepan(string nama, string nim) {
  Node *baru = new Node;
  baru->nama = nama;
  baru->nim = nim;
  baru->next = NULL;

  if (isEmpty()) {
    head = tail = baru;
  } else {
    baru->next = head;
    head = baru;
  }
}

// Insert node at the back
void insertBelakang(string nama, string nim) {
  Node *baru = new Node;
  baru->nama = nama;
  baru->nim = nim;
  baru->next = NULL;

  if (isEmpty()) {
    head = tail = baru;
  } else {
    tail->next = baru;
    tail = baru;
  }
}

// Count the number of nodes in the linked list
int hitungList() {
  Node *hitung = head;
  int jumlah = 0;
  while (hitung != NULL) {
    jumlah++;
    hitung = hitung->next;
  }
  return jumlah;
}

// Insert node in the middle
void insertTengah(string nama, string nim, int posisi) {
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Posisi tidak valid. Posisi harus di anatara 1 dan jumlah node." << endl;
    return;
  } else if (posisi == 1) {
    insertDepan(nama, nim);
    return;
  } else {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    Node *bantu = head;
    for (int i = 1; i < posisi - 1; i++) {
      bantu = bantu->next;
    }

    baru->next = bantu->next;
    bantu->next = baru;
  }
}

// Delete node at the front
void hapusDepan() {
  if (!isEmpty()) {
    Node *hapus = head;
    if (head->next != NULL) {
      head = head->next;
    } else {
      head = tail = NULL;
    }
    cout << "Data mahasiswa dengan nama " << hapus->nama << " berhasil dihapus" << endl;
    delete hapus;
  } else {
    cout << "List Kosong!" << endl;
  }
}

// Delete node at the back
void hapusBelakang() {
  if (!isEmpty()) {
    Node *hapus = tail;
    if (head != tail) {
      Node *bantu = head;
      while (bantu->next != tail) {
        bantu = bantu->next;
      }
      tail = bantu;
      tail->next = NULL;
    } else {
      head = tail = NULL;
    }
    cout << "Data mahasiswa dengan nama " << hapus->nama << " berhasil dihapus" << endl;
    delete hapus;
  } else {
    cout << "List Kosong!" << endl;
  }
}

// Delete node in the middle
void hapusTengah(int posisi) {
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Posisi tidak valid. Posisi harus di anatara 1 dan jumlah node." << endl;
    return;
  } else if (posisi == 1) {
    hapusDepan();
    return;
  } else {
    Node *hapus;
    Node *bantu = head;
    for (int i = 1; i < posisi - 1; i++) {
      bantu = bantu->next;
    }
    hapus = bantu->next;
    bantu->next = hapus->next;
    cout << "Data mahasiswa dengan nama " << hapus->nama << " berhasil dihapus" << endl;
    delete hapus;
  }
}

// Update data in the front node
void ubahDepan(string namaBaru, string nimBaru) {
  if (!isEmpty()) {
    
    string namaLama = head->nama;
    string nimLama = head->nim;
    
    head->nama = namaBaru;
    head->nim = nimBaru;

    if (namaLama != namaBaru && nimLama != nimBaru) {
      cout << "Data " << namaLama << " (" << nimLama << ") telah diganti dengan data " << namaBaru << " (" << nimBaru << ")" << endl;
    } else if (namaLama != namaBaru) {
      cout << "Nama telah diganti dari " << namaLama << " menjadi " << namaBaru << endl;
    } else if (nimLama != nimBaru) {
      cout << "NIM telah diganti dari " << nimLama << " menjadi " << nimBaru << endl;
    }
  } else {
    cout << "List Kosong!" << endl;
  }
}

// Update data in the middle node
void ubahTengah(string namaBaru, string nimBaru, int posisi) {
  if (!isEmpty()) {
    if (posisi < 1 || posisi > hitungList()) {
      cout << "Posisi tidak valid. Posisi harus di antara 1 dan jumlah node." << endl;
      return;
    } else if (posisi == 1) {
      ubahDepan(namaBaru, nimBaru);
      return;
    } else {
      Node *bantu = head;
      for (int i = 1; i < posisi; i++) {
        bantu = bantu->next;
      }
      string namaLama = bantu->nama;
      string nimLama = bantu->nim;

      bantu->nama = namaBaru;
      bantu->nim = nimBaru;

      if (namaLama != namaBaru && nimLama != nimBaru) {
        cout << "Data " << namaLama << " (" << nimLama << ") pada posisi " << posisi << " telah diganti dengan data " << namaBaru << " (" << nimBaru << ")" << endl;
      } else if (namaLama != namaBaru) {
        cout << "Nama pada posisi " << posisi << " telah diganti dari " << namaLama << " menjadi " << namaBaru << endl;
      } else if (nimLama != nimBaru) {
        cout << "NIM pada posisi " << posisi << " telah diganti dari " << nimLama << " menjadi " << nimBaru << endl;
      }
    }
  } else {
    cout << "List Kosong!" << endl;
  }
}

// Update data in the back node
void ubahBelakang(string namaBaru, string nimBaru) {
  if (!isEmpty()) {

    string namaLama = tail->nama;
    string nimLama = tail->nim;
    
    tail->nama = namaBaru;
    tail->nim = nimBaru;

    if (namaLama != namaBaru && nimLama != nimBaru) {
      cout << "Data " << namaLama << " (" << nimLama << ") telah diganti dengan data " << namaBaru << " (" << nimBaru << ")" << endl;
    } else if (namaLama != namaBaru) {
      cout << "Nama telah diganti dari " << namaLama << " menjadi " << namaBaru << endl;
    } else if (nimLama != nimBaru) {
      cout << "NIM telah diganti dari " << nimLama << " menjadi " << nimBaru << endl;
    }
  } else {
    cout << "List Kosong!" << endl;
  }
}

// Clear the linked list
void clearList() {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }
  Node *hapus;
  while (head != NULL) {
    hapus = head;
    head = head->next;
    delete hapus;
  }
  tail = NULL;
  cout << "List berhasil dihapus!" << endl;
}

// Display the linked list
void tampil() {
  Node *bantu = head;
  if (!isEmpty()) {
    cout << "---------------------------------------------" << endl;
    cout << "| No. |       Nama       |        NIM       |" << endl;
    cout << "---------------------------------------------" << endl;
    int i = 1;
    while (bantu != NULL) {
      cout << "| " << setw(3) << i << " | " << setw(16) << bantu->nama << " | " << setw(16) << bantu->nim << " |" << endl;
      bantu = bantu->next;
      i++;
    }
    cout << "---------------------------------------------" << endl;
  } else {
    cout << "List Kosong!" << endl;
  }
}

// Main function
int main() {
  init();

  int pilihan;
  string nama, nim;
  int posisi;

  do {
    cout << "\nMENU LINKED LIST MAHASISWA" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Tambah Data Depan" << endl;
    cout << "2. Tambah Data Belakang" << endl;
    cout << "3. Tambah Data Tengah" << endl;
    cout << "4. Hapus Data Depan" << endl;
    cout << "5. Hapus Data Belakang" << endl;
    cout << "6. Hapus Data Tengah" << endl;
    cout << "7. Ubah Data Depan" << endl;
    cout << "8. Ubah Data Tengah" << endl;
    cout << "9. Ubah Data Belakang" << endl;
    cout << "10. Tampilkan Data" << endl;
    cout << "11. Hapus Semua Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "\nPilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        insertDepan(nama, nim);
        cout << "Data berhasil ditambahkan" << endl;
        break;
      case 2:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        insertBelakang(nama, nim);
        cout << "Data berhasil ditambahkan"  << endl;;
        break;
      case 3:
        tampil();
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan posisi (1-" << hitungList() << "): ";
        cin >> posisi;
        insertTengah(nama, nim, posisi);
        cout << "Data berhasil ditambahkan"  << endl;;
        break;
      case 4:
        hapusDepan();
        break;
      case 5:
        hapusBelakang();
        break;
      case 6:
        tampil();
        cout << "Masukkan posisi (1-" << hitungList() << "): ";
        cin >> posisi;
        hapusTengah(posisi);
        break;
      case 7:
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahDepan(nama, nim);
        break;
      case 8:
        tampil();
        cout << "Masukkan posisi (1-" << hitungList() << "): ";
        cin >> posisi;
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahTengah(nama, nim, posisi);
        break;
      case 9:
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahBelakang(nama, nim);
        break;
      case 10:
        tampil();
        break;
      case 11:
        clearList();
        break;
      case 0:
        cout << "Keluar dari program." << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 0);

  return 0;
}
