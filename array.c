#include <stdio.h>

#define MAX 100
int arr[MAX];
int size = 0;

void insert(int value) {
    if (size < MAX) {
        arr[size] = value;
        size++;
    } else {
        printf("Array is full.\n");
    }
}

void removeElement(int value) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Value not found.\n");
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
            printf("Found at position %d.\n", i);
            return;
        }
    }
    printf("Not found.\n");
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Sort\n4. Search\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                removeElement(value);
                break;
            case 3:
                sortArray();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
