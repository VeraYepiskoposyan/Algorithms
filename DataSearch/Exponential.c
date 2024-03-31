#include <stdio.h>

static int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}


int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0; 

    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;


    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
}

int testExponentialSearch() {
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;
    int index = exponentialSearch(arr, n, target);
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found in the array\n", target);
    return 0;
}
