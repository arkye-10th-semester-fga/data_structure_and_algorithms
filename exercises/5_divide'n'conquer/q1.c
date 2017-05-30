#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int * declareArray(int n){
    int * x;
    x = malloc(n * (sizeof(int)));
    return x;
}

int inputSize(){
    int a=0, b=0, x;
    FILE * fileA = fopen( "./examples/q1/inputA.txt" , "r");
    FILE * fileB = fopen( "./examples/q1/inputB.txt" , "r");

    if(fileA == NULL || fileB == NULL){
        printf("\nERROR: FILE_FAILED_TO_OPEN");
        exit(0);
    }

    while(!feof(fileA)){
        fscanf(fileA, "%d ", &x);
        a++;
    }

    while(!feof(fileB)){
        fscanf(fileB, "%d ", &x);
        b++;
    }

    if(a == 0 || b == 0 || a!=b){
        printf("\nERROR: FILE_INPUT_SIZE_INVALID");
        exit(0);
    }
    fclose(fileA);
    fclose(fileB);

    return a;
}


void scanInput(int * a, int * b, int n){
    int i;

    FILE * fileA = fopen( "./examples/q1/inputA.txt" , "r");
    FILE * fileB = fopen( "./examples/q1/inputB.txt" , "r");

    if(fileA == NULL || fileB == NULL){
        printf("\nERROR: FILE_FAILED_TO_OPEN");
        exit(0);
    }

    for(i=0; i<n; i++){
        fscanf(fileA, "%d ", &a[i]);
        fscanf(fileB, "%d ", &b[i]);
    }

    fclose(fileA);
    fclose(fileB);
}

void printArray(int * x, int n){
    int i;
    for (i=0; i<n; i++) printf("%d ", x[i]);
    printf("\n");
}

int median(int n, int ai, int bi, int * A, int * B){
    int k = ceil(n/2.0);
    int i;

    if(n==1){
        return min(A[ai], B[bi]);
    }
    if (A[ai+k] < B[bi + k]){
        if(n%2==0 && n!=2){
            return median(k+1, ai+k-1, bi, A, B);
        }else if(n/2!=k){
            return median(k, ai+k-1, bi, A, B);
        }else{
            return median(k, ai+k, bi, A, B);
        }
    }else{
        if(n%2==0 && n!=2){
            return median(k+1, ai, bi+k-1, A, B);
        }else if(n/2!=k){
            return median(k, ai, bi+k-1, A, B);
        }else{
            return median(k, ai, bi+k, A, B);
        }
    }
}

int main(){
    int size = inputSize();

    int * A = declareArray(size);
    int * B = declareArray(size);
    scanInput(A, B, size);

    int answer = median(size, 0, 0, A, B);
    printf("MEDIAN: %d", answer);
    return 0;
}


