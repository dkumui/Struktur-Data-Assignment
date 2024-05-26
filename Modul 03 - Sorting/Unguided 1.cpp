#include <iostream>
using namespace std;

int main() {
  // Array untuk menyimpan nilai IPS
  float ips[5] = {3.8, 2.9, 3.3, 4.0, 2.4};

  // Menjalankan algoritma Selection Sort
  for (int i = 0; i < 5; i++) {
    int minIndex = i;
    for (int j = i + 1; j < 5; j++) {
      if (ips[minIndex] < ips[j]) {
        minIndex = j;
      }
    }
    // Menukar nilai IPS pada indeks minimum dengan indeks saat ini
    float temp = ips[i];
    ips[i] = ips[minIndex];
    ips[minIndex] = temp;
  }

  // Menampilkan hasil pengurutan
  cout << "\nIPS mahasiswa setelah diurutkan dari terbesar ke terkecil:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << ips[i] << ", ";
  }
  cout << endl;

  return 0;
}
