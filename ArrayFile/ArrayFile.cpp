 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

// ---------- Ввід ----------
void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// ---------- ЗАДАЧА 1 ----------
void task1() {
    int n;
    cout << "n = ";
    cin >> n;

    int A[100], B[100];

    cout << "Enter A:\n";
    inputArray(A, n);

    cout << "Enter B:\n";
    inputArray(B, n);

    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            A[i] = B[i];
        }
    }

    cout << "Result:\n";
    printArray(A, n);
}
// ---------- ЗАДАЧА 2 ----------
void task2() {
    int n;
    cout << "n = ";
    cin >> n;

    int A[100];
    inputArray(A, n);

    int T1, T2;
    cout << "Enter T1 and T2: ";
    cin >> T1 >> T2;

    int posT2 = -1;

    for (int i = 0; i < n; i++) {
        if (A[i] == T2) {
            posT2 = i;
            break;
        }
    }

    if (posT2 == -1) {
        cout << "T2 not found\n";
        return;
    }

    int minVal = 1e9;
    int index = -1;

    for (int i = posT2 + 1; i < n; i++) {
        if (A[i] > T1 && A[i] < minVal) {
            minVal = A[i];
            index = i;
        }
    }

    if (index == -1)
        cout << "No suitable element\n";
    else
        cout << "Index: " << index << endl;
}
// ---------- ЗАДАЧА 3 ----------
void task3() {
    int n;
    cout << "n = ";
    cin >> n;

    int A[100];
    inputArray(A, n);

    int maxUnique = -1e9;
    bool found = false;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) count++;
        }

        if (count == 1 && A[i] > maxUnique) {
            maxUnique = A[i];
            found = true;
        }
    }

    if (found)
        cout << "Max unique: " << maxUnique << endl;
    else
        cout << "No unique elements\n";
}
// ---------- МЕНЮ ----------
int main() {
    int choice;

    do {
        cout << "\nMENU:\n";
        cout << "1 - Task 1\n";
        cout << "2 - Task 2\n";
        cout << "3 - Task 3\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            cout << "Exit\n";
            break;
        default:
            cout << "Wrong choice\n";
        }

    } while (choice != 0);

    return 0;
}