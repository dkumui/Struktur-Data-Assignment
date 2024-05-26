#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "\nMasukkan jumlah elemen array: ";
  cin >> n;

  int arr[n];
  cout << "Masukkan data array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "\nData Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ", ";
  }

  cout << "\nNomor Genap: ";
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      cout << arr[i] << ", ";
    }
  }

  cout << "\nNomor Ganjil: ";
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != 0) {
      cout << arr[i] << " ";
    }
  }

  cout << endl;

  return 0;
}

