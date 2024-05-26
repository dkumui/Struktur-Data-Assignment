#include <iostream>

using namespace std;

void ascendingSort(char arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[i] > arr[j]) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void descendingSort(char arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[i] < arr[j]) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int n;
  cout << "\nMasukkan jumlah karakter (n): ";
  cin >> n;

  char characters[n];

  for (int i = 0; i < n; ++i) {
    cout << "Masukkan karakter ke-" << i + 1 << ": ";
    cin >> characters[i];
  }

  // Menampilkan urutan karakter sebelum sorting
  cout << "Urutan karakter sebelum sorting: ";
  for (int i = 0; i < n; ++i) {
    cout << characters[i] << " ";
  }
  cout << endl;

  // Sorting secara menaik (ascending)
  ascendingSort(characters, n);

  // Menampilkan urutan karakter setelah sorting ascending
  cout << "Urutan karakter setelah ascending sort: ";
  for (int i = 0; i < n; ++i) {
    cout << characters[i] << " ";
  }
  cout << endl;

  // Sorting secara menurun (descending)
  descendingSort(characters, n);

  // Menampilkan urutan karakter setelah sorting descending
  cout << "Urutan karakter setelah descending sort: ";
  for (int i = 0; i < n; ++i) {
    cout << characters[i] << " ";
  }
  cout << endl;

  return 0;
}
