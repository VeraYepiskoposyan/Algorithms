int insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int swapIdx = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                swapIdx = j;
            }
            else
                break;
        }
        if (swapIdx != i) {
            int temp = arr[i];
            for (int k = i; k > swapIdx; k--) {
                arr[k] = arr[k - 1];
            }
            arr[swapIdx] = temp;
        }
    }
    return 0;
}
