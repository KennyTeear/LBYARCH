#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// asm
extern float DotProduct(float* A, float* B, int n);

// Function declarations
float dotProductC(const float* A, const float* B, int n);
void initializeVectors(float* vecA, float* vecB, int n);

int main() {
    int n = 1 << 29; // 2^20 vector size
    float* A, * B;
    float sdotC = 0.0f, sdotASM = 0.0f;

    A = (float*)malloc(n * sizeof(float));
    B = (float*)malloc(n * sizeof(float));

    initializeVectors(A, B, n);

    const int iterations = 30;
    double totalCpuTimeC = 0, totalCpuTimeASM = 0;
    int resultsMatch = 1;

    for (int i = 0; i < iterations; i++) {
        clock_t startC = clock();
        sdotC = dotProductC(A, B, n);
        clock_t endC = clock();
        totalCpuTimeC += ((double)(endC - startC)) / CLOCKS_PER_SEC;

        clock_t startASM = clock();
        sdotASM = DotProduct(A, B, n);
        clock_t endASM = clock();
        totalCpuTimeASM += ((double)(endASM - startASM)) / CLOCKS_PER_SEC;

        if (sdotC != sdotASM) {
            resultsMatch = 0;
            printf("Discrepancy found at iteration %d: C = %f, ASM = %f\n", i + 1, sdotC, sdotASM);
            break;
        }
    }

    double avgCpuTimeC = totalCpuTimeC / iterations;
    double avgCpuTimeASM = totalCpuTimeASM / iterations;

    printf("Dot Product (C): %f\n", sdotC);
    printf("Dot Product (ASM): %f\n", sdotASM);
    printf("Average Time taken (C): %f seconds\n", avgCpuTimeC);
    printf("Average Time taken (ASM): %f seconds\n", avgCpuTimeASM);

    if (resultsMatch) {
        printf("All iterations produced matching results. The x86-64 kernel output is correct.\n");
    }
    else {
        printf("There were discrepancies in the output.\n");
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
