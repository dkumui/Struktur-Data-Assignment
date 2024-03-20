#include <iostream>
#include <string>
using namespace std;

//Class biasa yang belum publik akses
class Employee {
    string nama;
    int umur;
    string email;
};

//Class yang sudah menjadi publik akses
class Employee2 {
public:
    string nama;
    int umur;
    string email;
};

struct Employeee {
    string nama;
    int umur;
    string email;
};

int main() {
    Employeee emp1;
    Employee2 emp2;
    
    emp1.nama = "Dundun";
    emp1.umur = 19;
    emp1.email = "dundunat@gmail.com";
    cout << "==== Employee 1 ===="
        << "\nNama: " << emp1.nama
        << "\nUmur: " << emp1.umur << " tahun"
        << "\nEmail: " << emp1.email << endl;

    emp2.nama = "Kumui";
    emp2.umur = 18;
    emp2.email = "kumuidd@gmail.com";
    cout << "==== Employee 2 ===="
        << "\nNama: " << emp2.nama
        << "\nUmur: " << emp2.umur << " tahun"
        << "\nEmail: " << emp2.email << endl;

    return 0;
}