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