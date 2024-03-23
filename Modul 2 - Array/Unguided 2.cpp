#include <iostream>

using namespace std;

int main() {
  int m, n, o;

  cout << "Masukkan jumlah matriks array: ";
  cin >> m;

  cout << "Masukkan jumlah baris array: ";
  cin >> n;

  cout << "Masukkan jumlah kolom array: ";
  cin >> o;

  int arr[m][n][o];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < o; k++) {
        cout << "Masukkan data array [" << i << "][" << j << "][" << k << "]: ";
        cin >> arr[i][j][k];
      }
    }
  }

  cout << "\nData Array:" << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < o; k++) {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
