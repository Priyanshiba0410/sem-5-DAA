#include <stdio.h>
#include <time.h>

#define N 100000

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

    if (readArrayFromFile("C:/Users/priya/OneDrive/Desktop/DAA/array/avg_case_100000.txt", arr, N)) {
        printf("Original array:\n");
        printArray(arr, N);

        int low = 0, high = N - 1;

        start = clock();
        mergeSort(arr, low, high);
        end = clock();

        printf("Sorted array:\n");
        printArray(arr, N);

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Merge Sort: %.6f seconds\n", time_taken);
    }

    return 0;
}
