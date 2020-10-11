#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "arith.h"

int hex2int (char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10; 
     return -1;
}

void hex2bin (const BigInt A) {
    const char array1 [16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    const char *array2 [16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    const char *hexstring = "8E6F43CAB43118F92ACCE9E445BA59AC6B50791EA9A69032096675DBD328454C";
    for (int i = 0; i < strlen(hexstring); i++) {
        char character = hexstring[i];
        int temp = hex2int (character);
        for (int j = 0; j < 16; j++ ) {
            if (array1[j] == hexstring[i]) {
                printf ("%s", array2[j]);
            }
        }
    }
}

void _Dump (const BigInt A, int n) {
    for (int i = n-1; i > -1; i--) {
        printf("%.16llX", A[i]);
    }
    printf("\n");
}

void DumpBigInt (const BigInt A) {
    return _Dump (A, SIZE);
}

void DumpDoubleBigInt (const DoubleBigInt A) {
    return _Dump (A, SIZE*2);
}

void _Clear (BigInt A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }
}

void ClearBigInt (BigInt A) {
    return _Clear (A, SIZE);
}

void ClearDoubleBigInt (DoubleBigInt A) {
    return _Clear (A, SIZE*2);
}

void CopyBigInt (BigInt B, const BigInt A) {
    memcpy (B, A, SIZE*8);
}

void CopyDoubleBigInt (DoubleBigInt B, const DoubleBigInt A) {
    memcpy (B, A, SIZE*2*8);
}

void CheckTest (int r, BigInt C, BigInt C2) {
    r = LongCmp (C, C2);
    if (r==0) 
        printf("Test  - OK\n");
    else 
        printf("Test - ERROR\n");
}

void _ConvertStringTo (char* num, int n, BigInt A) {
    for (int i=strlen(num)-1; i >= 0; i--) {
        char character = num[i]; 
        unsigned char temp = hex2int (character);
        n = strlen(num) - 1 - i;
        A[n/16] = A[n/16] | ((unsigned long long)temp << 4*( n % 16 ));
    }
}

void ConvertStringToBigInt (char* num, int n, BigInt A) {
    ClearBigInt(A);
    _ConvertStringTo (num, n, A);
}

void ConvertStringToDoubleBigInt (char* num, int n, DoubleBigInt A) {
    ClearDoubleBigInt(A);
    _ConvertStringTo (num, n, A);
}

int _LongAdd (const BigInt A, const BigInt B, BigInt C, int n) {
    int carry = 0;
    unsigned long long a, b, c;
    for (int i = 0; i < n; i++) {
        a = A[i] >> 63;
        b = B[i] >> 63;
        C[i] = A[i] + B[i] + carry;
        c = C[i] >> 63;
        if ((a && b) || ((a^b) && !c))
            carry = 1;
        else
            carry = 0;
    }
    return carry;
}

int LongAdd (const BigInt A, const BigInt B, BigInt C) {
    return _LongAdd(A, B, C, SIZE);
}

int LongAddDouble (const DoubleBigInt A, const DoubleBigInt B, DoubleBigInt C) {
    return _LongAdd(A, B, C, SIZE*2);
}

int LongSub (const BigInt A, const BigInt B, BigInt C) {
    int borrow = 0;
    unsigned long long a, b, c;
    for (int i = 0; i < SIZE; i++) {
        a = A[i] >> 63;
        b = B[i] >> 63;
        C[i] = A[i] - B[i] - borrow;
        c = C[i] >> 63;
        if ((a && b && c) || ((b||c) && !a))
            borrow = 1;
        else
            borrow = 0;
    }
    return borrow;
}

int _LongCmp (const BigInt A, const BigInt B, int n) {
    int i = n - 1;
    while ((i>=0) && (A[i] == B[i])) {
        i--;
    }
    if (i != -1) {
        if (A[i] > B[i])  
            return 1;
        else  
            return -1;
    } 
    return 0;
}

int LongCmp (const BigInt A, const BigInt B) {
    _LongCmp (A, B, SIZE);
}

int DoubleLongCmp (const DoubleBigInt A, const DoubleBigInt B) {
    _LongCmp (A, B, SIZE*2);
}

/*
int LongCmp2 (const BigInt A, const BigInt B) {
    int i;
    for (i = SIZE-1; i > -1; i--) {
        if (A[i] > B[i]) 
            return 1;
        else if (A[i] < B[i])  
            return -1;
    } 
    return 0; 
}
*/
void ReadTestFile (const char* fname) {
	FILE* fp = fopen(fname,"r");
    char test_string[512];
    unsigned d;
	if(fp == NULL) {
		printf("файл не найден '%s'\n",fname);
	}
    int i=0;
    int r;
    BigInt A, B, C, C2;
    while (fgets(test_string, sizeof(test_string), fp)) {
        test_string[strlen(test_string)-1]='\0';
        int x = i % 4;
        if (x==0) {
            ConvertStringToBigInt(test_string, 16, A);
        } else if (x==1) {
            ConvertStringToBigInt(test_string, 16, B);
        } else if (x==2) {
            ConvertStringToBigInt(test_string, 16, C);
        } else if (x==3) {
            if (strcmp ("test_add.arith", fname)==0) {
                puts ("Вызов функции Add");
                LongAdd(A, B, C2);
            } else if (strcmp ("test_sub.arith", fname)==0) {
                puts ("Вызов функции Sub");
                LongSub(A, B, C2);
            } else if (strcmp ("test_mul.arith", fname)==0) {
                puts ("Вызов функции Mul");
                LongMul(A, B, C2);
            } else {
                puts ("Имя файла не совпадает");
            }
            CheckTest (r, C, C2);
        }  
        i++;
    }
    fclose (fp);
}

int LongMulOneDigit (const BigInt A, unsigned d, DoubleBigInt C) {
    ClearDoubleBigInt(C);
    unsigned carry = 0;
    unsigned long long temp;
    const unsigned* a = (const unsigned*)A;
    unsigned* c = (unsigned*)C;
    for (int i = 0; i < 2*SIZE; i++) {       
        temp = (unsigned long long)a[i]*(unsigned long long)d + carry;
        c[i] = temp&0xFFFFFFFF;
        carry = temp>>32;
    }
    c[2*SIZE] = carry;
    return carry;
}

int LongShiftDigitsToHight (BigInt A, int n, BigInt C) {
    unsigned* a = (unsigned*)A;
    unsigned* c = (unsigned*)C;  
    int m;
    m = n/32;
    for (int i = 0; i < 2*SIZE-m; i++) {  
        c[i+m] = a[i];
    }
    for (int i = 0; i < m; i++) {  
        c[i] = 0;
    }
    return 0;
}

int LongDoubleShiftDigitsToHight (DoubleBigInt A, int n, DoubleBigInt C) {
    unsigned* a = (unsigned*)A;
    DoubleBigInt D; 
    unsigned* c = (unsigned*)D; 
    int m;
    m = n/32;
    for (int i = 0; i < 4*SIZE-m; i++) {  
        c[i+m] = a[i];
    }
    for (int i = 0; i < m; i++) {  
        c[i] = 0;
    }
    CopyDoubleBigInt (C, D);
    return 0;
}

int LongMul (const BigInt A, const BigInt B, DoubleBigInt C) {
    ClearDoubleBigInt (C);
    DoubleBigInt temp;
    const unsigned* b = (const unsigned*)B;
    for (int i = 0; i < 2*SIZE; i++) {       
        LongMulOneDigit (A, b[i], temp);
        LongDoubleShiftDigitsToHight (temp, i*32, temp);
        LongAddDouble (C, temp, C);      
    }
    return 0;
}

int BitLength (const BigInt A) {
    unsigned long long int Length;
    int i;
    /*for (i = SIZE-1; i >= 0; i--) {
        if (A[i] == 0)
            continue; 
        else { Length = A[i];
            printf("A[i] = %llX\n", A[i]);           
        }
    }*/
    return 0;
}



int LongDivMod (const BigInt A, const BigInt B, BigInt Q, BigInt R) {
    unsigned long long int k;
    k = BitLength (B);
    //R = A;

    return 0;
}







