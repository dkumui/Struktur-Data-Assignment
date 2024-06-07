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