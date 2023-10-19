#include <iostream>
using namespace std;

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int arr[], int n, int exp) {
    const int MAX = 10; // Radix is 10 (decimal system)

    int output[n];
    int count[MAX] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (int i = 1; i < MAX; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] contains
    // sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// radix sort algorithm
void radixSort(int arr[], int n) {
    // find the maximum number to know the number of digits
    int max = findMax(arr, n);

    // do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// function to print the final array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    printArray(arr, n);
}
