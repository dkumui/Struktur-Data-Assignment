#include <iostream>
using namespace std;

int factorialHelper(int n, int result);

int factorialStart(int n) {
    if (n == 0) {
        return 1;
    }
    return factorialHelper(n, 1);
}

int factorialHelper(int n, int result) {
    if (n == 1) {
        return result;
    }
    return factorialStart(n - 1) * n;
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorialStart(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}