static void insertionSortByPlace(int* arr, int n, int place) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((arr[j] / place) % 10) > ((key / place) % 10)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int radixSort(int* arr, int n) {

    int maxElement = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxElement)
            maxElement = arr[i];

    for (int place = 1; maxElement / place > 0; place *= 10)
        insertionSortByPlace(arr, n, place);

    return 0;
}