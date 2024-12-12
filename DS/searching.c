#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int low, int high, int key);
void bubbleSort(int arr[], int n);

int main() // Changed void to int for main
{
    int arr[100], n, choice, key, result, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Select any search method:\n");
    printf("1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    if (choice == 1) {
        result = linearSearch(arr, n, key);
    } else if (choice == 2) {
        bubbleSort(arr, n);
        printf("Array sorted for Binary Search.\n");
        result = binarySearch(arr, 0, n - 1, key);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0; // Added return statement for main
}

// Linear Search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Element found
    }
    return -1; // Means element not found
}

// Binary Search function
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid
        if (arr[mid] == key)
            return mid; // Element found
        if (arr[mid] < key)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    return -1; // Element not found
}

// Bubble Sort function to sort the array for Binary Search
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}