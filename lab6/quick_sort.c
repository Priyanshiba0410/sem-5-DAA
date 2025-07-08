#include <stdio.h>
#include <time.h>

#define N 100000

void swap(int *k, int *l) {
    int temp = *k;
    *k = *l;
    *l = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); 
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);  
        quickSort(arr, p + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    if (readArrayFromFile("C:/Users/priya/OneDrive/Desktop/DAA/array/best_case_100000.txt", arr, N)) {
        printf("Original array:\n");
        printArray(arr, N);

        int low = 0, high = N - 1;

        start = clock();
        quickSort(arr, low, high);
        end = clock();

        printf("Sorted array:\n");
        printArray(arr, N);

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Quick Sort: %.6f seconds\n", time_taken);
    }

    return 0;
}
