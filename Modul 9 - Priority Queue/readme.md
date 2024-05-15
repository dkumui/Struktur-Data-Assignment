# <h1 align="center">Laporan Praktikum Modul Priority Queue</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Priority queue adalah jenis antrian yang mengatur elemen berdasarkan nilai prioritasnya [1]. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Terdapat beberapa cara untuk mengimplementasikan priority queue, termasuk menggunakan array, linked list, heap, atau binary search tree [2].

Heap dalam struktur data adalah struktur berbasis pohon biner dengan aturan tertentu. Heap memiliki ciri khas berupa complete binary tree dan property order [3]. Heap dapat dibagi menjadi max-heap dan min-heap. Max-heap memiliki nilai parent lebih besar atau sama dengan anak, sedangan min-heap sebaliknya [4].

Operasi utama pada heap antara lain insert, extract max/min, dan change priority. Operasi-operasi tersebut dapat dilakukan dengan kompleksitas waktu O(logN) menggunakan shiftUp dan shiftDown[5]. Heap sering digunakan untuk priority queue dan algoritma sorting seperti heap sort.

## Guided

### 1. Queue

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize++;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize--;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
    cout << "Node with maximum priority : " << extractMax() << "\n";
    cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
    changePriority(2, 49);
    cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
    remove(3);
    cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```

### Interpretasi:

Kodingan ini mengimplementasikan struktur data **Max Heap** dan algoritma **Heap Sort** untuk mengurutkan data. Berikut interpretasinya:

**1. Menyertakan Header:**

```c++
#include <iostream>
#include <algorithm>
```

* `<iostream>` untuk input/output standar seperti `cout`.
* `<algorithm>` untuk fungsi `swap` yang digunakan untuk menukar elemen array.

**2. Deklarasi Array dan Variabel:**

```c++
using namespace std;

int H[50];
int heapSize = -1;
```

* `H`: Array dengan ukuran 50 untuk menyimpan elemen heap.
* `heapSize`: Variabel untuk menyimpan ukuran heap saat ini (dimulai dari -1).

**3. Fungsi untuk Mencari Indeks Parent:**

```c++
int parent(int i) {
  return (i - 1) / 2;
}
```

Fungsi `parent(i)` mengembalikan indeks parent dari elemen pada indeks `i` di dalam heap.

**4. Fungsi untuk Mencari Indeks Left Child:**

```c++
int leftChild(int i) {
  return (2 * i) + 1;
}
```

Fungsi `leftChild(i)` mengembalikan indeks left child dari elemen pada indeks `i` di dalam heap.

**5. Fungsi untuk Mencari Indeks Right Child:**

```c++
int rightChild(int i) {
  return (2 * i) + 2;
}
```

Fungsi `rightChild(i)` mengembalikan indeks right child dari elemen pada indeks `i` di dalam heap.

**6. Fungsi untuk Shift Up:**

```c++
void shiftUp(int i) {
  while (i > 0 && H[parent(i)] < H[i]) {
    swap(H[parent(i)], H[i]);
    i = parent(i);
  }
}
```

Fungsi `shiftUp(i)` digunakan untuk menjaga sifat heap (nilai parent lebih besar sama dengan anak) setelah elemen pada indeks `i` diubah. Dilakukan perulangan untuk menukar elemen dengan parentnya ke atas sampai mencapai parent dengan nilai yang lebih besar atau sama.

**7. Fungsi untuk Shift Down:**

```c++
void shiftDown(int i) {
  int maxIndex = i;
  int l = leftChild(i);
  if (l <= heapSize && H[l] > H[maxIndex]) {
    maxIndex = l;
  }
  int r = rightChild(i);
  if (r <= heapSize && H[r] > H[maxIndex]) {
    maxIndex = r;
  }
  if (i != maxIndex) {
    swap(H[i], H[maxIndex]);
    shiftDown(maxIndex);
  }
}
```

Fungsi `shiftDown(i)` digunakan untuk menjaga sifat heap (nilai parent lebih besar sama dengan anak) setelah elemen pada indeks `i` diubah. Dilakukan perulangan untuk mencari anak dengan nilai terbesar, kemudian menukar elemen tersebut dengan elemen pada indeks `i`. Proses ini diulang sampai tidak ada anak yang lebih besar.

**8. Fungsi untuk Memasukkan Elemen:**

```c++
void insert(int p) {
  heapSize++;
  H[heapSize] = p;
  shiftUp(heapSize);
}
```

Fungsi `insert(p)` memasukkan elemen `p` ke dalam heap. `heapSize` ditambah, elemen baru dimasukkan ke indeks terakhir, dan kemudian dilakukan `shiftUp` untuk menjaga sifat heap.

**9. Fungsi untuk Mengambil Elemen Maksimum:**

```c++
int extractMax() {
  int result = H[0];
  H[0] = H[heapSize];
  heapSize--;
  shiftDown(0);
  return result;
}
```

Fungsi `extractMax()` mengembalikan dan menghapus elemen dengan nilai maksimum dari heap. Elemen maksimum ada pada indeks 0, sehingga disimpan di variabel `result`. Elemen terakhir kemudian dipindahkan ke indeks 0, `heapSize` dikurangi, dan dilakukan `shiftDown` untuk menjaga sifat heap.

**10. Fungsi untuk Mengubah Prioritas Elemen:**

```c++
void changePriority(int i, int p) {
  int oldp = H[i];
  H[i] = p;
  if (p > oldp) {
    shiftUp(i);
  } else {
    shiftDown(i);
  }
}
```

Fungsi `changePriority(i, p)` mengubah prioritas elemen pada indeks `i` menjadi nilai `p`. Pertama, nilai prioritas lama disimpan di variabel `oldp`. Kemudian, nilai prioritas baru disimpan di elemen `H[i]`. Selanjutnya, dilakukan pemeriksaan apakah nilai prioritas baru lebih besar atau sama dengan nilai prioritas lama. Jika lebih besar, dilakukan `shiftUp` untuk menaikkan elemen ke atas. Jika lebih kecil atau sama, dilakukan `shiftDown` untuk menurunkan elemen ke bawah. Hal ini dilakukan untuk menjaga sifat heap.

**11. Fungsi untuk Mendapatkan Elemen Maksimum:**

```c++
int getMax() {
  return H[0];
}
```

Fungsi `getMax()` mengembalikan nilai elemen maksimum dari heap. Elemen maksimum ada pada indeks 0, sehingga dikembalikan oleh fungsi ini.

**12. Fungsi untuk Menghapus Elemen:**

```c++
void remove(int i) {
  H[i] = getMax() + 1;
  shiftUp(i);
  extractMax();
}
```

Fungsi `remove(i)` menghapus elemen pada indeks `i` dari heap. Pertama, nilai elemen pada indeks `i` diubah menjadi nilai yang lebih besar dari nilai maksimum heap. Hal ini memastikan bahwa elemen tersebut akan menjadi elemen maksimum dan dihapus oleh `extractMax`. Kemudian, dilakukan `shiftUp` untuk menjaga sifat heap.

**13. Fungsi Utama (main):**

```c++
int main() {
  insert(45);
  insert(20);
  insert(14);
  insert(12);
  insert(31);
  insert(7);
  insert(11);
  insert(13);
  insert(7);

  cout << "Priority Queue : ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  cout << "Node with maximum priority : " << extractMax() << "\n";
  cout << "Priority queue after extracting maximum : ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  changePriority(2, 49);
  cout << "Priority queue after priority change : ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  remove(3);
  cout << "Priority queue after removing the element : ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << "\n";

  return 0;
}
```

Pada fungsi `main()`, dilakukan beberapa operasi pada heap:

* **Memasukkan Elemen:** Elemen-elemen dimasukkan ke dalam heap menggunakan fungsi `insert`.
* **Menampilkan Heap:** Heap ditampilkan menggunakan loop `for` yang mencetak isi array `H`.
* **Mengambil Elemen Maksimum:** Elemen maksimum dihapus dari heap dan nilainya ditampilkan menggunakan fungsi `extractMax`.
* **Mengubah Prioritas Elemen:** Prioritas elemen pada indeks 2 diubah menjadi 49 menggunakan fungsi `changePriority`.
* **Menghapus Elemen:** Elemen pada indeks 3 dihapus dari heap menggunakan fungsi `remove`.

**Kesimpulan:**

Kodingan di atas mengimplementasikan struktur data heap dan algoritma heap sort. Heap digunakan untuk menyimpan data dengan cara yang efisien, memungkinkan pengambilan elemen maksimum dengan cepat. Algoritma heap sort kemudian menggunakan heap untuk mengurutkan data.

## Unguided

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize++;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    if (heapSize < 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize--;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void displayHeap() {
    cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, value, index;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Extract Max\n";
        cout << "3. Get Max\n";
        cout << "4. Change Priority\n";
        cout << "5. Remove\n";
        cout << "6. Display Heap\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                value = extractMax();
                if (value != -1) {
                    cout << "Extracted max value: " << value << endl;
                }
                break;
            case 3:
                value = getMax();
                if (value != -1) {
                    cout << "Max value: " << value << endl;
                }
                break;
            case 4:
                cout << "Enter index and new priority: ";
                cin >> index >> value;
                if (index <= heapSize && index >= 0) {
                    changePriority(index, value);
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            case 5:
                cout << "Enter index to remove: ";
                cin >> index;
                if (index <= heapSize && index >= 0) {
                    remove(index);
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            case 6:
                displayHeap();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
```

### Output:

* **Menu Insert**

    ![image-2](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/3cd9f8bd-b17c-41f5-b9a2-caf9b3131e9a)

* **Menu Display Heap (Data Awal)**

    ![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/67b4fd9c-dab8-49cf-ad4a-37d8da303b82)

* **Menu Extract Max**

    ![image-1](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/b4a4db22-82ec-4b32-a04a-226f4181b20b)

* **Menu Get Max**

    ![image-3](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/50c550fa-5bc6-4fc3-abe3-2105abce69ec)

* **Menu Change Priority**

    ![image-4](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/478e58f1-1ff2-4b96-9b68-1690d2068fb2)

* **Menu Remove**

    ![image-5](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/09cdb90c-7395-4ad8-ac03-5c2a65b97528)

* **Menu Display Heap (Data Akhir)**

    ![image-6](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/97833371-c960-4412-932f-1c7d6048efda)

* **Menu Exit**

    ![image-7](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/e1e0d00a-61bf-4f58-ae4e-997323b0c0a4)

### Interpretasi

Kodingan di atas mengimplementasikan struktur data **Max Heap** dan menyediakan menu interaktif untuk melakukan operasi pada heap. Berikut interpretasinya:

**1. Menyertakan Header:**

Sama seperti kode sebelumnya, kode ini menyertakan header `<iostream>` untuk input/output standar dan `<algorithm>` untuk fungsi `swap`.

**2. Deklarasi Array dan Variabel:**

* `H`: Array dengan ukuran 50 untuk menyimpan elemen heap.
* `heapSize`: Variabel untuk menyimpan ukuran heap saat ini (dimulai dari -1).

**3. Fungsi-fungsi untuk Heap:**

Kode ini memiliki fungsi-fungsi yang sama persis dengan kode sebelumnya untuk:

* `parent(i)`: Mencari indeks parent dari sebuah elemen.
* `leftChild(i)`: Mencari indeks left child dari sebuah elemen.
* `rightChild(i)`: Mencari indeks right child dari sebuah elemen.
* `shiftUp(i)`: Menjaga sifat heap (nilai parent lebih besar sama dengan anak) setelah elemen pada indeks `i` diubah. Dilakukan dengan perulangan untuk menukar elemen ke atas.
* `shiftDown(i)`: Menjaga sifat heap setelah elemen pada indeks `i` diubah. Dilakukan dengan perulangan untuk mencari anak dengan nilai terbesar dan menukar elemen tersebut dengan elemen pada indeks `i`.
* `insert(p)`: Memasukkan elemen `p` ke dalam heap.
* `extractMax()`: Menghapus dan mengembalikan elemen dengan nilai maksimum dari heap.
* `changePriority(i, p)`: Mengubah prioritas elemen pada indeks `i` menjadi nilai `p`.
* `getMax()`: Mengembalikan elemen maksimum dari heap.
* `remove(i)`: Menghapus elemen pada indeks `i` dari heap.

**4. Fungsi Tambahan:**

* `displayHeap()`: Menampilkan isi dari heap dengan mencetak elemen-elemen array `H`.

**5. Fungsi Utama (main):**

* Deklarasi variabel `choice`, `value`, dan `index` untuk menyimpan pilihan pengguna, nilai yang akan dimasukkan, dan indeks elemen.
* Loop `while (true)` untuk menjalankan program secara terus menerus sampai pengguna memilih keluar (Exit).
    * Menampilkan menu dengan pilihan:
        * Insert (Memasukkan elemen)
        * Extract Max (Menghapus elemen maksimum)
        * Get Max (Mendapatkan elemen maksimum)
        * Change Priority (Mengubah prioritas elemen)
        * Remove (Menghapus elemen)
        * Display Heap (Menampilkan heap)
        * Exit (Keluar)
    * Membaca pilihan pengguna dan melakukan operasi sesuai pilihan tersebut menggunakan switch-case:
        * **case 1 (Insert):** Meminta nilai dari pengguna dan memasukkannya ke dalam heap menggunakan `insert`.
        * **case 2 (Extract Max):** Menghapus elemen maksimum dan menampilkannya menggunakan `extractMax`.
        * **case 3 (Get Max):** Mendapatkan elemen maksimum dan menampilkannya menggunakan `getMax`.
        * **case 4 (Change Priority):** Meminta indeks elemen dan nilai prioritas baru dari pengguna. Melakukan perubahan prioritas menggunakan `changePriority` jika indeks valid.
        * **case 5 (Remove):** Meminta indeks elemen dan menghapusnya dari heap menggunakan `remove` jika indeks valid.
        * **case 6 (Display Heap):** Menampilkan isi heap menggunakan `displayHeap`.
        * **case 7 (Exit):** Keluar dari program.
    * Pilihan selain 1-7 dianggap invalid dan akan menampilkan pesan kesalahan.

**Kesimpulan:**

Kodingan di atas memungkinkan pengguna untuk berinteraksi dengan heap secara mudah menggunakan menu. Pengguna dapat memasukkan elemen, menghapus elemen, mengubah prioritas elemen, dan melihat isi heap.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/bf8ad062-c701-4751-8946-075bb44f0d02)

## Kesimpulan

Priority queue berguna untuk mengatur elemen berdasarkan prioritasnya, dimana elemen berprioritas tinggi diambil lebih dulu. Heap merupakan struktur data yang efisien untuk merepresentasikan priority queue karena operasi insert, extract, dan change priority memiliki kompleksitas waktu O(logN).

Heap dapat dikategorikan menjadi max-heap dan min-heap, tergantung apakah nilai parent lebih besar atau lebih kecil dari anaknya. Sifat complete binary tree dan property order membuat nilai tertinggi atau terendah selalu berada di root. 

Beberapa cara untuk merealisasikan priority queue adalah menggunakan array, linked list, heap, atau binary search tree. Namun heap memberikan keunggulan dalam kompleksitas waktu operasinya. Priority queue bermanfaat untuk sistem real-time dan algoritma seperti Dijkstra dan A*. Sedangkan heap sort memanfaatkan property heap untuk mengurutkan elemen dengan kompleksitas O(nlogn).

## Referensi

[1] GeeksforGeeks, "Priority Queue - Set 1: Introduction", 2024.

[2] Programiz, "Heap Data Structure", [Online]. Tersedia: https://www.programiz.com/dsa/heap-data-structure, [Diakses 13 Mei 2024].

[3] Wikipedia, "Heap (data structure)", 2023.

[4] J. Skiena, "The Algorithm Design Manual", Springer, 2020.

[5] I. Kalaji, "Implementing Heap Data Structure in C++", 2022.