#include <iostream>
#include <string>

using namespace std;

int main() {
  // Array untuk menyimpan nama warga
  string nama[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Menjalankan algoritma Bubble Sort
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        string temp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = temp;
      }
    }
  }

  // Menampilkan hasil pengurutan
  cout << "Daftar nama warga setelah diurutkan:" << endl;
  for (int i = 0; i < 10; i++) {
    cout << nama[i] << " ";
  }
  cout << endl;

  return 0;
}