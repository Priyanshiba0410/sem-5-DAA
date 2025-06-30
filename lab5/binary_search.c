#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 100000


int binary_search(int arr[],int high, int low,int element){
    if(low>high){
        return 0;
    }
    int mid =(low+high)/2;
    if(element>arr[mid]){
        return binary_search(arr,mid+1,high,element);

    }else if(element<arr[mid]){
        return binary_search(arr,low,mid-1,element);
    }
    else{
        return 1;
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
        binary_search(arr,0,N,55);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken by binary Search:%f seconds\n",time_taken);
    }
    return 0;
}