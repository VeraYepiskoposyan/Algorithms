#include <stdio.h>


int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int testLinearSEarch()
{
    int arr[] = { 12, 45, 67, 89, 34, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 34;

    int index = linearSearch(arr, n, key);
    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    }
    else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}