#include "arith.h"
#include <stdio.h>
#include <string.h>

int main (void) {
    /*
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
    }*/
    char* num;
    BigInt A;
    int n;
    num = "6689D1EC16A29ED00B6E64B2A53602C31F54EF6FFEDEEEDD5D6";
    ConvertStringToBigInt(num, n, A);
    //DumpBigInt(A);
    BitLength (A);
    DumpBigInt(A);
    
}    
   /* const char A = "8E6F43CAB43118F92ACCE9E445BA59AC6B50791EA9A69032096675DBD328454C";

    hex2bin (*A);
    //printf ("%s", array2[j]);
    //DumpBigInt(A);
}*/

    //ReadTestFile ("test_add.arith");
    //ReadTestFile ("test_sub.arith");
    //ReadTestFile ("test_mul.arith");
    /*BigInt A, B;
    int r;
    DoubleBigInt C, K;
    //DoubleBigInt C;
    char* num;
    char* num2;
    char* num3;
    //int i, b, m;
    //m = 64;
    //unsigned d;
    //d = 1;
    num = "55270DFA657C6689D1EC16A29ED00B6E64B2A53602C31F54EF6FFEDEEEDD5D69";
    num2 = "15DE2898887F44BEDCA01E7347E622254C0F88FA2FC5D5EF6DDE7C0D83627B45";
    num3 = "00007461984803DB77CBCD6F7C1CB083F7C31EF574E60609B01F5B32C5978456878B0AF9E76F605881BE8E4C42C948056AB23495473A50A1D040EC220BA3ABDA04D";
    int n=16;
    ConvertStringToBigInt(num, n, A);
    DumpBigInt(A);
    ConvertStringToBigInt(num2, n, B);
    DumpBigInt(B);
    //ConvertStringToDoubleBigInt (num, n, A);
    //DumpDoubleBigInt(A);
    //ConvertStringToDoubleBigInt (num2, n, B);
    //DumpDoubleBigInt(B);
    ConvertStringToDoubleBigInt (num3, n, K);
    LongMul (A, B, C);
    DumpDoubleBigInt (C);
    //DoubleLongCmp (C, K);
    //CheckTestDouble (r, C, K);
    //Copy ();
    //CopyBigInt (B, A);
    //CopyDoubleBigInt (A, B);
    //DumpBigInt(A);
    //DumpBigInt(B);
    //DumpBigInt(B);*/
    //ReadTestFile ("test_add.arith");
    //ReadTestFile ("test_sub.arith");
    //ReadTestFile ("test_mul.arith");
    //LongShiftDigitsToHight(A, 32, C);
    //DumpBigInt(A);
    //DumpBigInt(C);


    //LongDoubleShiftDigitsToHight (A, 32, C);
    //ClearDoubleBigInt (A);
   // DumpDoubleBigInt(A);
    //ClearDoubleBigInt (A);
    //DumpDoubleBigInt(C);
    //LongMulOneDigit (A, d, C);
    //DumpBigInt(A);
    //DumpBigInt(C);
    
    //DumpBigInt(A);
    //DumpBigInt(B);
    //LongMul (A, B, C);

    //DumpBigInt (A);
    //DumpBigInt (B);
    //DumpDoubleBigInt (C);
    //ReadTestFile ("test_mul.arith");


    /*char* num;
    char* num2;
    int n;
    BigInt A, B, C;
    num = "50CF6A20998EEA455FCA21F671EC7A88A90FB5FBDC31007E4D9A8E6DBB3E69C1";
    num2 = "517E8C5E83080BF2EB0898C9F864FCD20AD1B9BB05E62BFE21F82C4E56919F6B";
    num2 = "3D9FD9AA1AA22EB3CB02C7EDD3CDDF23C240C322CD758FB3BBCBE76E17E9DB8B";
    n = 16;
    ConvertStringToBigInt(num, n, A);
    ConvertStringToBigInt(num2, n, B);
    LongAdd(A, B, C);
    DumpBigInt(A);
    DumpBigInt(B);
    DumpBigInt(C);
    LongSub (A, B, C);
    DumpBigInt(A);
    DumpBigInt(B);
    DumpBigInt(C);
    int r = LongCmp (A, B);
    int r2 = LongCmp2 (A, B);  
    printf("r = %d\n", r);*/
