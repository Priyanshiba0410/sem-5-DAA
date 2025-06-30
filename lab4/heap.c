#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}

int heap_sort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);

        for (int i = n - 1; i > 0; i--) {
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            heapify(arr, i, 0);
        }
    }
    
}

void printArray(int arr[],int size){
    for(int i = 0;i < size;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

int readArrayFromFile(const char *filename , int arr[], int n){
    FILE *f = fopen(filename,"r");
    if(!f){
        printf("cannot open file %s\n",filename);
        return 0;
    }
    for(int i = 0;i<n;i++){
        fscanf(f , "%d",&arr[i]);
    }
    fclose(f);
    return 1;
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    if (readArrayFromFile("C:/Users/priya/OneDrive/Desktop/DAA/array/best_case_10000.txt", arr, N)) {
        start = clock();
        heap_sort(arr, N);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken by heap Sort: %.3f seconds\n", time_taken);

    }

    return 0;
}