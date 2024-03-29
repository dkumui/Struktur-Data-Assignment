#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;

  // Meminta user untuk menginputkan jumlah karakter
  cout << "Masukkan jumlah karakter: ";
  cin >> n;

  // Deklarasi array untuk menyimpan karakter
  char karakter[n];

  // Meminta user untuk menginputkan karakter
  cout << "Masukkan " << n << " karakter: ";
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Sorting karakter secara ascending
  sort(karakter, karakter + n);

  // Menampilkan hasil sorting ascending
  cout << "Karakter setelah sorting ascending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  // Sorting karakter secara descending
  sort(karakter, karakter + n, greater<char>());

  // Menampilkan hasil sorting descending
  cout << "Karakter setelah sorting descending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  return 0;
}
