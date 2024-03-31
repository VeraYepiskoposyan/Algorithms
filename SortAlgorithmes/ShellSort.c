int shellSort(int* arr, int n) {
    int step = n / 2;
    while (step > 0) {
        for (int i = step; i < n; i++) {
            for (int j = i; (j - step) >= 0; j -= step)
                if (arr[j] < arr[j - step]) {
                    int temp = arr[j];
                    arr[j] = arr[j - step];
                    arr[j - step] = temp;
                }
                else
                    break;
        }
        step /= 2;
    }
    return 0;
}