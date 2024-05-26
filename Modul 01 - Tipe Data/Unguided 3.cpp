#include <iostream>
#include <map>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi map
    map<int, int> nilai;
    nilai[0] = 60;
    nilai[1] = 25;
    nilai[2] = 87;
    nilai[3] = 12;
    nilai[4] = 56;

    // Mencetak nilai dari map
    for (const auto& pair : nilai) {
        cout << "Isi Array ke-" << pair.first + 1 << " : " << pair.second << endl;
    }

    return 0;
}