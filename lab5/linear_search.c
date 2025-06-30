#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 100000

int linear_search(int arr[],int n,int element){
    for(int i;i<n;i++){
        if(element=arr[i]){
            return 1;
        }
    }
}
int readArrayFromFile(const char *filename,int arr[],int n){
    FILE *f = fopen(filename,"r");
    if(!f){
        printf("cannot open file %s\n",filename);
        return 0;
    }
    for(int i=0;i<n;i++){
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    return 1;
}
int main(){
    int arr[N];
    clock_t start,end;
    double time_taken;

    if(readArrayFromFile("C:/Users/priya/OneDrive/Desktop/DAA/array/avg_case_100.txt",arr,N)){
        start = clock();
        linear_search(arr,N,55);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken by linear Search:%f seconds\n",time_taken);
    }
    return 0;
}