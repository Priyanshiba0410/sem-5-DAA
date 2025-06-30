#include<stdio.h>
#include<time.h>
#define N 100000

void insertionSort(int arr[] , int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}   

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
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

    if (readArrayFromFile("C:/Users/priya/OneDrive/Desktop/DAA/array/average_case_10000.txt", arr, N)) {
        printf("Original array:\n");
        printArray(arr, N);

        start = clock();
        insertionSort(arr, N);
        end = clock();

        printf("Sorted array:\n");
        printArray(arr, N);

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Bubble Sort: %.6f seconds\n", time_taken);
    }

    return 0;
}