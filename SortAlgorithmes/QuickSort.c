static int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

static void quickSortRange(int* arr, int low, int high)
{
    if (low < high) {

        int partitionIndex = partition(arr, low, high);

        quickSortRange(arr, low, partitionIndex - 1);
        quickSortRange(arr, partitionIndex + 1, high);
    }
}

int quickSort(int* arr, int n)
{
    quickSortRange(arr, 0, n - 1);
    return 0;
}