#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int len(FILE* f, int* error) {
double c;
int len = 0;
while (fscanf(f, "%lf", &c) == 1) {
len++;
}
if (len == 0) {
    *error = -1;
}
if(!feof(f)) {
    *error = -2;
}
rewind(f);
return len;
}

void read(FILE* f, int len, double* arr) {
    for (int i = 0; i < len; i++) {
        fscanf(f, "%lf", &arr[i]);
    }
}


void sorting(double* arr, int len) {
    double temp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int function(double* A, double* B, int M, int N) {
    int minLen;
    if (M <= N) {
        minLen = N;
    }
    else {
        minLen = M;
    }

    for(int i = 0; i < (minLen - 1); i++) {                                                                            
        if (fabs(A[i] - B[i]) <= fabs(A[i+1] - B[i+1])) {
          return 1;
        }
        return 0;
    }
}

int main(void){
int error, check;
double *A, *B;
double M, N;
error = 0;
FILE* ina, *inb, *out;

ina = fopen("ina.txt", "r");
inb = fopen("inb.txt", "r");
out = fopen("output.txt", "w");

if (ina == NULL) {
    printf("Couldn't open the ina.txt\n");
    return -1;
}
if (inb == NULL) {
    printf("Couldn't open the inb.txt\n");
    fclose(ina);
    return -1;
}
if (out == NULL) {
    printf("Couldn't open the output.txt\n");
    fclose(ina);
    fclose(inb);
    return -1;
}

M = len(ina, &error);
if (error == -1) {
    printf("The ina.txt is empty\n");
    fclose(ina);
    fclose(inb);
    fclose(out);
    return -1;
}
if (error == -2) {
    printf("There are other symbols besides numbers in ina.txt");
    fclose(ina);
    fclose(inb);
    fclose(out);
    return -1;
}
N = len(inb, &error);
if (error == -1) {
    printf("The inb.txt is empty\n");
    fclose(ina);
    fclose(inb);
    fclose(out);
    return -1;
}
if (error == -2) {
    printf("There are other symbols besides numbers in inb.txt");
    fclose(ina);
    fclose(inb);
    fclose(out);
    return -1;
}
A = (double*)malloc(M*sizeof(double));
if (A == NULL) {
    printf("Can't allocate memory for ina.txt\n");
    fclose(ina);
    fclose(inb);
    fclose(out);
    return -1;
}
 B = (double*)malloc(N*sizeof(double));
 if (B == NULL) {
    printf("Can't allocate memory for inb.txt\n");
    fclose(ina);
    fclose(inb);
    fclose(out);
    free(A);
    return -1;
}
read(ina, M, A);
read(inb, N, B);
sorting(A, M);
sorting(B, N);
check = function(A, B, M, N);
if (check == 0) {
    fprintf(out, "NO");
}
else if (check == 1) {
    fprintf(out, "YES");
}
fclose(ina);
fclose(inb);
fclose(out);
free(A);
free(B);
return 0;
}