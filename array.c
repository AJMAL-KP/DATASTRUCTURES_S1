#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int size = 0;

void insert(int value) {
    if (size < MAX) {
        arr[size] = value;
        size++;
    } else {
        cout << "Array is full.\n";
    }
}

void remove(int value) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Value not found.\n";
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void sortArray() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << "Found at position " << i << ".\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void display() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Sort\n4. Search\n5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            insert(value);
        } else if (choice == 2) {
            cout << "Enter value to delete: ";
            cin >> value;
            remove(value);
        } else if (choice == 3) {
            sortArray();
        } else if (choice == 4) {
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
        } else if (choice == 5) {
            display();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
