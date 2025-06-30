#include<stdio.h>
#include<time.h>

#define N 1000

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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

    if (readArrayFromFile("C:/Users/priya/OneDrive/Desktop/DAA/array/best_case_100.txt", arr, N)) {
        printf("Original array:\n");
        printArray(arr, N);

        start = clock();
        selectionSort(arr, N);
        end = clock();

        printf("Sorted array:\n");
        printArray(arr, N);

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Selection Sort: %.6f seconds\n", time_taken);
    }

    return 0;
}