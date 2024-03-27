#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// asm
extern float DotProduct(float* A, float* B, int n);

// Function declarations
float dotProductC(const float* A, const float* B, int n);
void initializeVectors(float* vecA, float* vecB, int n);

int main() {
    int n = 1 << 30; //  2^20 vector size
    float* A, * B, sdotC, sdotASM;

    A = (float*)malloc(n * sizeof(float));
    B = (float*)malloc(n * sizeof(float));

    initializeVectors(A, B, n);

    clock_t startC = clock();
    sdotC = dotProductC(A, B, n);
    clock_t endC = clock();
    double cpuTimeC = ((double)(endC - startC)) / CLOCKS_PER_SEC;

    printf("Dot Product (C): %f\n", sdotC);
    printf("Time taken (C): %f seconds\n", cpuTimeC);

    clock_t startASM = clock();
    sdotASM = DotProduct(A, B, n);
    clock_t endASM = clock();
    double cpuTimeASM = ((double)(endASM - startASM)) / CLOCKS_PER_SEC;

    printf("Dot Product (ASM): %f\n", sdotASM);
    printf("Time taken (ASM): %f seconds\n", cpuTimeASM);

    if (sdotC == sdotASM) {
        printf("The x86-64 kernel output is correct\n");
    }
    else {
        printf("The x86-64 kernel output is wrong\n");
    }

    free(A);
    free(B);

    return 0;
}

void initializeVectors(float* vecA, float* vecB, int n) {
    for (int i = 0; i < n; i++) {
        vecA[i] = 0.5f;
        vecB[i] = 0.25f;
    }
}

float dotProductC(const float* A, const float* B, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += A[i] * B[i];
    }
    return sum;
}