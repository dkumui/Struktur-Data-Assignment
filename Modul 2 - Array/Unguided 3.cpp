#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  int arr[n];
  cout << "Masukkan data array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int max = arr[0], min = arr[0], sum = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
    sum += arr[i];
  }

  float avg = (float)sum / n;

  int choice;
  do {
    cout << "\nMenu:" << endl;
    cout << "1. Tampilkan nilai maksimum" << endl;
    cout << "2. Tampilkan nilai minimum" << endl;
    cout << "3. Tampilkan nilai rata-rata" << endl;
    cout << "0. Keluar" << endl;

    cout << "Masukkan pilihan: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Nilai maksimum: " << max << endl;
        break;
      case 2:
        cout << "Nilai minimum: " << min << endl;
        break;
      case 3:
        cout << "Nilai rata-rata: " << avg << endl;
        break;
      case 0:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (choice != 0);

  return 0;
}