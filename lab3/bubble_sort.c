#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100
 void bubble_sort(){

 }
 void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);

    }
    printf("\n");
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
        bubble_sort();
        end = clock();
    }
}