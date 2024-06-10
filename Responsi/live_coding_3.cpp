// 3. BUBBLE SORT

#include <iostream>

using namespace std;

void bubble_sort(int arr[], int length) {
    bool not_sorted = true;
    int j = 0;
    double tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(){
    int arr[5] = {5, 1, 4, 2, 8};
    int length = 5;

    cout << "Sebelum diurutkan: " << endl;
    print_array(arr, length);

    cout << "\nSetelah diurutkan: " << endl;
    bubble_sort(arr, length);
    print_array(arr, length);
}