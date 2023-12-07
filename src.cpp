#include <iostream>
#include <cstdlib> // Include this header for rand() function
#include <ctime>   // Include this header for time() function
#include <math.h>

#define FREQ 16
#define MAX 4096;

struct array
{
    // A, B_Array = basic Array, C_Array = Sum Array, T_Array = Tmp Array
    char A_Array[FREQ-1], B_Array[FREQ-1], C_Array[FREQ-1], T_Array[FREQ];
    // Normalization Array
    char N_Array[FREQ];
};

void Sum(char* SUM_ARRAY, char* F_OPERAND_ARRAY, char* S_OPERAND_ARRAY) {
    for (int i = 0; i < FREQ - 1; ++i) {
        SUM_ARRAY[i] = S_OPERAND_ARRAY[i] + F_OPERAND_ARRAY[i];
    }
}

void Normalization(char* SUM_ARRAY, char* TMP_ARRAY, char* END_ARRAY) {
    array A;
    int tmp[FREQ - 1], Selection_Index;
    for (int i = 0; i < FREQ - 1; ++i) {
        if (A.C_Array[i] >= 10) {
            Selection_Index = A.C_Array[i] * 0.1;
            tmp[i] = std::floor(Selection_Index);
        }
    }
    for (int i = 0; i < FREQ - 1; ++i) {
        END_ARRAY[i] = SUM_ARRAY[i] + tmp[i];
    }
}

void Array_Print(char* Array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << Array[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Assignment_Array(char* ArrayName, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        ArrayName[i] = rand() % 10 + 48;
    }
}

int main() {
    array A;

    Assignment_Array(A.A_Array, FREQ - 1);
    Assignment_Array(A.B_Array, FREQ - 1);

    Array_Print(A.A_Array, FREQ - 1);
    std::cout << std::endl;
    Array_Print(A.B_Array, FREQ - 1);
    std::cout << std::endl;

    Sum(A.C_Array, A.A_Array, A.B_Array);
    Array_Print(A.C_Array, FREQ - 1);
    std::cout << std::endl;

    Normalization(A.C_Array, A.T_Array, A.N_Array);
    Array_Print(A.N_Array, FREQ - 1);
    std::cout << std::endl;

    return 0;
}

/*
#include <iostream>
#include <cstdlib> // Include this header for rand() function
#include <ctime>   // Include this header for time() function
#include <math.h>

#define FREQ 16
#define MAX 4096;

struct array
{
    // A, B_Array = basic Array, C_Array = Sum Array, T_Array = Tmp Array
    int A_Array[FREQ-1], B_Array[FREQ-1], C_Array[FREQ-1], T_Array[FREQ];
    // Normalization Array
    int N_Array[FREQ];
};

void Sum(int* SUM_ARRAY, int* F_OPERAND_ARRAY, int* S_OPERAND_ARRAY) {
    for (int i = 0; i < FREQ - 1; ++i) {
        SUM_ARRAY[i] = S_OPERAND_ARRAY[i] + F_OPERAND_ARRAY[i];
    }
}

void Normalization(int* SUM_ARRAY, int* TMP_ARRAY, int* END_ARRAY) {
    array A;
    int tmp[FREQ - 1], Selection_Index;
    for (int i = 0; i < FREQ - 1; ++i) {
        if (A.C_Array[i] >= 10) {
            Selection_Index = A.C_Array[i] * 0.1;
            tmp[i] = std::floor(Selection_Index);
        }
    }
    for (int i = 0; i < FREQ - 1; ++i) {
        END_ARRAY[i] = SUM_ARRAY[i] + tmp[i];
    }
}

void Array_Print(int* Array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << Array[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Assignment_Array(int* ArrayName, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        ArrayName[i] = rand() % 10 + 48;
    }
}

int main() {
    array A;

    Assignment_Array(A.A_Array, FREQ - 1);
    Assignment_Array(A.B_Array, FREQ - 1);

    Array_Print(A.A_Array, FREQ - 1);
    std::cout << std::endl;
    Array_Print(A.B_Array, FREQ - 1);
    std::cout << std::endl;

    Sum(A.C_Array, A.A_Array, A.B_Array);
    Array_Print(A.C_Array, FREQ - 1);
    std::cout << std::endl;

    Normalization(A.C_Array, A.T_Array, A.N_Array);
    Array_Print(A.N_Array, FREQ - 1);
    std::cout << std::endl;

    return 0;
}
*/
