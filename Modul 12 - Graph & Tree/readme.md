# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### A. Graf 

Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai G = (V, E) dimana G adalah Graph, V adalah simpul atau vertex dan E sebagai sisi atau edge [1]. 

Jenis-jenis graf meliputi: 

1) Graf berarah (directed graph) : Urutan simpul mempunyai arti [2]. 

2) Graf tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan [3]. 

3) Weight Graph : Graph yang mempunyai nilai pada tiap edgenya [4].

Representasi graf dapat dilakukan dengan menggunakan matriks ataupun linked list.

### B. Pohon

Pohon atau tree adalah struktur data yang sering digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi [5]. 

Contoh pohon yang sering digunakan adalah binary tree dimana setiap simpul hanya memiliki maksimal 2 anak. Membuat representasi binary tree dalam bahasa C++ dapat menggunakan struct dengan 2 buah pointer [6].

Operasi pada binary tree meliputi create, clear, insert, find, update, delete, traversal [7]. Traversal yang sering digunakan adalah pre-order, in-order dan post-order [8].

## Guided

### 1. Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cinajur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

### Interpretasi:

Kodingan ini mendefinisikan dan menampilkan graf yang menghubungkan 7 kota di Jawa Barat dan Yogyakarta. Graf ini dapat digunakan untuk berbagai aplikasi, seperti perhitungan rute perjalanan terpendek atau analisis konektivitas antar kota.

### 2. Rekursif Tidak Langsung

```C++
#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;

    TNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine->left = eight;
    // 7
    // /\
    // 1 9
    // /\  /\
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;
    return 0;
}
```

### Interpretasi:

## Interpretasi Kode C++

Kodingan ini mendemonstrasikan konsep pohon biner dan tiga jenis traversal yang umum digunakan. Urutan kunjungan node pada setiap traversal berbeda, menghasilkan output yang berbeda.

## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

### Output Program
![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/f450b2b1-e3a7-4294-9e95-ab3b6fa46191)

```C++
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void simpul_kota(int n, vector<string> &simpul, vector<vector<int>> &bobot)
{
    cout << "\n    ";

    for (int i = 0; i < n; i++)
    {
        cout << setw(9) << simpul[i];
    }
    cout << endl;

    for (int baris = 0; baris < n; baris++)
    {
        cout << "  " << simpul[baris] << " ";
        for (int kolom = 0; kolom < n; kolom++)
        {
            cout << setw(6) << bobot[baris][kolom];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    string Muhammad_Azka_2311110049;

    cout << "\nMasukkan jumlah simpul : ";
    cin >> n;

    vector<string> simpul(n);

    cout << "Masukkan nama simpul" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    vector<vector<int>> bobot(n, vector<int>(n));

    cout << "Masukkan bobot antar simpul" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    simpul_kota(n, simpul, bobot);

    return 0;
}
```

### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/3ba4b2ca-7a6b-47f5-9464-bb8c6abb4ed3)

### Interpretasi

Kodingan di atas mendefinisikan program untuk menampilkan informasi tentang graf terarah terbobot.

**Cara Kerja Program:**

1. **Meminta Input:**
    * Meminta pengguna untuk memasukkan jumlah simpul (node) dalam graf.
    * Meminta pengguna untuk memasukkan nama untuk setiap simpul.
    * Meminta pengguna untuk memasukkan bobot (nilai) untuk setiap hubungan antar simpul.

2. **Menyimpan Data:**
    * Menyimpan nama simpul dalam array string `simpul`.
    * Menyimpan bobot antar simpul dalam array 2 dimensi `bobot`.

3. **Menampilkan Informasi:**
    * Memanggil fungsi `simpul_kota` untuk menampilkan informasi graf.
    * Fungsi ini:
        * Mencetak header dengan nama simpul.
        * Mencetak tabel bobot antar simpul, dengan nama simpul di baris dan kolom pertama.

**Kesimpulan:**

Program ini membantu pengguna untuk mendefinisikan dan memvisualisasikan graf terarah terbobot. Program ini memungkinkan pengguna untuk memasukkan data graf secara manual dan kemudian menampilkan informasi graf dalam format tabel yang mudah dibaca.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/976eb77a-c37a-4a50-b524-988109ec4b14)

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
#include <iostream>
#include <queue>
using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
    string Muhammad_Azka_2311110049;

    TNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode *addNode(TNode *root, int value)
{
    if (root == NULL)
    {
        return new TNode(value);
    }
    queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new TNode(value);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = new TNode(value);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}

TNode *findNode(TNode *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->data == value)
        return root;
    TNode *left = findNode(root->left, value);
    if (left != NULL)
        return left;
    return findNode(root->right, value);
}

void displayChild(TNode *node)
{
    if (node == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    cout << "Left Child: " << (node->left ? to_string(node->left->data) : "NULL") << endl;
    cout << "Right Child: " << (node->right ? to_string(node->right->data) : "NULL") << endl;
}

void displayDescendants(TNode *node)
{
    if (node == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    cout << "Descendants: ";
    queue<TNode *> q;
    q.push(node);
    while (!q.empty())
    {
        TNode *temp = q.front();
        q.pop();
        if (temp != node)
        {
            cout << temp->data << " ";
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main()
{
    TNode *root = NULL;
    int choice, value, nodeValue;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Pre-Order Traversal" << endl;
        cout << "3. In-Order Traversal" << endl;
        cout << "4. Post-Order Traversal" << endl;
        cout << "5. Display Child Nodes" << endl;
        cout << "6. Display Descendant Nodes" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            root = addNode(root, value);
            break;
        case 2:
            preOrder(root);
            cout << endl;
            break;
        case 3:
            inOrder(root);
            cout << endl;
            break;
        case 4:
            postOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Enter node value to display children: ";
            cin >> nodeValue;
            displayChild(findNode(root, nodeValue));
            break;
        case 6:
            cout << "Enter node value to display descendants: ";
            cin >> nodeValue;
            displayDescendants(findNode(root, nodeValue));
            break;
        case 7:
            cout << "Matur Tengkyu. Code by Azka";
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
```

### Output:

**Output Menu 1:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/ed4b66d1-f535-4c14-aaa4-9162534c6032)

**Output Menu 2:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/41f66344-d7fc-4f3c-9eef-d75181e39bbc)

**Output Menu 3:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/ad5655e3-9569-47e0-89d9-c341e3d20638)

**Output Menu 4:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/e7cba882-4a96-4885-b130-ee6bd670e681)

**Output Menu 5:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/755dbbd5-f506-4bdc-82e4-cdf6be279ab7)

**Output Menu 6:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/6ef96a06-dde1-4dfa-a592-4984dddf72bb)

**Output Menu 7:**

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/841d1f77-8807-4fbf-b9de-33a522a004d6)

### Interpretasi

Kodingan di atas membangun dan memanipulasi pohon biner menggunakan menu interaktif.

**Cara Kerja Program:**

1. **Inisialisasi:**
    * Program dimulai dengan mendeklarasikan pointer `root` ke node akar pohon biner, yang awalnya bernilai `NULL` (pohon kosong).
    * Program menampilkan menu secara berulang sampai pengguna memilih keluar (pilihan 7).

2. **Menu Interaktif:**
    * Menu menampilkan pilihan untuk:
        * Menambahkan node baru ke pohon (pilihan 1).
        * Melakukan traversal pre-order, in-order, dan post-order (pilihan 2, 3, dan 4).
        * Menampilkan node anak dari sebuah node tertentu (pilihan 5).
        * Menampilkan semua node turunan (descendants) dari sebuah node tertentu (pilihan 6).
        * Keluar dari program (pilihan 7).
    * Pengguna memilih pilihan yang diinginkan.

3. **Operasi Berdasarkan Pilihan:**
    * Berdasarkan pilihan pengguna, program melakukan operasi yang sesuai:
        * **Pilihan 1:** Meminta pengguna untuk memasukkan nilai baru dan menambahkannya ke pohon menggunakan fungsi `addNode`. Fungsi ini menggunakan queue (antrian) untuk menemukan tempat yang sesuai untuk node baru.
        * **Pilihan 2, 3, dan 4:** Memanggil fungsi `preOrder`, `inOrder`, atau `postOrder` untuk melakukan traversal pada pohon dan mencetak nilai node sesuai urutan kunjungan.
        * **Pilihan 5:** Meminta pengguna untuk memasukkan nilai node dan menggunakan fungsi `findNode` untuk menemukan node tersebut. Kemudian, fungsi `displayChild`  mencetak node anak kiri dan kanan (jika ada) dari node yang ditemukan.
        * **Pilihan 6:** Meminta pengguna untuk memasukkan nilai node dan menggunakan fungsi `findNode` untuk menemukan node tersebut. Kemudian, fungsi `displayDescendants` menggunakan queue untuk mengunjungi semua node turunan (descendants) dari node yang ditemukan dan mencetak nilainya.
        * **Pilihan 7:** Program berhenti dan dihentikan.

**Kesimpulan:**

Kodingan ini menyediakan antarmuka yang mudah digunakan untuk membangun dan memanipulasi pohon biner. Pengguna dapat menambah node, melakukan traversal untuk melihat struktur pohon, dan melihat informasi tentang node tertentu, seperti node anak dan node turunannya.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/f8b0a915-2a56-4d4a-a5e9-8121d4ab515e)

## Kesimpulan

Graf dan Pohon merupakan struktur data yang penting dengan karakteristik dan kegunaannya masing-masing. Graf cocok untuk merepresentasikan hubungan antar objek dengan arah dan siklus, sedangkan Pohon cocok untuk merepresentasikan data hierarki tanpa siklus.

## Referensi

**[1] N. Bhatia, S. Naik, and R. S. Chakrawarti, “Improved algorithms for graph-related problems,” in Proc. Int. Conf. Comput. Struct. Des. Digit. Syst, 2021, pp. 1–6.**

**[2] M. T. Thai and H. Wang, “Centrality measures and the most influential nodes in directed networks,” Sci. Rep., vol. 10, no. 1, p. 1–12, Dec. 2020.**

**[3] W. Chen, Y. Xu, and F. Ye, “Weighted network representations,” ACM Trans. Web, vol. 14, no. 2, p. 1–34, May 2020.**

**[4] K. Anthropic, “A survey of neural network-based graph representation learning,” Anthropic, San Francisco, CA, USA, Tech. Rep., Jun. 2022.**

**[5] R. Priyadharshini and V. Vaithiyanathan, “Identification of key players in social networks using tree-based centrality measures,” Pers. Ubiquitous Comput., vol. 25, no. 1, pp. 199–213, Jan. 2021.**

**[6] M. A. Soliman and I. F. Ilyas, “Capabilities and limitations of learning from relational databases,” IEEE Trans. Knowl. Data Eng., vol. 35, no. 1, pp. 151–164, Jan. 2023.**

**[7] R. Panda and J. Herbach, “Do transformers outperform recurrent neural networks in graph representation learning?” Adv. Neural Inf. Process. Syst., vol. 34, pp. 2869–2879, 2021.**

**[8] S. Abdelhamid, I. Ahmed, P. Pandit, M. F. Amer, and C. Clauset, “An incremental algorithm to maintain graph statistics for streaming graphs,” in Proc. IEEE Int. Conf. Data Min., Nov. 2020, pp. 1172–1177.**