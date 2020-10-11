#define SIZE 32
typedef unsigned long long int BigInt [SIZE];
typedef unsigned long long int DoubleBigInt [SIZE*2];

int hex2int (char ch);
int BitLength (const BigInt A);
//void hex2bin (const BigInt A);
void ConvertStringToBigInt (char* num, int n, BigInt A);
void ConvertStringToDoubleBigInt (char* num, int n, DoubleBigInt A);
void ClearBigInt (BigInt A);
void ClearDoubleBigInt (DoubleBigInt A);
void DumpBigInt (const BigInt A);
void DumpDoubleBigInt (const DoubleBigInt A);
void CheckTest (int r, BigInt C, BigInt C2);
void ReadTestFile (const char* fn);
void CopyBigInt (BigInt B, const BigInt A);
void CopyDoubleBigInt (DoubleBigInt B, const DoubleBigInt A);
int LongAdd (const BigInt A, const BigInt B, BigInt C);
int LongAddDouble (const DoubleBigInt A, const DoubleBigInt B, DoubleBigInt C);
int LongSub (const BigInt A, const BigInt B, BigInt C);
int LongCmp (const BigInt A, const BigInt B);
int DoubleLongCmp (const DoubleBigInt A, const DoubleBigInt B);
int LongMulOneDigit (const BigInt A, unsigned d, DoubleBigInt C);
int LongShiftDigitsToHight (BigInt A, int n, BigInt C);
int LongDoubleShiftDigitsToHight (DoubleBigInt A, int n, DoubleBigInt C);
int LongMul (const BigInt A, const BigInt B, DoubleBigInt C);

//int LongCmp2 (const BigInt A, const BigInt B);
